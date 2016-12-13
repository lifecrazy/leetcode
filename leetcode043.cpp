/*************************************************************************
	> File Name: leetcode043.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 12 Dec 2016 11:16:13 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
string reverse(string s)
{
    char c ;
    for(int i = 0 ; i < s.size()/2;i++)
    {
        c = s[i];
        s[i] = s[s.size() - i -1];
        s[s.size() -i - 1] = c;
    }
    return s;
}
string multiply(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    string res(len1+len2,'0');
    string re_num1 = reverse(num1);
    string re_num2 = reverse(num2);
    int temp = 0 ;
    for(int i = 0 ;i < re_num1.size();i++)
    {
        int j = 0;
        for(; j < re_num2.size();j++)
        {
            temp += res[i + j] -'0'+ (re_num1[i] - '0')*(re_num2[j] -'0');
            res[i+j] = (temp% 10) +'0';
            temp = temp/10;
        }
        while(temp)
        {
            res[i+j++] += temp%10;
            temp = temp / 10;
        }
    }
    for(int i = res.size() -1 ;i >=0;i--)
    {
        if(res[i]!= '0')
        {
            break;
        }
        else
        {
            res.pop_back();
        }
    }
    res = reverse(res);
    return res;
}
int main()
{
    //cout <<"abcd\t"<< reverse("abcd") <<endl;
    cout << multiply("17","5")<<endl;
}
