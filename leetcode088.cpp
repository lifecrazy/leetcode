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
    while(i < nums1.size() && j < n)
    {
        if(nums1[i] > nums2[j])
        {
            nums1.insert(nums1.begin() + i,nums2[j]);
            j++;
        }
        else
        {
            i++;
        }
    }
    if(j != n)
    {
        while(j < n)
        {
            nums1.push_back(nums2[j]);
            j++;
        }
    }
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
