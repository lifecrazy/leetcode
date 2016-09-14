/*************************************************************************
	> File Name: leetcode096.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Sep 2016 07:16:28 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//思路：n个点中每个点都可以作为root，
//当 i 作为root时，
//小于 i  的点都只能放在其左子树中，
//大于 i 的点只能放在右子树中，
//此时只需求出左、右子树各有多少种，
//二者相乘即为以 i 作为root时BST的总数。
int numTrees(int n) {
    vector<int> result;
    result.push_back(1);
    for(int i = 1 ; i <= n ; i++)
    {
        result.push_back(0);
        if(i < 3)
        {
            result[i] = i;
        }
        else
        {
            for(int k = 1; k <= i;k++)
            {
                result[i] += result[k-1] * result[i-k];
            }
        }
    }
    return result[n];
}
int main()
{
    for(int i = 0 ; i < 11; i++)
    {
        cout << "当 i= "<< i << "时，result:" << numTrees(i) <<endl;
    }
}
