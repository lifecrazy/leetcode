/*************************************************************************
> File Name: leetcode027.cpp
> Author: 
> Mail: 
> Created Time: Mon 25 Jul 2016 10:39:19 PM PDT
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//思路：利用vector 的特性删除vector中的等于val的元素
int removeElement(vector<int>& nums, int val) {
    vector<int>::iterator iter;
    for(iter = nums.begin();iter != nums.end();)
    {
        if(*iter == val)
        {
            iter = nums.erase(iter);
        }
        else
        {
            iter++;
        }
    }
    return nums.size();
}
//思路：方法二，两头比较，借鉴快速排序的思路
//当相等的时候将后边的元素拷贝到当前位置再比较一次
//当不相等的时候继续比较下一个元素，直到两者相遇为止
int removeElement_2(vector<int>& nums, int val) {
    int i = 0 ;
    int len = nums.size() - 1;
    while(i <= len)
    {
        if(nums[i] == val)
        {
            nums[i] = nums[len];
            len--;
        }
        else
        {
            i++;
        }
    }
    return len + 1;
}
//
int removeElement_3(vector<int>& nums, int val) {
    int i = 0 ;
    int index = 0;
    while(index < nums.size())
    {
        if(nums[index] == val)
        {
            index++;
        }
        else
        {
            nums[i] = nums[index];
            i++;
            index++;
        }
    }
    return i;
}
int main()
{
    vector<int> data;
    data.push_back(3);
    data.push_back(2);
    data.push_back(2);
    data.push_back(3);
    cout << removeElement(data,3)<<endl;
    cout << removeElement_2(data,3)<<endl;
    cout << removeElement_3(data,3)<<endl;
}
