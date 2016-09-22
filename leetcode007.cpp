/*************************************************************************
	> File Name: leetcode007.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 21 Sep 2016 10:35:54 PM PDT
 ************************************************************************/

#include<iostream>
#include<climits>
using namespace std;

int reverse(int x) {
    long result = 0;
    while(x != 0)
    {
        result = result * 10 +(x % 10);
        if(result > INT_MAX || result < INT_MIN)
        {
            return 0;
        }
        x = x /10;
    }
    return result;
}
int main()
{
    cout << reverse(321) << endl;
    cout << reverse(-321) << endl;
    cout << reverse(1534236469) <<endl;
}
