/*************************************************************************
	> File Name: leetcode476.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Jan 2017 05:18:32 PM PST
 ************************************************************************/

#include<iostream>
using namespace std;
int findComplement(int num) {
    //从高位开始遍历发现第一个为1的位置为止
    int i = 31;
    while(1!=(num>>i & 0x1))
    {
        i--;
    }
    int len = i;
    int result = 0;
    int temp;
    //继续开始遍历如果为0则取反，最后计算计算结果
    while(i >= 0)
    {
        if(1 != (num >> i & 0x1))
        {
            temp = 1;
            for(int k = 0;k < i; k++)
            {
                temp *= 2;
            }
            result += temp;
        }
        i--;
    }
    return result;
}

int main()
{
    cout << findComplement(9) << endl;
    cout << findComplement(5) << endl;

}
