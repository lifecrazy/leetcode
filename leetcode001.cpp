/*************************************************************************
	> File Name: leetcode001.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 06 Jul 2016 05:33:14 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

//方法一：
//思路：依次遍历每个元素和其后的每个的元素的和，判断其是否等于target
//时间复杂度为：n2
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> results;
    size_t len = nums.size();
    for (size_t i = 0; i < len ; i++)
    {
        for(size_t j = i + 1; j < len ; j++)
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
//方法二：
//思路：将数组中的所有数字存储在map 或者set中key 为 数组的index,value为数组的值
//然后依次查找 其时间复杂度为o(n) 该方法是用空间换时间
vector<int> twoSum_2(vector<int>& nums, int target) {
    vector<int> results;
    map<int,int> mapData;
    size_t len = nums.size();
    for(size_t i = 0; i < len ; i++)
    {
        mapData.insert(pair<int,int>(nums[i],i));
    }
    map<int,int>::iterator iter;
    for(size_t i = 0;i < len ; i++)
    {
        int temp = target - nums[i];
        if(mapData.find(temp)!= mapData.end() && mapData[temp] > i)
        {
            results.push_back(i);
            results.push_back(mapData[temp]);
            return results;
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
    int target = 22;
    cout << "twoSum results" << endl;
    vector<int> results  = twoSum(inputs,target);
    for(size_t i = 0 ; i < results.size();i++)
    {
        cout << results[i] << "\t";
    }
    cout << endl;
    cout << "twoSum_2 results_2" << endl;
    vector<int> results_2 = twoSum_2(inputs,target);
    for(size_t i = 0 ; i < results.size() ; i++)
    {
        cout << results_2[i] << "\t";
    }
    cout << endl;
}
