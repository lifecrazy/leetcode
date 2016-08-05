/*************************************************************************
> File Name: leetcode48.cpp
> Author: 
> Mail: 
> Created Time: Thu 04 Aug 2016 06:43:23 PM PDT
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int> >& matrix) {
    int rowNum = matrix.size();
    int colNum = matrix[0].size();
    int temp =0;
    for(int i = 0 ; i < rowNum ;i++)
    {
        for(int j = 0; j < colNum - 1 - i ;j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[colNum - 1 - j][rowNum - 1 - i];
            matrix[colNum - 1 - j][rowNum - 1 - i] = temp;
        }
    }
    for(int i = 0 ; i < rowNum / 2 ; i++)
    {
        for(int j = 0 ; j < colNum ; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[rowNum - 1 - i][j];
            matrix[rowNum - 1 - i][j] = temp;
        }
    }
}

int main()
{
    vector<vector<int> > data;
    int num = 4;
    for(int i = 0;i < num ; i++)
    {
        vector<int> row;
        for(int j = 0; j < num ; j++)
        {
            row.push_back(i * num + j + 1);
        }
        data.push_back(row);
    }
    for(int i = 0 ; i < data.size(); i++)
    {
        for(int j = 0 ; j < data[0].size();j++)
        {
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
    rotate(data);
    for(int i = 0 ; i < data.size(); i++)
    {
        for(int j = 0 ; j < data[0].size();j++)
        {
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
}
