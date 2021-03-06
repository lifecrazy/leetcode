/*************************************************************************
	> File Name: leetcode452.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Nov 2016 11:14:08 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMinArrowShots(vector<pair<int, int> >& points) {
    sort(points.begin(),points.end(),[](pair<int,int>& x ,pair<int,int>& y)->int{
        return x.second < y.second || (x.second == y.second && x.first < y.first);
    });
    int result = 1;
    int end = points[0].second;
    cout <<points[0].first << "===" << points[0].second <<endl;
    for(int i = 1 ; i < points.size();i++)
    {
        cout << points[i].first << "===" << points[i].second << endl;
        if(points[i].first > end)
        {
            end = points[i].second;
            result++;
        }
    }
    return result;
}
int main()
{
    vector<pair<int,int> > nums;
    /*nums.push_back(make_pair(10,16));
    nums.push_back(make_pair(2,8));
    nums.push_back(make_pair(1,6));
    nums.push_back(make_pair(7,12));*/

    nums.push_back(make_pair(9,12));
    nums.push_back(make_pair(1,10));
    nums.push_back(make_pair(4,11));
    nums.push_back(make_pair(8,12));
    nums.push_back(make_pair(3,9));
    nums.push_back(make_pair(6,9));
    nums.push_back(make_pair(6,7));
    cout << findMinArrowShots(nums) << endl;
}
