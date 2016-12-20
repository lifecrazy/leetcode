/*************************************************************************
	> File Name: leetcode030.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Dec 2016 07:13:49 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if(s.size() <= 0 || words.size() <= 0)
    {
        return result;
    }
    map<string,int> words_map;
    for(int i = 0 ; i < words.size();i++)
    {
        words_map.insert(make_pair(words[i],0));
    }
    map<string,int>::iterator iter;
    int wordlen = words[0].size();
    for(int i = 0 ; i < s.size() - wordlen * words.size(); i++)
    {
        //按照wordlen的大小截取words.size()个字符串进行比较
        //如果能够覆盖整个words数组则符合要求
        int j = 0;
        string temp;
        int flag = 0;
        //如果当前截取的字符串在words中不能找到则跳出下面的循环
        while(j < words.size())
        {
            flag = 0;
            temp = s.substr(i + j * wordlen,wordlen);
            for(iter = words_map.begin();iter != words_map.end();iter++)
            {
                if(temp == iter->first && iter->second == 0)
                {
                    flag = 1;
                    iter->second = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                break;
            }
            j++;
        }
        if(j == words.size())
        {
            for(iter = words_map.begin();iter != words_map.end();iter++)
            {
                if(iter->second != 1)
                {
                    break;
                }
            }
            if(iter == words_map.end())
            {
                result.push_back(i);
                i += words.size() * wordlen;
                i--;
            }
        }
        for(iter = words_map.begin();iter != words_map.end();iter++)
        {
            iter->second = 0;
        }
    }
    return result;
}
int main()
{
    string s = "barfoothefoobarman";
    vector<string> words;
    words.push_back("foo");
    words.push_back("bar");
    vector<int> result = findSubstring(s,words);
    for(int i = 0 ;i < result.size(); i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl;
}
