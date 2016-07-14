/*************************************************************************
> File Name: leetcode118.cpp
> Author: 
> Mail: 
> Created Time: Wed 13 Jul 2016 05:46:26 PM PDT
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//思路：1.确定边界问题，当numRows = 1 ,2 时候的情况
//      2.确定计算公式 A[i][j] = A[i - 1][j - 1] + A[i - 1][j]
vector< vector<int> > generate(int numRows) {
    vector<vector<int> > result;
    vector<int> firstRow;
    firstRow.push_back(1);
    if(numRows == 1)
    {
        result.push_back(firstRow);
        return result;
    }
    vector<int> secRow;
    secRow.push_back(1);
    secRow.push_back(1);
    if(numRows == 2)
    {
        result.push_back(firstRow);
        result.push_back(secRow);
        return result;
    }
    result.push_back(firstRow);
    result.push_back(secRow);
    int i = 2;
    int j = 1;
    while(i < numRows)
    {
        vector<int> row ;
        row.push_back(1);
        while(j < i)
        {
            row.push_back( result[i-1][j-1] + result[i-1][j]);
            j++;
        }
        row.push_back(1);
        result.push_back(row);
        i++;
        j = 1;
    }
    for(int m = 0; m < result.size();m++)
    {
        for(int n = 0 ; n <result[m].size();n++)
        {
            cout << result[m][n] << "\t";
        }
        cout << endl;
    }
    return result;
}
int main()
{
    generate(6);
}
