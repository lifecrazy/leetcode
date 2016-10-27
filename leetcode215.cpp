/*************************************************************************
	> File Name: leetcode215.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Oct 2016 06:20:01 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int QuickSort(vector<int>& nums,int left,int right)
{
    int p = nums[left];
    if(left < right)
    {
        while(nums[right] >= p && left < right)
        {
            right--;
        }
        nums[left] = nums[right];
        while(nums[left] <= p && left < right)
        {
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = p;
    return left;
}
int QuickSort_KMax(vector<int>& nums,int left,int right,int k)
{
    if(left >= right)
    {
        return nums[left];
    }
    else
    {
        int mid = QuickSort(nums,left,right);
        if(mid > k)
        {
            QuickSort_KMax(nums, left,mid - 1, k);
        }
        else if(mid < k)
        {
            QuickSort_KMax(nums,mid + 1 ,right, k);
        }
        else
        {
            return nums[mid];
        }
    }
}
int findKthLargest(vector<int>& nums, int k) 
{
    return QuickSort_KMax(nums,0,nums.size() - 1 ,nums.size() - k);
}
int main()
{
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(6);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(9);
    cout << findKthLargest(nums,2) << endl;
}
