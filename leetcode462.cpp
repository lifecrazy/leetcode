/*************************************************************************
	> File Name: leetcode462.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Nov 2016 11:59:33 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minMoves2(vector<int>& nums) {
    if(nums.size() <= 0)
    {
        return 0;
    }
    sort(nums.begin(),nums.end(),[](int& x,int& y)->int { 
        return x < y;
    });
    int mid = -1;
    int len = nums.size();
    if(len % 2 == 0)
    {
        mid = (nums[len / 2] + nums[len / 2 - 1]) / 2;
    }
    else
    {
        mid = nums[len / 2];
    }
    int result = 0 ;
    for(int i = 0 ; i < nums.size();i++)
    {
        if(nums[i] > mid)
        {
            result += (nums[i] - mid);
        }
        else
        {
            result += (mid - nums[i]);
        }
    }
    return result;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    cout << minMoves2(nums) << endl;
}
