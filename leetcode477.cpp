/*************************************************************************
	> File Name: leetcode477.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Dec 2016 05:04:43 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int hammingDistance(int x, int y) {
    int tmp = x^y;
    int result = 0 ;
    for (int i = 0; i < 32;i++)
    {
        int x = tmp >> i & 0x1;
        if(1 == x)
        {
            result++;
        }
    }
    return result;
}
//方法一超时
int totalHammingDistance_1(vector<int>& nums) {
    int result = 0 ;
    for(int i = 0 ; i < nums.size(); i++)
    {
        for(int j = i + 1; j < nums.size();j++)
        {
            result += hammingDistance(nums[i],nums[j]);
        }
    }
    return result;
}
//方法二:
int totalHammingDistance(vector<int>& nums) {
    int result = 0;
    for(int k = 0 ; k < 32;k++)
    {
        int x = 0;
        int y = 0;
        for(int i = 0 ; i < nums.size();i++)
        {
            int tmp = nums[i] >> k & 0x1;
            if(tmp == 0)
            {
                x++;
            }
            else
            {
                y++;
            }
        }
        result += x * y;
    }
    return result;
}
int main()
{
    vector<int> data;
    data.push_back(4);
    data.push_back(14);
    data.push_back(2);
    cout <<totalHammingDistance(data) <<endl;
}
