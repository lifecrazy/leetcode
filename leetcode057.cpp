/*************************************************************************
	> File Name: leetcode056.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Oct 2016 06:44:26 PM PDT
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
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    //如果添加的区间的end比第一个区间的start的值小直接将其添加到第一个位置即为结果
    if(newInterval.end < intervals[0].start)
    {
        intervals.insert(intervals.begin(),newInterval);
        return intervals;
    }
    //如果添加的区间的start比最后一个区间的end的值大直接将其添加到最后一个位置即为结果
    if(newInterval.start > intervals[intervals.size() - 1].end)
    {
        intervals.push_back(newInterval);
        return intervals;
    }
    for(int i = 0 ; i < intervals.size();i++)
    {
        //如果新添加的区间是任意一个区间的子区间则直接返回
        if(newInterval.start >= intervals[i].start && newInterval.end <= intervals[i].end)
        {
            return intervals;
        }
        //如果添加的区间在任意两个区间的中间则直接添加到这两个区间之间即可
        if(i + 1 <intervals.size() && newInterval.start > intervals[i].end && newInterval.end < intervals[i+1].start)
        {
            intervals.insert(intervals.begin() + i,newInterval);
            return intervals;
        }
        //新的区间横跨至少两个区间
        int start;
        if(newInterval.start < intervals[i].end)
        {
            start = newInterval.start < intervals[i].start ? newInterval.start:intervals[i].start;
            intervals.erase(intervals.begin() + i);
            for(int j = i  ; j < intervals.size();j++)
            {
                if(newInterval.end < intervals[i].start)
                {
                    intervals.insert(intervals.begin()+i,Interval(start,newInterval.end));
                    return intervals;
                }
                else if(newInterval.end <= intervals[i].end)
                {
                    int end = intervals[i].end;
                    intervals.erase(intervals.begin()+1);
                    intervals.insert(intervals.begin()+1,Interval(start,end));
                    return intervals;
                }
                else
                {
                    intervals.erase(intervals.begin() + i);
                }
            }
        }
    }
    return intervals;
}
int main()
{
/*    Interval first(1,2);
    Interval sec(3,5);
    Interval third(6,7);
    Interval forth(8,10);
    vector<Interval> data;
    data.push_back(first);
    data.push_back(sec);
    data.push_back(third);
    data.push_back(forth);
    data.push_back(Interval(12,16));*/
    vector<Interval> data;
    data.push_back(Interval(1,3));
    data.push_back(Interval(6,9));
    vector<Interval> result = insert(data,Interval(2,5));
    for(int i = 0 ; i < result.size(); i++)
    {
        cout << result[i].start << " , " << result[i].end << endl;
    }
}
