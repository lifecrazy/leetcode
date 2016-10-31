/*************************************************************************
	> File Name: leetcode441.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Oct 2016 10:44:42 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

int arrangeCoins(int n) {
    int result = 0;
    while(result < n)
    {
        result++;
        /*for(int i = 0;i < result; i++)
        {
            cout << '*';
        }
        cout << endl;*/
        n -= result;
    }
    return result;
}
int main()
{
    cout << arrangeCoins(5) << endl;
    cout << arrangeCoins(6) << endl;
    cout << arrangeCoins(8) << endl;
    cout << arrangeCoins(50) << endl;
}
