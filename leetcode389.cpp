/*************************************************************************
	> File Name: leetcode389.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 30 Aug 2016 06:51:05 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
using namespace std;
char findTheDifference(string s, string t) {
/*    char c;
    for(int i = 0 ; i < t.size();i++)
    {
        if(s.find(t[i]) == std::string::npos)
        {
            c = t[i];
        }
    }
    return c;*/
    
    char c;
    map<char,int> s_map;
    for(int i = 0 ;i < s.size(); i++)
    {
        if(s_map.find(s[i]) == s_map.end())
        {
            s_map[s[i]] = 0;
        }
    }
    for(int i = 0 ; i < t.size(); i++)
    {
        if(s_map.find(t[i]) == s_map.end())
        {
            c = t[i];
            break;
        }
    }
    return c;
}
int main()
{
    cout << findTheDifference("abcd","abcde") <<endl;
}
