/*************************************************************************
	> File Name: leetcode219.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Jul 2016 11:24:42 PM PDT
 ************************************************************************/
//Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
//已知一个整形数组，是否存在两个相同的元素下标之间的距离不超过k
#include<iostream>
#include<vector>
#include<map>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int,int> result_map;
    int i = 0 ;
    while(i < nums.size())
    {
        if(result_map.find(nums[i]) != result_map.end()&&i - result_map[nums[i]] <= k)
        {
                return true;
        }
        else
        {
            result_map[nums[i]] = i;
        }
        i++;
    }
    return false;
}
int main()
{
    vector<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(1);
    data.push_back(4);
    data.push_back(5);
    data.push_back(6);
    cout << containsNearbyDuplicate(data,3) << endl;
}
