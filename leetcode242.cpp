/*************************************************************************
	> File Name: leetcode242.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Oct 2016 12:47:45 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length())
        return false;
    map<char,int> count_map;
    for(int i = 0; i < 26;i++)
    {
        count_map['a' + i] = 0;
    }
    for(int i = 0; i <s.length();i++)
    {
        count_map[s[i]]++;
    }
    for(int i = 0 ; i < t.length();i++)
    {
        count_map[t[i]]--;
    }
    for(int i = 0 ; i < 26;i++)
    {
        if(count_map['a' + i] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cout << isAnagram("nagaram","anagram")<<endl;
    cout << isAnagram("rat","car")<<endl;
}
