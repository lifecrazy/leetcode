/*************************************************************************
	> File Name: leetcode387.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 09 Nov 2016 07:15:22 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int firstUniqChar(string s) {
    //下标表示字母 pair 第一个表示字母下标，第二个表示是否有重复
    vector<pair<int,int> > letter;
    for(int i = 0; i < 26; i++)
    {
        letter.push_back(make_pair(s.length(),-1));
    }
    for(int i = 0 ; i < s.length(); i++)
    {
        if(letter[s[i] - 'a'].first <s.length())
        {
            //标记重复出现的字母
            letter[s[i] - 'a'].second = 1;
        }
        else
        {
            //记录第一个出现的字符的下标
            letter[s[i] - 'a'].first = i;
        }
    }
    int min = s.length();
    for(int i = 0; i < 26; i++)
    {
        cout << (char)('a'+i) <<"==="<< letter[i].first <<"==="<< letter[i].second <<endl;
        if(letter[i].second == -1 && letter[i].first < min)
        {
            min = letter[i].first;
        }
    }
    if(min == s.length())
    {
        min = -1;
    }
    return min;
}
int main()
{
    string s = "leetcodecpp";
    cout << firstUniqChar(s) << endl;
    string s1= "loveleetcode";
    cout << firstUniqChar(s1)<< endl;
    cout << firstUniqChar("") << endl;
    cout << firstUniqChar("aa") << endl;
}
