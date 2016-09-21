/*************************************************************************
	> File Name: leetcode004.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Sep 2016 07:25:20 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int findkth(vector<int>& nums1,vector<int> nums2,int k)
{
    int j = 0;
    int m = 0;
    for(int i = 0 ;i < k - 1 ; i++)
    {
        if(j >= nums1.size() && m < nums2.size())
        {
            m++;
        }
        else if(j < nums1.size() && m >= nums2.size())
        {
            j++;
        }
        else if(nums1[j] > nums2[m])
        {
            m++;
        }
        else
        {
            j++;
        }
    }
    if(j >= nums1.size())
    {
        return nums2[m];
    }
    else if(m >= nums2.size())
    {
        return nums1[j];
    }
    else
    {
        return nums1[j] > nums2[m] ? nums2[m]:nums1[j];
    }
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size() + nums2.size();
    if(len % 2 == 0)
    {
        return (findkth(nums1,nums2,len/2) + findkth(nums1,nums2,len/2+1))/2.0;
    }
    else
    {
        return findkth(nums1,nums2,len/2+1);
    }
}
int main()
{
    vector<int> data1;
    data1.push_back(1);
    data1.push_back(2);
    vector<int> data2;
    data2.push_back(3);
    vector<int> data3;
    data3.push_back(3);
    data3.push_back(4);
    cout << findMedianSortedArrays(data1,data2) << endl;
    cout << findMedianSortedArrays(data1,data3) << endl;
}
