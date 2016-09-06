/*************************************************************************
	> File Name: leetcode034.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 05 Sep 2016 07:32:05 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result;
    int count = 0;
    for(int i = 0 ;i < nums.size();i++)
    {
        if(nums[i] == target)
        {
            if(count == 0)
            {
                result.push_back(i);
            }
            count++;
        }
    }
    if(result.size() == 1)
    {
        result.push_back(result[0] + count - 1);
    }
    else
    {
        result.push_back(-1);
        result.push_back(-1);
    }
    return result;
}
int main()
{
    vector<int> data;
    data.push_back(5);
    data.push_back(7);
    data.push_back(7);
    data.push_back(8);
    data.push_back(8);
    data.push_back(10);
    for(int i = 0; i < data.size();i++)
    {
        cout << data[i] << '\t';
    }
    cout << endl;
    vector<int> result = searchRange(data,8);
    for(int i = 0 ;i < result.size(); i++)
    {
        cout << result[i] << '\t';
    }
    cout << endl;
}
