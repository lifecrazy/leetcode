/*************************************************************************
> File Name: leetcode071.cpp
> Author: 
> Mail: 
> Created Time: Mon 29 Aug 2016 11:07:48 PM PDT
************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string simplifyPath(string path) {
    vector<char> s;
    int len = path.length();
    for(int i = 0 ; i < len; i++)
    {
        //处理./和// ////
        if(i - 1 >= 0 && i + 1 < len && path[i + 1] == '.' && path[i] == '.')
        {
            if(s.size() > 1)
            {
                s.erase(s.end()-1);    
                while(s[s.size() -1] != '/')
                {
                    s.erase(s.end()-1);
                }
            }
            continue;
        }
        else if(i - 1 >= 0 && i + 1 < len && path[i] == '.' && path[i + 1] == '/')
        continue;
        else if(i - 1 >= 0 && i + 1 < len && path[i - 1] == '.' && path[i] == '/')
        continue;
        else if(i - 1 >= 0 && i + 1 < len && path[i - 1] == '/' && path[i] == '/')
        continue;
        else if(i == len - 1 && path[i] == '/')
        continue;
        s.push_back(path[i]);
    }
    string result = "";
    for(int i = 0 ; i < s.size();i++)
    {
        result += s[i];
    }
    return result;
}
int main()
{
    cout <<"/home/---"<<  simplifyPath("/home/") <<endl;
    cout <<"/../---"<<  simplifyPath("/../") <<endl;
    cout <<"/a//b/---"<<  simplifyPath("/a//b/") <<endl;
    cout <<"/a//////////b/---"<<  simplifyPath("/a/////////b/") <<endl;
    cout <<"/a/./b/../../c/---"<<  simplifyPath("/a/./b/../../c/") <<endl;
}
