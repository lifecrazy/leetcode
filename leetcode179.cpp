/*************************************************************************
	> File Name: leetcode179.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Oct 2016 10:37:22 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string a,string b)
{
    return a + b > b + a;
}
string largestNumber(vector<int>& nums) {
    vector<string> s_num;
    for(int i = 0; i < nums.size(); i++)
    {
        s_num.push_back(to_string(nums[i]));
    }
    sort(s_num.begin(),s_num.end(),cmp);
    string res = "";
    for(int i = 0; i <s_num.size();i++)
    {
        res += s_num[i];
    }
    if(res[0] == '0')
        return "0";
    return res;
}
int main()
{
    vector<int> data;
    data.push_back(3);
    data.push_back(30);
    data.push_back(34);
    data.push_back(5);
    data.push_back(9);
    cout << largestNumber(data) << endl;
}
