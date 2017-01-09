/*************************************************************************
	> File Name: leetcode480.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Jan 2017 10:08:10 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

/*int findk(vector<int>& nums,int left,int right, int pos)
{
    int cur = nums[left];
    int i = left + 1;
    int j = right;
    while(i <= j)
    {
        while(nums[i] > cur) i++;
        while(nums[j] < cur) j--;
        if(i < j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    int temp = nums[left];
    nums[left] = nums[j];
    nums[j] = temp;
    int len = j - left + 1;
    if(len == pos)
    {
        return nums[j];
    }
    else if(len > pos)
    {
        return findk(nums,left, j - 1,pos);
    }
    else
    {
        return findk(nums,j + 1,right,pos -len);
    }
}*/
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
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
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
    //quickSort(nums , 0 , nums.size() - 1);
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
}
