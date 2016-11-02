/*************************************************************************
	> File Name: leetcode436.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 01 Nov 2016 10:54:48 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<int> findRightInterval(vector<Interval>& intervals) {
    vector<int> res(intervals.size(),-1);
    if(intervals.size() <= 1)
    {
        return res;
    }
    vector<pair<Interval,int> > tmp;
    for(int i = 0 ; i < intervals.size();i++)
    {
        tmp.push_back(pair<Interval,int>(intervals[i],i));
    }
    sort(tmp.begin(),tmp.end(),[](pair<Interval,int>& x,pair<Interval,int>& y)->int{
        return x.first.start < y.first.start || (x.first.start == y.first.start && x.first.end < y.first.end);
    });
    for(int i = 0; i < intervals.size(); i++)
    {
        for(int j = i + 1; j < intervals.size(); j++)
        {
            if(tmp[j].first.start >= tmp[i].first.end)
            {
                res[tmp[i].second] = tmp[j].second;
                break;
            }
        }
    }
    return res;
}
//方法超时。。。。
vector<int> findRightInterval_2(vector<Interval>& intervals) {
    vector<int> res;
    if(intervals.size() <= 1)
    {
        res.push_back(-1);
        return res;
    }
    for(int i = 0; i <intervals.size();i++)
    {
        int index = -1;
        int start = intervals[i].end;
        for(int j = 0; j < intervals.size(); j++)
        {
            //找到右边的区间
            if(i != j && intervals[j].start >= intervals[i].end &&start >= intervals[j].start)
            {
                start = intervals[j].start;
                index = j;
            }
        }
        res.push_back(index);
    }
    return res;
}
int main()
{
    vector<Interval> data;
     data.push_back(Interval(3,4));
    data.push_back(Interval(2,3));
    data.push_back(Interval(1,2));
/*   data.push_back(Interval(1,4));
    data.push_back(Interval(2,3));
    data.push_back(Interval(3,4));*/
    vector<int> result = findRightInterval(data);
    for(int i = 0; i <result.size(); i++)
    {
        cout << result.at(i) << '\t';
    }
    cout << endl;
}
