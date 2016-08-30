/*************************************************************************
> File Name: leetcode049.cpp
> Author: 
> Mail: 
> Created Time: Mon 29 Aug 2016 12:38:14 AM PDT
************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    string s;
    map<string,vector<string> > anagram;
    vector<vector<string> > res;
    for(int i = 0 ; i < strs.size(); i++)
    {
        s = strs[i];
        sort(s.begin(),s.end());
        if(anagram.find(s) == anagram.end())
        {
            vector<string> temp_vec;
            temp_vec.push_back(strs[i]);
            anagram[s] = temp_vec;
        }
        else
        {
            anagram[s].push_back(strs[i]);
        }
    }
    for(map<string,vector<string> >::iterator it = anagram.begin();it != anagram.end(); ++it)
    {
        res.push_back(it->second);
    }
    return res;
}
int main()
{
    vector<string> data;
    data.push_back("eat");
    data.push_back("tea");
    data.push_back("tan");
    data.push_back("ate");
    data.push_back("nat");
    data.push_back("bat");
    vector<vector<string> > result = groupAnagrams(data);
    for(int i = 0 ; i < result.size(); i++)
    {
        for(int j = 0 ; j < result[i].size();j++)
        {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }

}
