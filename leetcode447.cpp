/*************************************************************************
	> File Name: leetcode447.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Nov 2016 06:01:59 PM PST
 ************************************************************************/

//Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
//
//Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
//
//Example:
//Input:
//[[0,0],[1,0],[2,0]]
//Output:
//2
//
//Explanation:
//The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
//题目不难，在于弄懂题意
//思路：对每个点计算其他点到这个点的距离，统计距离相等的点的个数,
//个数超过2时，进行计算排列数
#include<iostream>
#include<vector>
#include<tr1/unordered_map>
using namespace std;

int distance(pair<int,int>& x,pair<int,int>& y)
{
    return (x.first - y.first) * (x.first - y.first) +(x.second - y.second) * (x.second - y.second);
}
int numberOfBoomerangs(vector<pair<int, int> >& points) {
    int result = 0;
    for(int i = 0 ; i < points.size(); i++)
    {
        //统计距离相等的点的个数
        std::tr1::unordered_map<int,int> dis;
        for(int j = 0; j < points.size();j++)
        {
            if(i != j)
            {
                dis[distance(points[i],points[j])]++;
            }
        }
        for(auto it = dis.begin(); it != dis.end();it++)
        {
            if(it->second >=2)
            {
                result += (it->second - 1) * it->second;
            }
        }
    }
    return result;
}
int main()
{
    vector<pair<int,int> > nums;
    nums.push_back(make_pair(0,0));
    nums.push_back(make_pair(1,0));
    nums.push_back(make_pair(2,0));
    cout << numberOfBoomerangs(nums) << endl;
}

