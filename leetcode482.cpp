/*************************************************************************
	> File Name: leetcode482.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 08 Jan 2017 07:25:38 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
string licenseKeyFormatting(string S, int K) {
    string result = "";
    vector<char> temp;
    for(int i = 0; i < S.length();i++)
    {
        if(S[i] != '-')
        {
            if(S[i] >= 'a' && S[i] <= 'z')
            {
                temp.push_back(S[i] - 'a' + 'A');
            }
            else
            {
                temp.push_back(S[i]);
            }
        }
    }
    int firstNum = temp.size() % K;
    int i = 0;
    while(i < firstNum)
    {
        result += temp[i];
        i++;
    }
    int j = 0;
    while(i < temp.size())
    {
        if(j % K == 0)
        {
            if(i != 0)
            {
                result += '-';
            }
        }
        result += temp[i];
        i++;
        j++;
    }
    return result;
}
int main()
{
    cout << licenseKeyFormatting("2-4A0r7-4k",4) << endl;
    cout << licenseKeyFormatting("2-4A0r7-4k",3) << endl;
}
