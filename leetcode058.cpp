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
    int i = s.length() - 1;
    while(s[i] == ' ')
    {
        i--;
    }
    while(i >= 0)
    {
        if(s[i] == ' ')
        {
            break;
        }
        len++;
        i--;
    }
    return len;
}

int main()
{
    string s = "hello world";
    cout << lengthOfLastWord(s) << endl;
    cout << lengthOfLastWord(" ") << endl;
    cout << lengthOfLastWord("a ") << endl;
    cout << lengthOfLastWord("a b ") << endl;
    cout << lengthOfLastWord("a b                                                  ") << endl;
}
