/*************************************************************************
	> File Name: leetcode090.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 06 Sep 2016 06:20:58 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
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
    sort(nums.begin(),nums.end());
    int index = 0;
    int last = 0;
    for(int i = 0; i < len; i++)
    { 
        if(i - 1 >= 0 && nums[i - 1] == nums[i])
        {
            index = last; 
        }
        else
        {
            index = 0;
        }
        int size = result.size();
        for(int j = index ; j < size; j++)
        {
            vector<int> temp;
            for(int k = 0; k < result[j].size();k++)
            {
                temp.push_back(result[j][k]);
            }
            temp.push_back(nums[i]);
            result.push_back(temp);
        }
        last = size;
    }
    return result;
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
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
}
