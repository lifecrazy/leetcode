/*************************************************************************
> File Name: leetcode011.cpp
> Author: 
> Mail: 
> Created Time: Fri 23 Sep 2016 01:36:17 AM PDT
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int maxArea(vector<int>& height) {
    int capability = 0;
    int left = 0;
    int right = height.size() - 1;
    int water = 0 ;
    while (left < right)
    {
        water = (height[left] > height[right] ? height[right] : height[left]) * (right - left);
        if (water > capability)
        {
            capability = water;
        }
        if (height[left] < height[right])
        {
            ++left;
        }
        else
        {
            --right;
        }
    }
    return capability;
}
int main()
{
    //4,6,2,6,7,11,2
    vector<int> data;
    data.push_back(4);
    data.push_back(6);
    data.push_back(2);
    data.push_back(6);
    data.push_back(7);
    data.push_back(11);
    data.push_back(2);
    cout << maxArea(data) << endl;
}
