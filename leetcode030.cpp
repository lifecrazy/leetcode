/*************************************************************************
	> File Name: leetcode030.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Dec 2016 07:13:49 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
    if(s.size() <= 0 || words.size() <= 0)
    {
        return result;
    }
    if(s.size() < words.size() * words[0].size())
    {
        return result;
    }
    vector<pair<string,int> > words_map;
    for(int i = 0 ; i < words.size();i++)
    {
        words_map.push_back(make_pair(words[i],0));
    }
    int wordlen = words[0].size();
    for(int i = 0 ; i <= s.size() - wordlen * words.size(); i++)
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
            for(int k = 0; k < words_map.size(); k++)
            {
                if(temp == words_map[k].first && words_map[k].second == 0)
                {
                    flag = 1;
                    words_map[k].second = 1;
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
            int k = 0;
            for(; k < words_map.size();k++)
            {
                if(words_map[k].second != 1)
                {
                    break;
                }
            }
            if(k == words_map.size())
            {
                result.push_back(i);
                i +=  wordlen;
                i--;
            }
        }
        else if(j != 0)
        {
            i += wordlen;
            i--;
        }
        for(int k = 0 ;k < words_map.size(); k++)
        {
            words_map[k].second = 0;
        }
    }
    return result;
}
int main()
{
    //string s = "barfoothefoobarman";
    //string s = "barfoofoobarthefoobarman";
    string s = "wordgoodgoodgoodbestword";
    vector<string> words;
    /*words.push_back("foo");
    words.push_back("bar");
    words.push_back("the");*/
    words.push_back("word");
    words.push_back("good");
    words.push_back("best");
    words.push_back("good");
    vector<int> result = findSubstring(s,words);
    for(int i = 0 ;i < result.size(); i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl;
}
