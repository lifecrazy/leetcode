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
    int max = 0 ;
    int count = 0;
    int zeroCount = 0;
    for(int i = 0 ; i < nums.size();i++)
    {
        if(nums[i] == 1)
        {
            count++;
        }
        else
        {
            zeroCount++;
        }
        //1.没有0全部是1 count 不需要回0
        //2.存在一个0 剩下的全部是1 count 不需要回0
        //3.存在多个零， count和zeroCount需要回0重新计数
        if(zeroCount == 0)
        {
            max = count;
        }
        else if(zeroCount == 1)
        {
            max = count + zeroCount;
        }
        else
        {
            max = count + 1;
            count = 0;
            zeroCount = 0;
        }
    }
    return max ;
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
    //nums.push_back(1);
    cout << findMaxConsecutiveOnes(nums) << endl;
}
