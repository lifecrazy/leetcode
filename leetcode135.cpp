/*************************************************************************
	> File Name: leetcode135.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 16 Aug 2016 11:38:51 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
/*
*初始化数组dp，数组成员均为1 ，每个孩子先分配一个糖果
从左向右遍历，如果第i个孩子比第i - 1孩子等级高，则dp[i] = dp[i - 1] + 1
从右向左遍历，如果第i个孩子比第i + 1孩子等级高并且糖果比i+1糖果少，则dp[i] = dp[i + 1] + 1
* */
int candy(vector<int>& ratings) {
    int resultNum = 0;
    vector<int> result;
    for(int i = 0 ; i < ratings.size();i++)
    {
        result.push_back(1);
    }
    for(int i = 0 ; i < result.size(); i++)
    {
        if((i-1 >=0 )&& ratings[i] >ratings[i-1])
        {
            result[i] = result[i-1] +1;
        }
    }
    for(int i = result.size()-1; i >=0;i--)
    {
        if((i+1<result.size())&& ratings[i]>ratings[i+1] && result[i] < result[i+1])
        {
            result[i] = result[i+1] +1;
        }
    }
    for(int i = 0 ; i < result.size(); i++)
    {
//        cout << result[i] << "\t";
        resultNum+=result[i];
    }
  //  cout <<endl;
    return resultNum;
}
int main()
{
    srand(time(0));
    int count = 10;
    vector<int> ratings;
    for(int i = 0 ; i < count; i++)
    {
        int temp = rand()%10;
        cout << temp << "\t";
        ratings.push_back(temp);
    }
    cout << endl;
    cout << candy(ratings) <<endl;
}
