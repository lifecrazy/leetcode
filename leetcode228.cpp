/*************************************************************************
> File Name: leetcode228.cpp
> Author: 
> Mail: 
> Created Time: Tue 12 Jul 2016 10:13:38 PM PDT
************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    if(nums.size() <= 1)
    {
        stringstream s;
        s << nums[0];
        result.push_back(s.str());
        return result;
    }
    int pre = 0;
    int cur = 1;
    int start = nums[pre];
    int end = nums[pre];
    while(cur < nums.size())
    {
        if(nums[cur] - nums[pre] == 1)
        {
            cur++;
            pre++;
        }
        else
        {
            end = nums[pre];
            stringstream startS;
            startS << start;
            stringstream endS;
            endS << end;
            result.push_back(startS.str()+"->"+endS.str());
            start = nums[cur];
            pre = cur;
            cur++;
        }
    }
    if(start == nums[pre])
    {
        stringstream startS;
        startS << start;
        result.push_back(startS.str());
    }
    else
    {
        stringstream startS;
        startS << start;
        stringstream endS;
        endS << nums[pre];
        result.push_back(startS.str()+ "->" + endS.str());
    }
    return result;
}

int main()
{
    vector<int> data;
    data.push_back(0);
    data.push_back(1);
    data.push_back(2);
    data.push_back(4);
    data.push_back(5);
    data.push_back(6);
    data.push_back(8);
    vector<string> result= summaryRanges(data);
    for(int i = 0 ; i < result.size();i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl;
}
