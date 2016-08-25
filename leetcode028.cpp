/*************************************************************************
> File Name: leetcode028.cpp
> Author: 
> Mail: 
> Created Time: Wed 24 Aug 2016 01:40:57 AM PDT
************************************************************************/

#include<iostream>
#include<string>

using namespace std;
//方法一暴力破解的方法 
//
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
//方法二

int strStr_2(string haystack, string needle) {
    int result = -1;
    int len_h = haystack.length();
    int len_n = needle.length();
    if(len_h < len_n)
    {
        return -1;
    }
    else if(len_h > len_n)
    {
        for(int i = 0 ; i < len_h-len_n+1;i++)
        {
            int j = 0;
            for(; j < len_n;j++)
            {
                if(haystack[i+j] != needle[j])
                {
                    break;
                }
            }
            if(j == len_n)
            {
                result = i;
                break;
            }
        }
        return result;
    }
    else
    {
        int i =0;
        for(; i < len_h;i++)
        {
            if(haystack[i] != needle[i])
            {
                break;
            }
        }
        if(i == len_h)
        {
            result =0;
        }
        return result;
    }
return result;
}
int main()
{
    string str = "abcdefghijk";
    string needle = "ghi";
    cout << strStr("","") <<endl;
    cout << strStr(str,needle)<< endl;
    cout <<strStr_2("aaaaaaddddddgsdfasdfasdf","ffffffffffff")<<endl;
    cout <<strStr_2("","")<<endl;
    cout <<strStr_2(str,needle) << endl;
}
