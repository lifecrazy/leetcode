/*************************************************************************
	> File Name: leetcode480.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Jan 2017 10:08:10 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
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
int findK(vector<int>& nums,int k)
{
    int start = 0;
    int end = nums.size() - 1;
    int index = partition(nums,start,end);
    while(index != k -1)
    {
        if(index > k -1)
        {
            end = index -1;
            index = partition(nums,start,end);
        }
        else
        {
            start = index + 1;
            index = partition(nums,start,end);
        }
    }
    return nums[k];
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
            result.push_back((double)findK(arr_tmp,k / 2));
        }
        else
        {
            result.push_back(((double)findK(arr_tmp,k / 2) + findK(arr_tmp,k/2 -1)) / 2);
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
