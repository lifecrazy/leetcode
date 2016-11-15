/*************************************************************************
	> File Name: leetcode459.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 14 Nov 2016 06:11:59 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;
bool repeatedSubstringPattern(string str) {
    if(str.size() < 2)
    {
        return false;
    }
    for(int i = 0; i < str.size()/2;i++)
    {
        for(int j = i + 1; j < str.size();j++)
        {
            int count = 0;
            for(int k = 0; k < i + 1;k++)
            {
                if(str[i + k] == str[j + k])
                {
                    count++;
                }
                if(count > 1)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    cout << repeatedSubstringPattern("abc") << endl;
    cout << repeatedSubstringPattern("abcabc") <<endl;
    cout << repeatedSubstringPattern("abcabcac") <<endl;
    cout << repeatedSubstringPattern("acabcac") <<endl;
}
