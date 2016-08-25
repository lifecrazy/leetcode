/*************************************************************************
	> File Name: leetcode005.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Aug 2016 11:50:09 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

//方法一：从中心向两边寻找，分为子串的个数为奇数和偶数的情况
//当为奇数个是，当前的字符为最中心的那个字符依次比较两边的字符判断其是否相等
//当为偶数个时，当前字符和下一个字符为中心，首先判断这两个字符是否相等
//按照上述方法寻找最长的回文子字符串
//其时间复杂度为n^2
//还有两种方法
//如果从两边向中间查找的话其时间复杂度为n^3
//还有一种用空间换时间的方法manacher算法
string longestPalindrome(string s) {
    int len = s.length();
    int i = 0 ;
    int max_len = 0;
    int start = 0;
    while(i < len)
    {
        int left = i-1;
        int right = i+1;
        int odd_len = 1;
        while(left >= 0 && right < len && s[left] == s[right])
        {
            left--;
            right++;
            odd_len +=2;
        }
        if( odd_len> max_len)
        {
            start = ++left;
            max_len = odd_len;
        }
        left = i;
        right = i + 1;
        int even_len = 0;
        while(left >= 0 && right < len && s[left] == s[right])
        {
            left--;
            right++;
            even_len += 2;
        }
        if(even_len > max_len)
        {
            start = ++left;
            max_len = even_len;
        }
        i++;
    }
    return s.substr(start,max_len);
}
int main()
{
    string str = "google";
    cout << longestPalindrome(str) << endl;
    cout << longestPalindrome("abcdefg") << endl;
    cout << longestPalindrome("abba") << endl;
}
