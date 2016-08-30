/*************************************************************************
	> File Name: leetcode058.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 29 Aug 2016 06:37:48 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int lengthOfLastWord(string s) {
    int len = 0 ;
    for(int i = 0 ;i < s.length();i++)
    {
        if(s[i] == ' ')
        {
            len = 0;
        }
        else
        {
            len++;
        }
    }
    return len;
}

int main()
{
    string s = "hello world";
    cout << lengthOfLastWord(s) << endl;
}
