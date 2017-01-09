/*************************************************************************
	> File Name: leetcode481.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Jan 2017 05:34:29 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int magicalString(int n) {
    if(n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2|| n == 3 ) 
    {
        return 1;
    }
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(2);
    int result = 1;
    int j = 2;
    //如果当前temp的大小加上要添加进去的数字的个数超过了目标值
    //那么退出循环
    while (temp.size() < n)
    {
        if (j % 2 == 0)
        {
            if (temp[j] == 1)
            {
                temp.push_back(1);
                result++;
            }
            else
            {
                temp.push_back(1);
                result++;
                if(temp.size() < n)
                {
                    temp.push_back(1);
                    result++;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            if(temp[j] == 1)
            {
                temp.push_back(2);
            }
            else
            {
                temp.push_back(2);
                if(temp.size() < n)
                {
                    temp.push_back(2);
                } 
                else
                {
                    break;
                }
            }
        }
        j++;
    }
    for (int k = 0; k < temp.size(); k++)
    {
        cout << temp[k]; 
    }
    cout << endl;
    return result;
}
int main()
{
    cout << magicalString(4) << endl;
    cout << magicalString(6) << endl;
    cout << magicalString(5) << endl;
}
