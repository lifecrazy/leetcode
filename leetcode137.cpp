/*************************************************************************
	> File Name: leetcode137.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 15 Aug 2016 06:12:22 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int result = 0 ;
    for(int i = 0 ; i < sizeof(int)*8;i++)
    {
        int count = 0;
        int mask = 1 << i;
        for(int j = 0 ; j < nums.size(); j++)
        {
            if((nums[j] & mask )!=0)
            {
                count++;
            }
        }
        if(count % 3 != 0)
        {
            result |= mask;
        }
    }
    return result;
}
int main()
{
    vector<int> nums;
    int count = 10;
    for(int i = 0 ; i < count; i++)
    {
        nums.push_back(i * 100 - 2);
        nums.push_back(i * 100 - 2);
        nums.push_back(i * 100 - 2);
    }
    nums.push_back(88);
    cout << singleNumber(nums) << endl;
}
