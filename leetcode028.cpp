/*************************************************************************
	> File Name: leetcode028.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Aug 2016 01:40:57 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;
int strStr(string haystack, string needle) {
    int result = -1;
    for(int i = 0 ; i < haystack.length();i++)
    {
        int j = 0;
        for(; j < needle.length();j++)
        {
            if(haystack[i+j] != needle[j])
            {
                break;
            }
        }
        if(j == needle.length())
        {
            result = i;
            break;
        }
    }
    return result;
}
int main()
{
    string str = "abcdefghijk";
    string needle = "ghi";
    cout << strStr(str,needle)<< endl;
}
