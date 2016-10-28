/*************************************************************************
	> File Name: leetcode414.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Oct 2016 08:09:37 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int thirdMax(vector<int>& nums) {
    if(nums.size() == 1)
    {
        return nums[0];   
    }
    else if(nums.size() == 2)
    {
        return nums[0] > nums[1]?nums[0]:nums[1];   
    }
    else
    {
        sort(nums.begin(),nums.end(),[](int &x,int &y)->int {return x > y;});
        int i = 1;
        int cur = 0;
        int result ;
        while(i < nums.size())
        {
            if(nums[i] != nums[cur])
            {
                cur++;
                if(cur + 1 == 3)
                {
                    result = i;
                    break;
                }
                i++;
            }
        }
        return nums[result];
    }
}
int main()
{
    vector<int> data;
    data.push_back(3);
    data.push_back(1);
    data.push_back(2);
    cout << thirdMax(data) << endl;
}
