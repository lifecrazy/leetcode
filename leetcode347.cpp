/*************************************************************************
	> File Name: leetcode347.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Oct 2016 07:00:43 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
  /*  if(nums.size() <= 1)
    {
        return nums;
    }*/
    vector<int> res;
    int i = 1 ;
    int cur = 0;
    res.push_back(nums[0]);
    while(i < nums.size())
    {
        if(nums[i] != nums[cur])
        {
            cur++;
            res.push_back(nums[i]);
            if(cur + 1 == k)
            {
                break;
            }
        }
        i++;
    }
    return res;
}

int main()
{
    vector<int> data;
    data.push_back(1);
    data.push_back(1);
    data.push_back(1);
    data.push_back(2);
    data.push_back(2);
    data.push_back(3);
    vector<int> res = topKFrequent(data,2) ;
    for(int i = 0 ; i < res.size();i++)
    {
        cout << res[i] << "\t";
    }
    cout << endl;
}
