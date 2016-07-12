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
    if(nums.size() <= 1)
    {
        return nums.size();
    }
    int i = 0 ;
    int cur = 1;
    int count = 0;
    while(cur < nums.size())
    {
        if(nums[i] != nums[cur])
        {
            if(count < 2)
            {
                i++;
            }
            else
            {
                i +=2;
            }
            nums[i] = nums[cur];
            count = 0;
        }
        cur++;
        count++;
    }
    for(int j = 0 ; j < i + 1;j++)
    {
        cout << nums[j] <<"\t";
    }
    cout << endl;
    return i + 1;
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
    cout << removeDuplicates(data)<<endl;
}
