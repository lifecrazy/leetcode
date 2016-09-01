/*************************************************************************
	> File Name: leetcode150.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 01 Sep 2016 12:09:29 AM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int evalRPN(vector<string>& tokens) {
    if(tokens.size()<=0)
    {
        return 0;
    }
    vector<int> data;
    for(int i = 0 ; i < tokens.size();i++)
    {
        int temp = 0 ;
        if(tokens[i] == "+")
        {
            temp = data[data.size()-1] + data[data.size()-2];
            data.erase(data.end()-1);
            data.erase(data.end()-1);
            data.push_back(temp);
        }
        else if(tokens[i] == "-")
        {
             temp = data[data.size()-2] - data[data.size()-1];
            data.erase(data.end()-1);
            data.erase(data.end()-1);
            data.push_back(temp);
        }
        else if(tokens[i] == "*")
        {
              temp = data[data.size()-1] * data[data.size()-2];
            data.erase(data.end()-1);
            data.erase(data.end()-1);
            data.push_back(temp);
        }
        else if(tokens[i] == "/")
        {
               temp = data[data.size()-2] / data[data.size()-1];
            data.erase(data.end()-1);
            data.erase(data.end()-1);
            data.push_back(temp);
        }
        else
        {
            data.push_back(atoi((tokens[i]).c_str()));
        }
    }
    return data[0];
}
int main()
{
    vector<string> data;
    data.push_back("2");
    data.push_back("1");
    data.push_back("+");
    data.push_back("3");
    data.push_back("*");
//    cout <<evalRPN(data)<<endl; 
    vector<string> data1;
    data1.push_back("4");
    data1.push_back("13");
    data1.push_back("5");
    data1.push_back("/");
    data1.push_back("+");
    cout <<evalRPN(data1)<<endl;
}
