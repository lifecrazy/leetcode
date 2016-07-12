/*************************************************************************
	> File Name: leetcode217.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Jul 2016 11:24:42 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
    map<int,int> result_map;
    int i = 0 ;
    while(i < nums.size())
    {
        if(result_map.find(nums[i]) != result_map.end())
        {
            return true;
        }
        else
        {
            result_map[nums[i]] = 1;
        }
        i++;
    }
    return false;
}
int main()
{
    vector<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    data.push_back(4);
    data.push_back(5);
    data.push_back(6);
    cout << containsDuplicate(data) << endl;
}
