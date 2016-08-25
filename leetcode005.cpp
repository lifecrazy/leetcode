/*************************************************************************
	> File Name: leetcode005.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Aug 2016 11:50:09 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

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
