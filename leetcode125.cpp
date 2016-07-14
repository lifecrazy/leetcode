/*************************************************************************
	> File Name: leetcode125.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Jul 2016 08:04:40 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

 bool isPalindrome(string s) {
     bool flag = true;
     int i = 0;
     int j = s.length() -1;
     while(i <= j)
     {
         if(!((s[i] >= 'a' && s[i] <='z') || ( s[i] >= 'A' && s[i] <= 'Z')))
         {
             i++;
             continue;
         }
         if(!((s[j] >= 'a' && s[j] <='z') || ( s[j] >= 'A' && s[j] <= 'Z')))
         {
             j--;
             continue;
         }
         if(!(s[i] == s[j]|| s[i] == (s[j] + 'a' - 'A')||s[i] == (s[j] + 'A' - 'a')))
         {
             flag = false;
             break;
         }
         i++;
         j--;
     }
     return flag;
 }

 int main()
 {
     string s1 = "A man, a plan, a canal: Panama";
     string s2 = "a";
     string s3 = "";
     cout <<"resutl of s1:"<< isPalindrome(s1)<<endl;
     cout <<"s2:"<< isPalindrome(s2)<<endl;
     cout <<"s3:"<< isPalindrome(s3)<<endl;
 }
