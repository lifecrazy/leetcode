/*************************************************************************
	> File Name: leetcode088.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 01 Sep 2016 01:06:25 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0 ;
    int j = 0;
    vector<int> temp;
    while(i < m && j < n)
    {
        if(nums1[i]>nums2[j])
        {
            temp.push_back(nums2[j]);
            j++;
        }
        else
        {
            temp.push_back(nums1[i]);
            i++;
        }
    }
    if(i != m)
    {
        while(i < m)
        {
            temp.push_back(nums1[i]);
            i++;
        }
    }
    if(j != n)
    {
        while(j < n)
        {
            temp.push_back(nums2[j]);
            j++;
        }
    }
    temp.swap(nums1);
}
int main()
{
    vector<int> first;
    first.push_back(1);
    first.push_back(3);
    first.push_back(4);
    first.push_back(6);
    first.push_back(9);
    vector<int> second;
    second.push_back(2);
    second.push_back(4);
    second.push_back(8);
    second.push_back(11);
    second.push_back(12);
    second.push_back(18);
    second.push_back(22); 
    for(int i = 0 ; i < first.size();i++)
    {
        cout<< first[i]<<"\t";
    }
    cout<<endl;
    for(int i = 0 ; i < second.size();i++)
    {
        cout<< second[i]<<"\t";
    }
    cout<<endl;
    merge(first,first.size(),second,second.size());
    for(int i = 0 ; i < first.size();i++)
    {
        cout<< first[i]<<"\t";
    }
    cout<<endl;
}
