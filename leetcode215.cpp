/*************************************************************************
	> File Name: leetcode215.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Oct 2016 06:20:01 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
/* this two funciton has bug
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
}*/
int findKthLargest(vector<int>& nums, int k) 
{
    int left = 0;
    int right = nums.size() - 1;
    while(left < right)
    {
        int key = nums[left];
        int l = left;
        int r = right;
        while(l < r)
        {
            while(l < r && nums[r] < key)
            {
                --r;
            }
            nums[l] = nums[r];
            while(l < r && nums[l] >= key) 
            {
                ++l;
            }
            nums[r] = nums[l];
        }
        nums[l] = key;
        if(l == k -1)
        {
            return nums[k - 1];
        }
        else if(l > k - 1)
        {
            right = l -1;
        }
        else
        {
            left = l + 1;
        }
    }
    return nums[k -1];
}
int main()
{
    //[3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6]
    //2
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
