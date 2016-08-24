/*************************************************************************
> File Name: leetcode081.cpp
> Author: 
> Mail: 
> Created Time: Wed 24 Aug 2016 12:17:31 AM PDT
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
bool search(vector<int>& nums, int target) 
{
    int left = 0 ;
    int right = nums.size() - 1;
    int mid = -1;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(nums[mid] == target)
        {
            return true;

        }
        if(nums[mid] > nums[left])
        {
            if(nums[left] <= target && target < nums[mid])
            {
                right = mid;

            }
            else
            {
                left = mid + 1;

            }

        }
        else if(nums[mid] < nums[left])
        {
            if(nums[mid] < target && target <= nums[right])
            {
                left = mid + 1;

            }
            else
            {
                right = mid;

            }

        }
        else
        {
            left++;

        }

    }
    return false;

}
int main()
{
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    cout << search(nums,3) << endl;
    cout << search(nums,4) << endl;
}
