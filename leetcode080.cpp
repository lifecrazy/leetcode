/*************************************************************************
	> File Name: leetcode080.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 11 Jul 2016 10:21:29 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if(nums.size() <= 2)
    {
        return nums.size();
    }
    int i = 2 ;
    int cur = 2;
    while(i < nums.size())
    {
        if(nums[i] != nums[cur - 2])
        {
            nums[cur] = nums[i];
            cur++;
        }
        i++;
    }
    return cur;
}

int main()
{
    vector<int> data;
    data.push_back(1);
    data.push_back(1);
    data.push_back(1);
   // data.push_back(2);
   // data.push_back(2);
   // data.push_back(3);
    cout << removeDuplicates(data)<<endl;
}
