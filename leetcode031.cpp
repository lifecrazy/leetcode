/*************************************************************************
	> File Name: leetcode031.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 27 Jul 2016 01:53:06 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
void nextPermutation(vector<int>& nums) {
    //找到第一个逆序数
    int partitionNumber = 0;
    for(int i = nums.size() - 1 ; i > 0;i--)
    {
        if(nums[i] > nums[i - 1])
        {
            partitionNumber = i - 1;
            break;
        }
    }
    //找到要交换的数字
    int changeNum = 0;
    for(int i = nums.size() - 1 ;i > 0 ;i--)
    {
        if(nums[i] > nums[partitionNumber])
        {
            changeNum = i;
            break;
        }
    }
    //交换这两个数字
    int temp = nums[partitionNumber];
    nums[partitionNumber] = nums[changeNum];
    nums[changeNum] = temp;
    //逆序partitionNumber右边的数字
    for(int i = partitionNumber + 1 ; i < partitionNumber + (nums.size()-1 - partitionNumber + 1)/2; i++)
    {
        temp = nums[nums.size()-1-(i-partitionNumber - 1)];
        nums[nums.size()-1-(i-partitionNumber - 1)] = nums[i];
        nums[i] = temp;
    }
}
int main()
{
    vector<int> data;
    data.push_back(6);
    data.push_back(8);
    data.push_back(7);
    data.push_back(4);
    data.push_back(3);
    data.push_back(2);
    for(int i = 0; i < data.size();i++)
    {
        cout << data[i] << "\t";
    }
    cout << endl;
    nextPermutation(data);
    for(int i = 0; i < data.size();i++)
    {
        cout << data[i] << "\t";
    }
    cout << endl;
}
