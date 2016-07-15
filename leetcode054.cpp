/*************************************************************************
	> File Name: leetcode054.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 14 Jul 2016 07:29:54 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    vector<int> result;
    int rownum = matrix.size();
    int colnum = matrix[0].size();
    for (int i = 0; i <rownum; i++)//列  
    {  
        for (int j = i; j <colnum-i; j++)//行  
        {  
            result.push_back(matrix[i][j]); 
        }  
        for (int j = i+1; j < rownum-i; j++)  
        {  
            result.push_back(matrix[j][colnum - i -1]);
        }  
        for (int j = colnum-i-2; j >=i; j--)  
        {
            result.push_back(matrix[rownum - i - 1][j]);
        }  
        for (int j = rownum - i - 2; j >i; j--)  
        {
            result.push_back(matrix[j][i]);  
        }  
    }
    return result;
}
int main()
{
    vector<vector<int> > data;
    int rownum = 4;
    int colnum = 5;
    for(int i = 0; i < rownum; i++)
    {
        vector<int> row;
        for(int j = i * rownum ;j < i*rownum + colnum;j++)
        {
            row.push_back(j);
        }
        data.push_back(row);
    }

    for(int i = 0 ; i < data.size();i++)
    {
        for(int j = 0 ; j < data[i].size();j++)
        {
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
    vector<int> result = spiralOrder(data);
    for(int i = 0 ; i < result.size();i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl;
}
