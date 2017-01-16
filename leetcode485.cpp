/*************************************************************************
	> File Name: leetcode485.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Jan 2017 11:27:55 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int max = 0 ;
    int count = 0;
    for(int i = 0 ; i < nums.size();i++)
    {
        if(nums[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if(count > max)
        {
            max = count;
        }
    }
    return max ;
}
int main()
{
    vector<int> nums;
    // [1,1,0,1,1,1]
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    cout << findMaxConsecutiveOnes(nums) << endl;
}
