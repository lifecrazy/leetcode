/*************************************************************************
	> File Name: leetcode136.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Aug 2016 06:01:25 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = nums[0];
    for(int i = 1; i < nums.size();i++)
    {
        result ^= nums[i];
    }
    return result;
}
int main()
{
    vector<int> nums;
    int count = 10;
    for(int i = 0 ; i < count ; i++)
    {
        nums.push_back( i * 5 - 1);
        nums.push_back( i * 5 - 1);
    }
    nums.push_back(66);
    cout << singleNumber(nums) << endl;
}
