/*************************************************************************
	> File Name: leetcode386.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Sep 2016 11:28:15 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
vector<int> lexicalOrder(int n) {
    vector<int> result;
    int base = 10;
    if(n <= 9)
    {
        for(int i = 0 ; i < n ;i++)
        {
            result.push_back(i + 1);
        }
        return result;
    }
    for(int i = 1;i <= 9 ; i++)
    {
        result.push_back(i);
        if(n >= i * 10)
        {
            while(base <= n)
            {
                if(n > (i+1)* base)
                {
                    for(int j = base * i;j < (i+1)*base;j++)
                        result.push_back(j);    
                }
                else
                {
                    for(int j = base * i ;j <= n;j++)
                        result.push_back(j);
                }
                base = base * 10;
            }
            base = 10;
        }
    }
    return result;
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
