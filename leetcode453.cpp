/*************************************************************************
	> File Name: leetcode453.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Nov 2016 05:13:07 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
//思路：最少的增加次数  即为数组中的每个值和最大值之间的差值之和
//反向思路：最少的增加次数   即为数组中每个值和最小值之间的差值之和
//注意： 正向思路最大值乘以数组的个数的时候如果超过整形所能表示的最大范围

int minMoves(vector<int>& nums) {
/*    int max = INT_MIN;
    int sum = 0 ;
    for (int i = 0 ;i <nums.size(); i++)
    {
        if(nums[i] > max)
        {
            max = nums[i];
        }
        sum += nums[i];
    }
    return max * nums.size() - sum;*/
    int min = INT_MAX;
    int sum = 0 ;
    for(int i = 0 ; i < nums.size();i++)
    {
        if(nums[i] < min)
        {
            min = nums[i];
        }
        sum += nums[i];
    }
    return sum - min * nums.size();
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    cout << minMoves(nums) << endl;
}
