/*************************************************************************
	> File Name: leetcode009.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 21 Sep 2016 11:06:49 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0)
        return false;
    int i = x;
    int j = 0;
    while(i != 0)
    {
        j = j * 10 + (i % 10);
        i = i / 10;
    }
    return x == j;
}

int main()
{
    cout << isPalindrome(131)<<endl;
    cout << isPalindrome(21)<<endl;
}
