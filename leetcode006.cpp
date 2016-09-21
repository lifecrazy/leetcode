/*************************************************************************
> File Name: leetcode006.cpp
> Author: 
> Mail: 
> Created Time: Wed 21 Sep 2016 12:12:08 AM PDT
************************************************************************/

#include<iostream>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1 || s.length() <= numRows)
    return s;
    string result = "";
    for(int i = 0 ; i < numRows;i++)
    {
        int j = i;
        int step = numRows + numRows - 2;
        int k = step - i;
        while(j < s.length() )
        {
            result +=s[j];
            j += step;
            if(!(i == 0 || i == numRows - 1))
            {
                if(k < s.length())
                {
                    result +=s[k];
                    k += step;
                }
            }
        }
    }
    return result;
}
int main()
{
    cout << convert("PAYPALISHIRING", 3) <<endl;
    cout << convert("P", 1) <<endl;
    cout << convert("abcdefghijkl", 4) <<endl;
    cout << convert("abcde", 4) <<endl;
}
