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
vector<int> lexicalOrder_2(int n) {
    for(int i=1; i<=9; i++)
        dfs(i, n);
    return ans;
}
//方法二
vector<int> lexicalOrder(int n) {
    vector<int> result(n);
    int index = 1;
    for(int i = 0; i < n; i++)
    {
        result[i] = index;
        if(index * 10 <= n)
        {
            index *= 10;
        }
        else
        {
            if(index >= n)
            {
                index /= 10;
            }
            index++;
            while(0 == index % 10)
            {
                index /= 10;
            }
        }
    }
    return result;
}
int main()
{
    vector<int> res = lexicalOrder(115);
    for(int i = 0 ; i < res.size();i++)
    {
        cout << res[i] <<'\t';
        if(i % 10 == 0)
        {
            cout << endl;
        }
    }
    cout <<endl;

}
