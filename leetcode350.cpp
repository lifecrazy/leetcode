/*************************************************************************
	> File Name: leetcode350.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Oct 2016 07:25:16 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    if(nums1.size() == 0 || nums2.size() == 0)
    {
        return result;
    }
    map<int,int> num_map;
    for (int i = 0;i < nums1.size(); i++)
    {
        num_map[nums1[i]]++;
    }
    for (int i = 0;i < nums2.size(); i++)
    {
        //如果map包含key，且key的值大于0则是共同元素
        if(num_map.count(nums2[i])&&num_map[nums2[i]] > 0)
        {
            result.push_back(nums2[i]);
            num_map[nums2[i]]--;
        }
    }
    return result;
}/*
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    if(nums1.size() == 0 || nums2.size() == 0)
    {
        return result;
    }
    map<int,int> num_map;
    for(int i = 0 ; i < nums1.size() ;i++)
    {
        if(num_map.count(nums1[i]) != 1)
        {
            num_map[nums1[i]] = 1;
        }
    }
    for(int i = 0; i < nums2.size(); i++)
    {
        if(num_map.count(nums2[i]) && num_map[nums2[i]] == 1)
        {
            result.push_back(nums2[i]);
            num_map[nums2[i]] = 0;
        }
    }
    return result;
}*/
int main()
{
    vector<int> first;
    first.push_back(1);
    first.push_back(2);
    first.push_back(2);
    first.push_back(1);
    vector<int> sec;
    sec.push_back(2);
    sec.push_back(2);
    vector<int> result = intersection(first,sec);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl;
}
