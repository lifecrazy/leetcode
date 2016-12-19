/*************************************************************************
	> File Name: leetcode461.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Dec 2016 05:04:43 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;

int hammingDistance(int x, int y) {
    int tmp = x^y;
    cout << tmp << endl;
    int result = 0 ;
    for (int i = 0; i < 32;i++)
    {
        int x = tmp >> i & 0x1;
        if(1 == x)
        {
            result++;
        }
    }
    return result;
}
int main()
{
    cout << hammingDistance(1,4) <<endl;
}
