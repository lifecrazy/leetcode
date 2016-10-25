/*************************************************************************
	> File Name: leetcode275.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Oct 2016 11:15:31 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;

int hIndex(vector<int>& citations) {
    int result = 0;
    if(citations.size() == 0)
    {
        return 0;
    }
    for(int i = citations.size() -1 ; i >= 0 && citations[i] >= (citations.size() - i);i--)
    {
        result = citations.size() - i;
    }
    return result;
}
int main()
{
    vector<int> nums;
   // nums.push_back(3);
   // nums.push_back(0);
   // nums.push_back(6);
    nums.push_back(1);
   // nums.push_back(5);
    cout << hIndex(nums) << endl;
}
