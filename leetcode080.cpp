/*************************************************************************
	> File Name: leetcode080.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Jul 2016 10:21:29 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//两个指针等速度前进，两个指针之间起始的差值表示该数组允许元素重复的最大次数
int removeDuplicates(vector<int>& nums) {
    if(nums.size() <= 2)
    {
        return nums.size();
    }
    int i = 2 ;
    int cur = 2;
    while(i < nums.size())
    {
        if(nums[i] != nums[cur - 2])
        {
            nums[cur] = nums[i];
            cur++;
        }
        i++;
    }
    return cur;
}

int main()
{
    vector<int> data;
    data.push_back(0);
    data.push_back(1);
    data.push_back(2);
    data.push_back(2);
    data.push_back(3);
    data.push_back(4);
    cout << removeDuplicates(data)<<endl;
}
