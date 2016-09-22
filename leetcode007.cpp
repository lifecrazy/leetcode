/*************************************************************************
	> File Name: leetcode007.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 21 Sep 2016 10:35:54 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

int reverse(int x) {
    int flag = 1;
    if(x < 0)
    {
        x = 0 - x;
        flag = -1;
    }
    int result = 0;
    while(x != 0)
    {
        result = result * 10 +(x % 10);
        x = x /10;
    }
    return result * flag;
}
int main()
{
    cout << reverse(321) << endl;
    cout << reverse(-321) << endl;
}
