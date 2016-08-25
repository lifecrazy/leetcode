/*************************************************************************
	> File Name: leetcode067.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Aug 2016 07:55:32 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
string addBinary(string a, string b) {
    int len_a = a.length();
    int len_b = b.length();
    if(len_a <= 0)
        return b;
    if(len_b <= 0)
        return a;
    int carry = 0;
    int max = len_a > len_b? len_a:len_b;
    vector<int> result;
    int temp = 0;
    for(int i = max - 1 ; i >= 0; i--)
    {
        if(max == len_a)
        {
            if(i - (len_a - len_b) >= 0)
                temp =(a[i] - '0') + (b[i - (len_a- len_b)] - '0') + carry;
            else
                temp =(a[i] - '0') + carry;
            carry = temp / 2;
            result.push_back(temp % 2);
        }
        else
        {
             if(i - (len_b - len_a) >= 0)
                temp =(a[i - (len_b -len_a)] - '0') + (b[i] - '0') + carry;
            else
                temp =(b[i] - '0') + carry;
            carry = temp / 2;
            result.push_back(temp % 2);
        }
    }
    if(carry == 1)
    {
        result.push_back(carry);
    }
    string num;
    for(int i =result.size()-1;i >= 0; i--)
    {
        num += (result[i] +'0');
    }
    return num;
}
int main()
{
    string num1 = "11";
    string num2 = "1";
    cout << addBinary(num1,num2) << endl;
    cout << addBinary("11","11111") << endl;
    cout << addBinary("111","100") << endl;
}
