/*************************************************************************
	> File Name: leetcode134.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Aug 2016 12:56:16 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    if(gas.size() <= 0 || cost.size() <= 0 || gas.size() != cost.size())
    {
        return -1;
    }
    int start = 0;
    int sum = 0;
    int total = 0;
    for(int i = 0 ; i < gas.size();i++)
    {
        total += (gas[i] - cost[i]);
        if(sum < 0)
        {
            sum = (gas[i] -cost[i]);
            start = i;
        }
        else
        {
            sum += (gas[i] - cost[i]);
        }
    }
    return total < 0 ? -1:start;
}
int main()
{
    srand(time(NULL));
    int n = 10 ;
    vector<int> gas;
    vector<int> cost;
    for(int i = 0 ;i < n ; i++)
    {
        gas.push_back(rand()%100);
        cost.push_back(rand()%100);
    }
    cout << "gas:" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout << gas[i] << "\t";
    }
    cout <<endl;
    cout << "cost:" << endl;
    for(int i = 0; i < n ; i++)
    {
        cout << cost[i] << "\t";
    }
    cout << endl;
    cout <<canCompleteCircuit(gas,cost)<<endl;
}
