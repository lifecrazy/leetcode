/*************************************************************************
	> File Name: leetcode010.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Dec 2016 11:22:04 PM PST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
//"a"对应"a"
//任意字母对应"."
//0到多个相同字符x,对应"x*", x代表的是相同的字符中取一个,比如"aaaab"对应是"a*b"
//"*"还有一个易于疏忽的地方比如"aaa"对应"a*a"
bool isMatch(string s, string p) {
    if(s.size() == 0)
    {
        return p.size() == 0;
    }
    if(p.size() == 0)
    {
        return s.size() == 0;
    }
    int s_len = s.size();
    int p_len = p.size();
    if(p_len == 1)
    {
        if(p == s||(p == "."&& s.size() == 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(p[1] != '*')
    {
        if(s.size() > 0 && (p[0] == s[0] || p[0] == '.'))
        {
            return isMatch(s.substr(1,s.size() - 1), p.substr(1,p.size() - 1));
        }
        return false;
    }
    else
    {
        while(s.size() > 0 && (p[0] == s[0] || p[0] == '.'))
        {
            if(isMatch(s,p.substr(2,p.size() - 2)))
            {
                return true;
            }
            s = s.substr(1,s.size() - 1);
        }
        return isMatch(s,p.substr(2,p.size() - 2));
    }
}
int main()
{
    cout << isMatch("aa","a") << endl;
    cout << isMatch("aa","aa") << endl;
    cout << isMatch("aaa","aa") << endl;
    cout << isMatch("aa", "a*") << endl;
    cout << isMatch("aa", ".*") << endl;
    cout << isMatch("ab", ".*") << endl;
    cout << isMatch("aab", "c*a*b") << endl;
}

