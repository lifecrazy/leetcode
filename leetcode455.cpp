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
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int i = 0 ;
    for(int j = 0; i < g.size() && j < s.size();j++)
    {
        if(g[i] <= s[j])
        {
            i++;
        }
    }
    return i;
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
