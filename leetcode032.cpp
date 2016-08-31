/*************************************************************************
> File Name: leetcode032.cpp
> Author: 
> Mail: 
> Created Time: Wed 31 Aug 2016 12:15:54 AM PDT
************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int longestValidParentheses(string s) 
{
    int flags[s.length()];
    for(int i = 0 ; i < s.length();i++)
    {
        flags[i] = 0;
    }
    vector<char> stk;
    for(int i = 0; i < s.length();i++)
    {
        if('(' == s[i])
        {
            stk.push_back(i);
        }
        else if(')' == s[i])
        {
            if(stk.size() > 0)
            {
                flags[i] = 1;
                flags[stk[stk.size() - 1]] = 1;
                stk.erase(stk.end() -1);
            }
        }
    }
    int max_len = 0;
    int cur_len = 0;
    for(int i = 0 ; i < s.length();i++)
    {
        if(flags[i] == 1)
        {
            cur_len++;
        }
        else
        {
            cur_len = 0;
        }
        if(cur_len > max_len)
        {
            max_len = cur_len;
        }
    }
    return max_len;
}
           int main()
           {
               cout << longestValidParentheses("(()")<<endl;
               cout << longestValidParentheses(")()()(")<<endl;
        //       cout << longestValidParentheses("(((())))")<<endl;
          //     cout << longestValidParentheses("(((())))()")<<endl;
            //   cout << longestValidParentheses("(((())())())()")<<endl;
           }
