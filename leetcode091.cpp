/*************************************************************************
	> File Name: leetcode091.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Dec 2016 06:44:02 PM PST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int numDecodings(string s) {
    if(s.size() <= 0)
    {
        return s.size();
    }
    vector<int> dp(s.size() + 1,0);
    //不管字符串长度为多少至少有一种解码方法
    dp[0] = 1;
    //如果第一个字符为‘0’则不能解码
    dp[1] = (s[0] == '0'? 0 : 1);
    for(int i = 2; i <= s.size(); i++)
    {
        //如果字符串的第i-1为和第i位能组成一个10到26的数字，
        //说明我们可以在第i-2位的解码方法上继续解码
        if((s[i -2] == '1')||(s[i - 2] == '2'&& s[i - 1] <'7'))
        {
            dp[i] += dp[i -2];
        }
        //如果字符串的第i-1位和第i位不能组成有效的两位数
        //那么在第i-1位的解码方法上继续解码
        if(s[i - 1] != '0')
        {
            dp[i] += dp[i - 1];
        }
    }
    return dp.back();
}
int main()
{
    cout<< numDecodings("1212") <<endl;
}
