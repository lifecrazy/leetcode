/*************************************************************************
	> File Name: leetcode480.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Jan 2017 10:08:10 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

//方法一采用快排的方法  超时了
int partition(vector<int>& nums, int left,int right)
{
    int temp = nums[left];
    int i = left;
    int j = right;
    while(i != j)
    {
        while(i < j && nums[j] > temp)
        {
            j--;
        }
        if(i < j)
        {
            nums[i++] = nums[j];
        }
        while(i < j && nums[i] < temp)
        {
            i++;
        }
        if(i < j)
        {
            nums[j--] = nums[i];
        }
    }
    nums[i] = temp;
    return i;
}
void quickSort(vector<int>& nums ,int left ,int right)
{
    if(left <= right)
    {
        int index = partition(nums,left,right);
        quickSort(nums,left,index - 1);
        quickSort(nums,index + 1, right);
    }
}
vector<double> medianSlidingWindow_2(vector<int>& nums, int k) {
    vector<int> arr_tmp(k,0);
    vector<double> result;
    for(int i = 0; i <= nums.size() - k; i++)
    {
        for(int j = 0 ;j < k;j++)
        {
            arr_tmp[j] = nums[i + j];
        }
        quickSort(arr_tmp, 0, k -1);
        if(k % 2 ==1)
        {
            result.push_back((double)arr_tmp[k/2]);
        }
        else
        {
            result.push_back(((double)arr_tmp[k/2] + arr_tmp[k/2 -1]) / 2);
        }
    }
    return result;
}
//方法二
int findK(vector<int>& nums,int left,int right,int k)
{
/*    if(left >= right)
    {
        return nums[left];
    }
    else
    {
        int index = partition(nums,left,right);
        if(index > k)
        {
            findK(nums,left,index - 1,k);
        }
        else if(index < k)
        {
            findK(nums,index + 1,right,k);
        }
        else
        {
            return nums[index];
        }
    }*/
    if(nums.size() <= 0)
    {
        return -1;
    }
    int index = -1 ;
    while(index != k)
    {
        index = partition(nums, left, right);
        if(index < k)
        {
            left = index + 1;
        }
        else if(index > k)
        {
            right = index - 1;
        }
        else
        {
            break;
        }
    }
    assert(index == k);
    return nums[index];
   /* if(index == k)
    {
        return nums[index];
    }
    else
    {
        return -1;
    }*/
}
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<int> arr_tmp(k,0);
    vector<double> result;
    for(int i = 0; i <= nums.size() - k; i++)
    {
        for(int j = 0 ;j < k;j++)
        {
            arr_tmp[j] = nums[i + j];
        }
        if(k % 2 ==1)
        {
            result.push_back((double) findK(arr_tmp,0,k-1,k / 2));
        }
        else
        {
            result.push_back(((double)findK(arr_tmp,0,k-1,k / 2) + findK(arr_tmp,0,k-1,k/2 -1)) / 2);
        }
    }
    return result;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(-1);
    nums.push_back(-3);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);
   // cout <<nums[ findK(nums,0,nums.size() - 1, 5)]<<endl;
    for(int i = 0 ; i < nums.size();i++)
    {
        cout << nums[i] << '\t';
    }
    cout << endl;
    vector<double> result = medianSlidingWindow(nums,3);
    for(int i = 0 ; i < result.size(); i++)
    {
        cout << result[i] << '\t';
    }
    cout << endl;
    /*cout << findK(nums,nums.size()/2)<< endl;
    for(int i = 0 ; i < nums.size();i++)
    {
        cout << nums[i] << '\t';
    }
    cout << endl;*/
}
