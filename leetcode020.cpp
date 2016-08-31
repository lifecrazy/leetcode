/*************************************************************************
> File Name: leetcode020.cpp
> Author: 
> Mail: 
> Created Time: Tue 30 Aug 2016 07:45:19 PM PDT
************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isValid(string s) {
    string left ="({[";
    string right = ")}]";
    vector<char> stk;
    bool flag = false;
    int i = 0;
    for(; i < s.length();i++)
    {
        if(left.find(s[i]) != std::string::npos)
        {
            stk.push_back(s[i]);
        }
        else if(right.find(s[i]) != std::string::npos)
        {
            int temp = right.find(s[i]);
            if(stk.size() > 0 )
            {
                if(stk[stk.size() - 1] != left[temp])
                {
                    flag = false;
                    break;
                }
                else
                {
                    stk.erase(stk.end()-1);
                }
            }
            else
            {
                flag = false;
                break;
            }
        }
        else
        {
            flag = false;
            break;
        }
    }
    if(stk.size() == 0 && i == s.length())
    {
        flag = true;
    }
    return flag;
}
int main()
{
    cout << isValid("{}][}}{[))){}{}){(}]))})[({")<<endl;
    cout << isValid("(){}[]")<<endl;
    cout << isValid("(")<<endl;
    cout << isValid("}")<<endl;
    cout << isValid("(){}[")<<endl;
    cout << isValid("(){}[]}")<<endl;
    cout << isValid("({})[]")<<endl;
    cout << isValid("({)}[]")<<endl;
}
