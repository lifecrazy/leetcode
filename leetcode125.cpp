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
         if(!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <='z') || ( s[i] >= 'A' && s[i] <= 'Z')))
         {
             i++;
             continue;
         }
         if(!((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'a' && s[j] <='z') || ( s[j] >= 'A' && s[j] <= 'Z')))
         {
             j--;
             continue;
         }
         if( toupper(s[i]) == toupper(s[j]))
         {
             i++;
             j--;
         }
         else
         {
             flag = false;
             break;
         }
     }
     return flag;
 }

 int main()
 {
     string s1 = "A man, a plan, a canal: Panama";
     string s2 = "abccba";
     string s3 = "0P";
    cout <<"resutl of s1:"<< isPalindrome(s1)<<endl;
    cout <<"s2:"<< isPalindrome(s2)<<endl;
     cout <<"s3:"<< isPalindrome(s3)<<endl;
 }
