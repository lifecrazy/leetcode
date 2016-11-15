/*************************************************************************
	> File Name: leetcode459.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 14 Nov 2016 06:11:59 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;
    
bool IsSame(string str, int i)
{
    for(int j = i ; j < str.size(); j +=i)
    {
        if(str.substr(0,i) != str.substr(j,i))
        {
            return false;
        }
    }
    return true;
} 

bool repeatedSubstringPattern(string str) {
    if(str.size() < 2)
    {
        return false;
    }
    //步长
    for(int i = 1; i <= str.size()/2;i++)
    {
        if(IsSame(str,i))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    //"ababac"
    cout << "abc" <<repeatedSubstringPattern("abc") << endl;
    cout << "abcabc"<<repeatedSubstringPattern("abcabc") <<endl;
    cout << "abcabcac"<<repeatedSubstringPattern("abcabcac") <<endl;
    cout << "acac" <<repeatedSubstringPattern("acac") <<endl;
    cout << "acacab" << repeatedSubstringPattern("acacab") <<endl;
}
