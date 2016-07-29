/*************************************************************************
> File Name: leetcode031.cpp
> Author: 
> Mail: 
> Created Time: Wed 27 Jul 2016 01:53:06 AM PDT
************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
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
    //当partitionNumber和changeNum都为0表示已经排列到最后一个
    if(partitionNumber == 0 && changeNum == 0)
    {
        for(int i = 0 ; i < nums.size()/2;i++)
        {
            temp = nums[i];
            nums[i] = nums[nums.size() - 1 - i];
            nums[nums.size() - 1 - i] = temp;
        }
    }
    else
    {
        for(int i = partitionNumber + 1 ; i <= partitionNumber + (nums.size()-1 - partitionNumber + 1)/2; i++)
        {
            temp = nums[nums.size()-1-(i-partitionNumber - 1)];
            nums[nums.size()-1-(i-partitionNumber - 1)] = nums[i];
            nums[i] = temp;
        }

    }
}
//方法一：超时
string getPermutation(int n, int k) {
    vector<int> data;
    int num = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        num *= i;
        data.push_back(i);
    }
    k = k % num == 0 ?num -1 :k-1;
    for(int i = 0 ; i < k  ; i++)
    {
        nextPermutation(data);
    }
    string result = "";
    for(int i = 0 ; i < n ; i++)
    {
        result+='0' + data[i];
    }
    return result;
}
//方法二 递归
void swap(int* a,int *b)
{
    int temp;
   temp = *a;
    *a = *b;
    *b = temp;
}
vector<int> tempResult;
void perm(vector<int>& data,int begin,int end)
{
    if(begin > end)
    {
        int n = 0 ;
        for(int i = 0 ; i <= end ; i++)
        {
            n = n * 10 + data[i];
        }
        tempResult.push_back(n);
    }
    else
    {
        for(int i = begin; i <= end ; i++)
        {
            swap(&data[begin],&data[i]);
            perm(data,begin + 1,end);
            swap(&data[begin],&data[i]);
        }
    }
}
string getPermutation_2(int n, int k) {
    vector<int> data;
    int num = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        num *= i;
        data.push_back(i);
    }
    perm(data,0,data.size()-1);
    sort(tempResult.begin(),tempResult.end());

    stringstream ss;
    ss << tempResult[k-1];
    return ss.str();
}
int main()
{
    cout << getPermutation(3,5) << endl;
    cout << getPermutation(8,8590) << endl;
    cout << getPermutation_2(3,5)<<endl;
}
