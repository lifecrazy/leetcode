/*************************************************************************
	> File Name: leetcode414.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Oct 2016 08:09:37 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
//方法一利用set自动排序的功能 当set大小超过3的时候直接删除第一个元素即可
//始终保持第一个元素为第三大元素
int thirdMax(vector<int>& nums)
{
    set<int> s;
    for(int i = 0; i < nums.size();i++)
    {
        s.insert(nums[i]);
        if(s.size() > 3)
        {
            s.erase(s.begin());
        }
    }

   /* set<int>::iterator it;
    for(it = s.begin();it != s.end();it++)
    {
        cout << *it <<"\t";
    }
    cout << endl;*/
    return s.size() == 3 ? *s.begin():*s.rbegin();
}
int thirdMax_2(vector<int>& nums)
{
     if(nums.size() == 1)
    {
        return nums[0];   
    }
    else if(nums.size() == 2)
    {
        return nums[0] > nums[1]?nums[0]:nums[1];   
    }
    else
    {
        int first = INT_MIN;
        int sec = INT_MIN;
        int third = INT_MIN;
       i// int count = 0;
        int bottom =0;
        for(int i = 0 ; i < nums.size();i++)
        {
            //说明有个不需要更新
            if(nums[i] == INT_MIN)
            {
                bottom = 1;
            }
            //跳过重复的数字
            if(nums[i] == first || nums[i] == sec || nums[i] == third)
            {
                continue;
            }
            if(nums[i] > first)
            {
                third = sec;
                sec = first;
                first = nums[i];
            }
            else if(nums[i] > sec)
            {
                third = sec;
                sec = nums[i];
            }
            else if(nums[i] >third)
            {
                third = nums[i];
            }
        }
        return bottom ? sec:third;
    } 
}
//超时
int thirdMax_3(vector<int>& nums) {
    if(nums.size() == 1)
    {
        return nums[0];   
    }
    else if(nums.size() == 2)
    {
        return nums[0] > nums[1]?nums[0]:nums[1];   
    }
    else
    {
        sort(nums.begin(),nums.end(),[](int &x,int &y)->int {return x > y;});
        int i = 1;
        int cur = 0;
        int result ;
        while(i < nums.size())
        {
            if(nums[i] != nums[cur])
            {
                cur++;
                if(cur + 1 == 3)
                {
                    result = i;
                    break;
                }
                i++;
            }
        }
        return nums[result];
    }
}
int main()
{
    vector<int> data;
    data.push_back(2);
    data.push_back(2);
    data.push_back(3);
    data.push_back(1)
    cout << thirdMax(data) << endl;
    cout << thirdMax_2(data) << endl;
}
