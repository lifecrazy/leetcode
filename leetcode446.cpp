/*************************************************************************
	> File Name: leetcode446.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 07 Nov 2016 11:50:21 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
    if(A.size() < 3)
    {
        return 0;
    }
    int result = 0;
    double step = 1.0;
    int tmp = ceil(A.size() / step);
    while(tmp >= 3)
    {
        for(int i = 3; i <= tmp;i++)
        {
            result += tmp - i + 1; 
        }
        step++;
        tmp = ceil(A.size() / step);
    }
    return result;
}
int main()
{
    vector<int> nums ;
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(8);
    nums.push_back(10);
    cout << numberOfArithmeticSlices(nums) << endl;
}
