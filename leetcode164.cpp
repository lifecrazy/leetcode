/*************************************************************************
	> File Name: leetcode164.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 25 Oct 2016 10:36:30 PM PDT
 ************************************************************************/

//5,9,8,3,15
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maximumGap(vector<int>& nums) {
    int result = 0 ;
    if(nums.size() < 2)
    {
        return 0;
    }
    sort(nums.begin(),nums.end());
    for(int i = 0 ; i < nums.size();i++)
    {
        if(i + 1 < nums.size() && result < (nums[i + 1] -nums[i]))
        {
            result = nums[i + 1] - nums[i];
        }
    }
    return result;
}

int main()
{
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(9);
    nums.push_back(8);
    nums.push_back(3);
    nums.push_back(15);
    cout << maximumGap(nums) << endl;
}
