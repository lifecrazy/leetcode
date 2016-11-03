/*************************************************************************
	> File Name: leetcode390.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Nov 2016 10:49:45 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int lastRemaining(int n) {
    vector<int> nums;
    for(int i = 1;i <= n; i++)
    {
        nums.push_back(i);
    }
    int k = 0;
    while(nums.size() != 1)
    {
        if(k % 2 == 0)
        {
        int i = 1;
        while(i <= nums.size())
        {
            i--;
            nums.erase(nums.begin() + i);
            i++;
            i++;
        }
        }
        else
        {
            int i = nums.size()-1;
            while(i >= 0)
            {
                nums.erase(nums.begin() + i);
                i--;
                i--;
            }
        }
/*    for(int i = 0;i < nums.size();i++)
    {
        cout << nums[i] << '\t';
    }
    cout <<endl;*/
        k++;
    }
    return nums[0];
}
int main()
{
    cout << lastRemaining(5) << endl;
    cout << lastRemaining(9) << endl;
    cout << lastRemaining(6) << endl;
}
