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
    int max = INT_MIN;
    for(int i = 0; i < s.size();i++)
    {
        if(s[i] > max)
        {
            max = s[i];
        }
    }
    int result = 0 ;
    sort(g.begin(),g.end());
    for(int i = 0 ; i < g.size();i++)
    {
        if(g[i] <= max)
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
    g.push_back(1);
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    cout << findContentChildren(s,g) << endl;
}
