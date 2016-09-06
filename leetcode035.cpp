/*************************************************************************
	> File Name: leetcode035.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 05 Sep 2016 08:36:36 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int result = -1;
    int i = 0 ; 
    for(; i <nums.size();i++)
    {
        if(nums[i] >= target)
        {
            result = i;
            break;
        }
    }
    if(i == nums.size())
    {
        result = nums.size();
    }
    return result;
}
int main()
{
    vector<int> data;
    data.push_back(1);
    data.push_back(3);
    data.push_back(5);
    data.push_back(6);
    cout << searchInsert(data,5) <<endl;
    cout << searchInsert(data,2) <<endl;
    cout << searchInsert(data,7) <<endl;
    cout << searchInsert(data,0) <<endl;
}
