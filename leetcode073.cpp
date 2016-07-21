/*************************************************************************
> File Name: leetcode073.cpp
> Author: 
> Mail: 
> Created Time: Wed 20 Jul 2016 06:25:24 PM PDT
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//思路：记录值为0的行和列的值，然后遍历该行和该列将其赋值为0
void setZeroes(vector<vector<int> >& matrix) {
    vector<int> row;
    vector<int> col;
    for(int i = 0 ;i < matrix.size();i++)
    {
        for(int j = 0 ; j < matrix[i].size();j++)
        {
            if(0 == matrix[i][j])
            {
                row.push_back(i);
                col.push_back(j);
            }
        }
    }
    for(int i = 0; i < row.size();i++ )
    {
        for(int j = 0; j < matrix[i].size();j++)
        {
            matrix[row[i]][j] = 0;
        }
    }
    for(int i = 0; i < matrix.size();i++ )
    {
        for(int j = 0; j < col.size();j++)
        {
            matrix[i][col[j]] = 0;
        }
    }

}

int main()
{
    vector<vector<int> > data;
    int rowNum = 4;
    int colNum = 5;
    for(int i = 0 ; i < rowNum; i++)
    {
        vector<int > row;
        for(int k = 0 ; k < colNum ; k++)
        {
            row.push_back(i * colNum + k + 1);
        }
        data.push_back(row);
    }
    data[3][2] = 0;
    data[2][4] = 0;
    for(int i = 0 ; i < data.size();i++)
    {
        for(int j = 0 ; j <data[i].size();j++)
        {
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
    setZeroes(data);
    cout << "***********************************" << endl;
    for(int i = 0 ; i < data.size();i++)
    {
        for(int j = 0 ; j <data[i].size();j++)
        {
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
}
