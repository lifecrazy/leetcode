/*************************************************************************
	> File Name: leetcode033.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Jul 2016 12:06:56 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//思路：二分法，如果中间的值比目标值大，而左侧的值都比中间的值小如果最左侧的那个值比目标值大说明目标值在中间值的左侧，如果最左侧的那个值比目标值小说明目标值在左侧

int search(vector<int>& nums, int target) {
    int low = 0 ;
    int high = nums.size();
    int mid ;
    while(low < high)
    {
        mid = (low + high) / 2 ;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] >= nums[low])
        {
            if(nums[mid] > target && target >= nums[low])
            {
                high = mid;
            }
            else
            {
                low = mid + 1 ;
            }
        }
        else
        {
            if(nums[mid] < target && target < nums[high - 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> data;
    data.push_back(4);
    data.push_back(5);
    data.push_back(6);
    data.push_back(7);
    data.push_back(0);
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    cout <<search(data,1)<< endl;
    cout <<search(data,5)<<endl;
}
