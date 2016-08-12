/*************************************************************************
	> File Name: leetcode345.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Aug 2016 06:49:18 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool IsVewel(char c)
{
    vector<char> vewels;
    vewels.push_back('a');
    vewels.push_back('e');
    vewels.push_back('i');
    vewels.push_back('o');
    vewels.push_back('u');
    vewels.push_back('A');
    vewels.push_back('E');
    vewels.push_back('I');
    vewels.push_back('O');
    vewels.push_back('U');
    bool flag = false;
   for(int i = 0 ; i < vewels.size();i++)
    {
        if(c == vewels[i])
        {
            flag = true;
        }
    }
    return flag;
}
string reverseString(string s) {
    vector<char> startdata;
    vector<char> enddata;
    for(int i = 0 ; i < s.length()/2;i++)
    {
        if(IsVewel(s[i]))
        {
            enddata.insert(enddata.begin(),s[i]);
        }
        else
        {
            startdata.push_back(s[i]);
        }
        if(IsVewel(s[s.length()- i -1]))
        {
            startdata.push_back(s[s.length() - i - 1]);
        }
        else
        {
            enddata.insert(enddata.begin(),s[s.length() - i - 1]);
        }
    }
    if(s.length()%2 != 0)
    {
        startdata.push_back(s[s.length()/2+1]);
    }
    string result ;
    for(int i = 0 ; i < startdata.size(); i++)
    {
        result +=startdata[i];
    }
    for(int i = 0 ; i < enddata.size(); i++)
    {
        result += enddata[i];
    }
    return result;
}
int main()
{
    string s = "hello";
    cout << reverseString(s) << endl;
    string s1 ="leetcode";
    cout << reverseString(s1) << endl;
}
