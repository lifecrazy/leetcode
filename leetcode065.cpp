/*************************************************************************
	> File Name: leetcode065.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 14 Dec 2016 11:40:53 PM PST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isNumber(string s) {
    //首先执行trim的过程
    int left = 0;
    while(left < s.length()&& s[left] == ' ')
    {
        left++;
    }
    int right = s.length() - 1;
    while(right >= left && s[right] == ' ')
    {
        right--;
    }
    cout << "left:"<<left<<"right:"<<right<<endl;
    //如果第一个非空字符为正负号则跳过
    if(s[left] == '-'||s[left] == '+')
    {
        left++;
    }
    if((left >= right)&&(s[left] <'0' || s[left] >'9'))
    {
        return false;
    }
    //如果第一个字符或者最后一个字符为e或者E肯定不是数字
    if(s[left] == 'e'||s[left] == 'E'||s[right] == 'e'||s[right] == 'E')
    {
        return false;
    }
    int pointCount = 0 ;
    int ePos = -1;
    int eCount = 0;
    for(int i = left; i <= right; i++)
    {
        //字符串中含有0-9eE不处理
        if(s[i] >='0' && s[i] <='9')
        {

        }
        else if(s[i] == 'e'||s[i] == 'E')
        {
            ePos = i;
            if(i+1 <right && (s[i+1]=='-'||s[i+1]=='+'))
            {
                i++;
            }
            eCount++;
        }
        //.可以处在字符串的任何位置但只能出现一次
        else if(s[i] == '.')
        {
            if(ePos != -1 && ePos < i)
            {
                return false;
            }
            if((i+1 < right &&i == left&& (s[i+1] == 'e'||s[i+1] == 'E'))||(i-1>left && i == right&&(s[i-1] == 'e'||s[i-1] == 'E')))
            {
                return false;                
            }
            pointCount++;
        }
        else
        {
            return false;
        }
        if(pointCount > 1 || eCount > 1)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cout <<"   1:" << isNumber("   1") <<endl;
    cout <<"0:" << isNumber("0") <<endl;
    cout <<"0.1:" << isNumber("0.1") <<endl;
    cout <<"e2:" << isNumber("e2") <<endl;
    cout <<"1  a:" << isNumber("1  a") <<endl;
    cout <<"2e10:" << isNumber("2e10") <<endl;
    cout <<"..:" << isNumber("..") <<endl;
    cout <<"+1.e+5:" << isNumber("+1.e+5") <<endl;
    cout <<".e1:" << isNumber(".e1") <<endl;
    cout <<"3ee5:" << isNumber("3ee5") <<endl;
    cout <<"3e.5:" << isNumber("3e.5") <<endl;
}
