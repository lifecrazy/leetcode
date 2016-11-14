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

bool find132pattern(vector<int>& nums) {
    if(nums.size() < 3)
    {
        return false;
    }
    for(int i = 0 ; i < nums.size();i++)
    {
        for(int j = i + 1;j <nums.size();j++)
        {
            if(nums[i] >= nums[j])
            {
                continue;
            }
            for(int k = j + 1; k <nums.size();k++)
            {
                if(nums[j] > nums[k])
                {
                    return true;
                }
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
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    cout << find132pattern(nums) << endl;
}
