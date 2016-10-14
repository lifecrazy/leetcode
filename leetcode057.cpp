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
    vector<Interval> ret;
    if(intervals.empty())
    {
        ret.push_back(newInterval);
        return ret;        
    }
    int i = 0;
    while(i < intervals.size())
    {
        if(newInterval.end < intervals[i].start)
        {
            ret.push_back(newInterval);
            while(i < intervals.size())
            {
                ret.push_back(intervals[i]);
                i++;
            }
            return ret;
        }
        else if(newInterval.start > intervals[i].end)
        {
            ret.push_back(intervals[i]);
        }
        else
        {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
        i++;
    }
    ret.push_back(newInterval);      
    return ret;
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
