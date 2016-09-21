/*************************************************************************
> File Name: leetcode003.cpp
> Author: 
> Mail: 
> Created Time: Tue 20 Sep 2016 06:26:18 PM PDT
************************************************************************/

#include<iostream>
using namespace std;
/*
*abcabcbb   abc  3.
bbbbb      b    1.
pwwkew     wke  3.
* */
//思路：让当前元素从第一个元素开始遍历并计数cur，如果发现
//有相同的元素则cur回1，并下次的起始点从这个相同的元素的
//下一个开始才重新计数
//当前元素计数完毕之后更新最大值，如果当前的不同元素的数量
//比之前的最大值大则更新当前值
int lengthOfLongestSubstring(string s) {
    int len = 0 ;
    int start = 0;
    int cur = 0;
    for(int i = 0 ; i < s.length();i++)
    {
        cur = 1;
        for(int j = start ;j < i;j++)
        {
            if(s[i] == s[j])
            {
                start = j + 1;
                cur = 1;
                break;
            }
            else
            {
                cur++;
            }
        }
        if(cur > len)
        {
            len = cur;
        }
    }
    return len;
}
int main()
{
    cout << "abcabcbb:"<< lengthOfLongestSubstring("abcabcbb") << endl;
    cout << "abc:"<< lengthOfLongestSubstring("abc") << endl;
    cout << "bbbbb" << lengthOfLongestSubstring("bbbbb") << endl;
    cout << "pwwkew" << lengthOfLongestSubstring("pwwkew") << endl;
}
