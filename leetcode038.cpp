/*************************************************************************
	> File Name: leetcode38.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Aug 2016 06:26:10 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string countAndSay(int n) {
    if(n == 1)
    {
        return "1";
    }
    vector<int> result;
    result.push_back(1);
    for(int i = 1; i < n; i++)
    {
        int j = 0;
        int count = 0;
        int lastNum = result[0];
        vector<int> temp;
        while(j < result.size())
        {
            if(lastNum != result[j])
            {
                temp.push_back(count);
                temp.push_back(lastNum);
                count = 0;
            }
            lastNum = result[j];
            count++;
            j++;
        }
        temp.push_back(count);
        temp.push_back(lastNum);
        result.clear();
        result.swap(temp);
        temp.clear();
    }
    string s;
    for(int i = 0 ; i < result.size(); i++)
    {
        s += ('0'+ result[i]);
    }
    return s ;
}
int main()
{
   cout <<  countAndSay(2) << endl;

}
