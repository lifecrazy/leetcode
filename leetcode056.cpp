/*************************************************************************
	> File Name: leetcode056.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 11 Oct 2016 06:44:26 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> result;
    int k = 1;
    for(int i = 0 ; i < intervals.size();i += k)
    {
        int end = intervals[i].end;
        k = 1;
        for(int j = i + 1; j < intervals.size();j++)
        {
            if(end >= intervals[j].start)
            {
                end = intervals[j].end;
                k++;
            }
        }
        result.push_back(Interval(intervals[i].start,end));
    }
    return result;
}
int main()
{
/*    Interval first(1,3);
    Interval sec(2,6);
    Interval third(8,10);
    Interval forth(15,18);
    vector<Interval> data;
    data.push_back(first);
    data.push_back(sec);
    data.push_back(third);
    data.push_back(forth);*/
    vector<Interval> data;
//    data.push_back(Interval(1,4));
  //  data.push_back(Interval(1,4));
    vector<Interval> result = merge(data);
    for(int i = 0 ; i < result.size(); i++)
    {
        cout << result[i].start << " , " << result[i].end << endl;
    }
}
