/*************************************************************************
	> File Name: leetcode017.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 12 Dec 2016 05:37:19 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
vector<string> letterCombinations(string digits) {
    vector<string> res;
    string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    res.push_back("");
    for (int i = 0; i < digits.size(); i++)
    {
        vector<string> tempres;
        string chars = charmap[digits[i] - '0'];
        for (int c = 0; c < chars.size();c++)
            for (int j = 0; j < res.size();j++)
                tempres.push_back(res[j]+chars[c]);
        res = tempres;        
    }
    return res;
}
int main()
{
    vector<string> result = letterCombinations("23");
    for(int i = 0; i < result.size();i++)
    {
        cout << result[i] << '\t';
    }
    cout << endl;
}
