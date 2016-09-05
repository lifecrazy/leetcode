/*************************************************************************
	> File Name: leetcode041.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 04 Sep 2016 11:38:05 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int i = 0;
    while(i < nums.size())
    {
        if(nums[i] > 0 && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i] && nums[i] - 1 < nums.size())
        {
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
        else
        {
            i++;
        }
    }
    for(int i = 0 ; i < nums.size();i++)
    {
        if(nums[i] != i + 1)
        {
            return i + 1;
        }
    }
    return nums.size() + 1;
}
int main()
{
    vector<int> data1;
    data1.push_back(1);
    data1.push_back(2);
    data1.push_back(0);
    vector<int> data2;
    data2.push_back(3);
    data2.push_back(4);
    data2.push_back(-1);
    data2.push_back(1);
    cout << firstMissingPositive(data1) << endl;
    cout << firstMissingPositive(data2) << endl;
}
