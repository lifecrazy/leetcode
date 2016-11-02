/*************************************************************************
	> File Name: leetcode435.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 01 Nov 2016 08:27:35 PM PDT
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
//思路：
//按照end升序排序每个区间，如果end相等start按照升序排序
//然后比较前一个区间的end和后一个区间的start,如果start小于end跳过说明有交集
//如果大于等于则统计并更新当前的end值
int eraseOverlapIntervals(vector<Interval>& intervals) {
    if(intervals.size() <= 1)
    {
        return 0;
    }
    sort(intervals.begin(),intervals.end(),[](Interval& x,Interval& y)->int{
        return x.end < y.end ||( x.end ==y.end && x.start < y.start); 
    });/*
    for(int i = 0 ;i <intervals.size();i++)
    {
        cout <<intervals.at(i).start << '\t' <<intervals.at(i).end << endl;
    }*/
    int end = intervals[0].end;
    int count = 1;
    for(int i = 1; i < intervals.size();i++)
    {
        if(intervals[i].start >= end)
        {
            count++;
            end = intervals[i].end;
        }
    }
    return intervals.size() - count;
}
int main()
{
    vector<Interval> data;
  /*  data.push_back(Interval(1,2));
    data.push_back(Interval(2,3));
    data.push_back(Interval(3,4));
    data.push_back(Interval(1,3));*/
    data.push_back(Interval(1,2));
    data.push_back(Interval(1,2));
    data.push_back(Interval(1,2));
    cout << eraseOverlapIntervals(data) << endl;
}
