/*************************************************************************
> File Name: leetcode008.cpp
> Author: 
> Mail: 
> Created Time: Wed 24 Aug 2016 06:15:21 PM PDT
************************************************************************/

#include<iostream>
#include<string>
#include<climits>
using namespace std;

int myAtoi(string str) {
    int len = str.length();
    if(len <= 0)
    {
        return 0;
    }
    int index = 0;
    //处理左边的空格
    while(index<len && str[index] == ' ')
    {
        index++;
    }
    //判断数字的正负号
    bool flag = false;
    if(str[index] == '+')
    {
        index++;
    }
    else if(str[index] == '-')
    {
        index++;
        flag = true;
    }
    int result = 0;
    while(index < len)
    {      
        if('0'<= str[index] && str[index] <='9')
        {
            if(result > INT_MAX / 10 || (result == INT_MAX/ 10 && (str[index] - '0') >INT_MAX % 10))
            {
                return flag  ? INT_MIN :INT_MAX;

            }
            result =(result * 10 + (str[index]-'0'));
        }
        else
        {
            break;
        }
        index++;
    }
    return flag ? result * (-1):result ;
}
int main()
{
    cout << myAtoi("          123") <<endl;
    cout << myAtoi("+123") <<endl;
    cout << myAtoi("-123") <<endl;
    cout << myAtoi("123") <<endl;
    cout << myAtoi("11111111111111111111111111111111111111111111111111111111111")<<endl;
    cout << myAtoi("+-2")<<endl;
}
