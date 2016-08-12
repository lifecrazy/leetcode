/*************************************************************************
	> File Name: leetcode344.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Aug 2016 06:49:18 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string reverseString(string s) {
    vector<char> data;
    for(int i = 0 ; i < s.length();i++)
    {
        data.insert(data.begin(),s[i]);
    }
    string result ;
    for(int i = 0 ; i < data.size(); i++)
    {
        result += data[i];
    }
    return result;
}
int main()
{
    string s = "hello";
    cout << reverseString(s) << endl;
}
