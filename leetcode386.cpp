/*************************************************************************
> File Name: leetcode386.cpp
> Author: 
> Mail: 
> Created Time: Tue 13 Sep 2016 11:28:15 PM PDT
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
vector<int> ans;
void dfs(int cur, int n)
{
    if(cur > n)
        return;
    ans.push_back(cur);
    for(int i=0; i<=9; i++)
        if(cur * 10 + i <= n)
            dfs(cur * 10 + i, n);

}
vector<int> lexicalOrder(int n) {
    for(int i=1; i<=9; i++)
        dfs(i, n);
    return ans;
}

int main()
{
    vector<int> res = lexicalOrder(105);
    for(int i = 0 ; i < res.size();i++)
    {
        cout << res[i] <<'\t';
    }
    cout <<endl;

}
