/*************************************************************************
	> File Name: leetcode368.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 06 Sep 2016 06:20:58 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > result;
    vector<int> blank;
    result.push_back(blank);
    int len = nums.size();
    if(len == 0)
    {
        return result;
    }
    for(int i = 0; i < len; i++)
    {
        int size = result.size();
        for(int j = 0 ; j < size; j++)
        {
            vector<int> temp;
            for(int k = 0; k < result[j].size();k++)
            {
                temp.push_back(result[j][k]);
            }
            temp.push_back(nums[i]);
            result.push_back(temp);
        }
    }
    return result;
}

vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<vector<int> > result = subsets(nums);
    vector<int> res;
    for(int i = 0; i < result.size();i++)
    {
        int k = 0;
        for(;k < result[i].size();k++)
        {
            int j = k+1;
            for(;j < result[i].size();j++)
            {
                if(result[i][k] % result[i][j] != 0 && result[i][j] % result[i][k] !=0)
                //if(!(result[i][k] % result[i][j] == 0 || result[i][j] % result[i][k] ==0))
                {
                    break;
                }
            }
            if(j != result[i].size())
            {
                break;
            }
        }
        if(k == result[i].size()&& k > res.size())
        {
            res.swap(result[i]);
        }
    }
    return res;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(8);
    vector<vector<int> > result = subsets(nums);
    for(int i = 0 ; i < result.size(); i++)
    {
        if(result[i].size() == 0)
        {
            cout <<"subset is blank" ;
        }
        else
        {
            for(int j = 0;j <result[i].size();j++)
            {
                cout << result[i][j] <<'\t';
            }
        }
        cout << endl;
    }
    cout <<"------------------------------"<<endl;
    vector<int> res = largestDivisibleSubset(nums);
    for(int i = 0 ; i < res.size();i++)
    {
        cout << res[i] <<'\t';
    }
    cout << endl;
}
