/*************************************************************************
	> File Name: leetcode456.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 13 Nov 2016 09:40:31 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


//
bool find132pattern_2(vector<int>& nums) {
    if(nums.size() < 3)
    {
        return false;
    }
    int j = 0;
    int k = 0;
    for(int i = 0 ; i < nums.size();i +=(j+1))
    {
        while(i+1 < nums.size() && nums[i] >= nums[i + 1])
        {
            i++;
        }
        j = i+1;
        while(j+1 < nums.size() && nums[j] <= nums[j + 1])
        {
            j++;
        }
        k = j+1;
        for(;k < nums.size() ;k++)
        {
            if(nums[k] > nums[i] && nums[k] < nums[j])
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
    /*nums.push_back(-1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(0);*/
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(-4);
    nums.push_back(-3);
    cout << find132pattern(nums) << endl;
}
