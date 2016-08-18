/*************************************************************************
	> File Name: leetcode070.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Aug 2016 06:56:51 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//折到达第n阶台阶的办法有f(n)
//到达第n阶台阶有两种办法从n-1台阶到走一步到达第n阶
//和从n-2台阶走两步直接到达第n阶
//那么到达第n阶台阶的办法有f(n) = f(n-1) + f(n-2)
int climbStairs(int n) {
    if(n < 3 )
    {
        return n;
    }
    vector<int> result;
    result.push_back(1);
    result.push_back(2);
    for(int i = 2 ; i < n;i++)
    {
        result[i] = result[i - 1] + result[i -2];
        result.push_back(result[i]);
    }
    return result[result.size() - 1];
}
int main()
{
    for(int i = 3; i < 10 ;i++)
    {
        cout <<"climbStairs"<< i <<" : "<< climbStairs(i) << endl;
    }
}
