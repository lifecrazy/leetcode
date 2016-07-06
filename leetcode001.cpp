/*************************************************************************
	> File Name: leetcode001.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Jul 2016 05:33:14 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

//思路：依次遍历每个元素和其后的每个的元素的和，判断其是否等于target
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> results;
    size_t len = nums.size();
    for (int i = 0; i < len ; i++)
    {
        for(int j = i + 1; j < len ; j++)
        {
            if(target == (nums[i] + nums[j]))
            {
                results.push_back(i);
                results.push_back(j);
                return results;
            }
        }
    }
    return results;
}

int main()
{
    vector<int> inputs;
    inputs.push_back(2);
    inputs.push_back(7);
    inputs.push_back(11);
    inputs.push_back(15);
    int target = 9;
    vector<int> results  = twoSum(inputs,target);
    for(int i = 0 ; i < results.size();i++)
    {
        cout << results[i] << "\t";
    }
    cout <<endl;
}
