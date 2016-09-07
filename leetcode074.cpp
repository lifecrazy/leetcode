/*************************************************************************
	> File Name: leetcode074.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 06 Sep 2016 06:00:33 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    if(matrix.size() <= 0)
    {
        return false;
    }
    int i = matrix.size() -1;
    int j = 0;
    while(i >= 0 && j <matrix[0].size())
    {
        if(target > matrix[i][j])
        {
            j++;
        }
        else if(target < matrix[i][j])
        {
            i--;
        }
        else
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<vector<int> > matrix;
    vector<int> first;
    first.push_back(1);
    first.push_back(3);
    first.push_back(5);
    first.push_back(7);
    vector<int> sec;
    sec.push_back(10);
    sec.push_back(11);
    sec.push_back(16);
    sec.push_back(20);
    vector<int> third;
    third.push_back(23);
    third.push_back(30);
    third.push_back(34);
    third.push_back(50);
    matrix.push_back(first);
    matrix.push_back(sec);
    matrix.push_back(third);
    for(int i = 0 ;i < matrix.size();i++)
    {
        for(int j = 0 ;j < matrix[0].size();j++)
        {
            cout << matrix[i][j] << '\t';
        }
        cout <<endl;
    }
    cout << searchMatrix(matrix,34) << endl;
    cout << searchMatrix(matrix,100) << endl;
}
