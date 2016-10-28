/*************************************************************************
	> File Name: leetcode347.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Oct 2016 07:00:43 PM PDT
 ************************************************************************/

#include<iostream>
#include<tr1/unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    std::tr1:: unordered_map<int,int> num_map;
    for(int i = 0 ; i < nums.size();i++)
    {
        if(num_map.find(nums[i]) != num_map.end())
        {
            num_map[nums[i]]++;
        }
        else
        {
            num_map[nums[i]] = 1;
        }
    }
    vector<pair<int,int> > vtMap;
    for(auto it =num_map.begin();it != num_map.end();it++)
    {
        vtMap.push_back(make_pair(it->first,it->second));
    }
    sort(vtMap.begin(),vtMap.end(),[](const pair<int,int> &x,const pair<int,int> &y)-> int{ return x.second > y.second; });
    vector<int> res;
    int i = 0;
    for(auto it = vtMap.begin();it!=vtMap.end();it++)
    {
       // cout << it->first << ":" <<it->second<<endl;
       res.push_back(it->first);
        i++;
        if(i >= k)
        {
            break;
        }
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
