/*************************************************************************
	> File Name: leetcode487.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 15 Jan 2017 11:27:55 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    vector<int> countArr;
    int count = 0;
    for(int i = 0 ; i < nums.size();i++)
    {
        if(nums[i] == 1)
        {
            count++;
        }
        else
        {
            countArr.push_back(count);
            count = 0;
        }
    }
    countArr.push_back(count);
    int max = 0 ;
    cout << countArr.size()<<endl;
    if(countArr.size() == 1 || countArr.size() == 2)
    {
        max = nums.size();
    }
    else
    {
        for(int i = 1 ; i <countArr.size();i++)
        {
            cout << countArr[i - 1] << "*******" << countArr[i] <<endl;
            if(countArr[i - 1] + 1 + countArr[i] > max)
            {
                max = countArr[i - 1] + 1 + countArr[i];
            }
        }
    }
    return max;
}
int main()
{
    vector<int> nums;
    // [1,1,0,1,1,1]
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    cout << findMaxConsecutiveOnes(nums) << endl;
}
