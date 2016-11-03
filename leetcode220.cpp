/*************************************************************************
	> File Name: leetcode220.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Nov 2016 07:35:27 PM PDT
 ************************************************************************/
//Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
//

#include<iostream>
#include<vector>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(nums.size() <= 1)
    {
        return false;
    }
    for(int i = 0 ; i < nums.size();i++)
    {
        for(int j = i + 1; j < nums.size(); j++)
        {
            int temp = nums[i] > nums[j] ? nums[i] - nums[j] :nums[j] - nums[i];
            if(temp <= t && j - i <= k)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<int> nums;
    for(int i = 0; i < 10; i++)
    {
        nums.push_back(i);
    }
    cout << containsNearbyAlmostDuplicate(nums,2,2) << endl;
}
