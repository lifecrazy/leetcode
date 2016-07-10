/*************************************************************************
	> File Name: leetcode026.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 09 Jul 2016 06:44:52 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

//思路：定义两个指针分别指向第一个和第二个元素，如果两个元素相同则第二指针向后移动，
//继续 比较如果不同则讲第二指针指向的元素一道第一个元素的后边然后修改第一个指针为第
//二指针的位置，依次比较，如果两个元素不相同则两个指针同时向后移动
int removeDuplicates(vector<int>& nums) {
    if(nums.size() <= 1)
    {
        return nums.size();
    }
    int i = 0 ;
    int j = 1;
    while(j < nums.size())
    {
        if(nums[i] != nums[j])
        {
            i++;
            j++;
        }
        else
        {
            while(j < nums.size())
            {
                j++;
                if(nums[i] != nums[j])
                {
                    nums[++i] = nums[j];
                    i--;
                    break;
                }
            }
        }
    }
    return i+1;
}

int main()
{
    vector<int> data;
    data.push_back(1);
    data.push_back(1);
    data.push_back(1);
    data.push_back(1);
    data.push_back(2);
    data.push_back(2);
    data.push_back(2);
    data.push_back(2);
    data.push_back(2);
    data.push_back(2);
    data.push_back(3);
    cout << removeDuplicates(data) << endl;
}
