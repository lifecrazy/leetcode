/*************************************************************************
	> File Name: leetcode455.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 16 Nov 2016 06:03:47 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    int min = INT_MAX;
    for(int i = 0; i < s.size();i++)
    {
        if(s[i] > min)
        {
            min = s[i];
        }
    }
    int result = 0 ;
    sort(g.begin(),g.end());
    for(int i = 0 ; i < g.size();i++)
    {
        if(g[i] <= min)
        {
            result++;
        }
        else
        {
            break;
        }
    }
    return result;
}

int main()
{
    vector<int> g;
    g.push_back(1);
    g.push_back(2);
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    cout << findContentChildren(g,s) << endl;
}
