/*************************************************************************
	> File Name: leetcode014.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 28 Aug 2016 06:49:50 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//方法一纵向扫描
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() <= 0)
    {
        return "";
    }
    int right = strs[0].length();
    for(int i = 1;i < strs.size();i++)
    {
        for(int j = 0; j < right  ; j++)
        {
            if(strs[0][j] != strs[i][j])
            {
                right = j;
                break;
            }
        }

    }
    return strs[0].substr(0,right);
}
//方法二横向扫描
string longestCommonPrefix_2(vector<string>& strs) {
    if(strs.size() <= 0)
    {
        return "";
    }
    int right = strs[0].length();
    for(int i = 0 ; i < right; i++)
    {
        for(int j = 1 ; j < strs.size(); j++)
        {
            if(strs[j][i] != strs[0][i])
            {
                right = i;
                break;
            }
        }
    }
    return strs[0].substr(0,right);
}
int main ()
{
    string str1 = "abch";
    string str2 = "abcdefghi";
    string str3 = "abcdef";
    vector<string> strs;
    strs.push_back(str1);
    strs.push_back(str2);
    strs.push_back(str3);
    cout << longestCommonPrefix(strs) << endl;
    cout <<longestCommonPrefix_2(strs) << endl;
}
