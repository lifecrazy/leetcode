/*************************************************************************
> File Name: leetcode069.cpp
> Author: 
> Mail: 
> Created Time: Wed 20 Jul 2016 07:54:21 PM PDT
************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;
//思路一：二分法
//先取x的一般计算x/2*x/2 如果大于x 向小的区间划分如果大于向大的区间划分
int mySqrt(int x) {
    if(x <= 1)
    return x;
    int low = 0;
    int high = x;
    int mid = -1;
    int temp = -1;
    while(low < high)
    {
        mid = (low + high) / 2;
        temp = mid* mid;
        if(temp > x)
        {
            high = mid;
        }
        else if(temp < x)
        {
            low = mid;
        }
        else{
            return mid;
        }
    }
    return mid;    
}
int mySqrt_2(int x)
{
    int result = x;
    int last;
    do
    {
        last = result;
        result = result + x /result;
    }while(abs(last - result) > eps);
    return result;
}
int main()
{
    cout <<"result:"<< mySqrt(64*64)<<endl;
    cout <<"result:"<< mySqrt_2(64*64)<<endl;
}
