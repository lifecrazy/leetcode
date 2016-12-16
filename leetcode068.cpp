/*************************************************************************
	> File Name: leetcode068.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 15 Dec 2016 07:12:32 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    if(words.size() <= 0 || maxWidth <= 0)
    {
        return result;
    }
    int len = 0;
    int nWords = 0;
    int lastWordIndex = 0;
    for(int i = 0;i < words.size();i++)
    {
        len += words[i].length();
        if(len < maxWidth && (maxWidth - len) > nWords)
        {
            //统计每行的单词数
            nWords++;
       /*     if(i == words.size() -1)
            {
                string line;
                while(lastWordIndex < words.size())
                {
                    line += words[lastWordIndex];
                }
                for(int j = 0;j < maxWidth - len;j++)
                {
                    line +=' ';
                }
                result.push_back(line);
            }
            continue;*/
        }
        else
        {
            len -= words[i].length();
            //计算总的空格数
            int spaceCount = maxWidth - len;
            //获取第一个间隔应该多放的空格数
            int spaceExtra = spaceCount % (nWords-1);
            //计算每个间隔的空格数量
            int spacePer = spaceCount /(nWords - 1);
            //添加每行第一个单词
            string line;
            line += words[lastWordIndex];
            lastWordIndex++;
            for(int j = 0; j < nWords -1 ; j++)
            {
                //设置每个间隔的空格的个数
                int spacePerLine = (j == 0 ? spacePer + spaceExtra : spacePer);
                for(int k = 0; k < spacePerLine; k++)
                {
                    line += ' ';
                }
                line += words[lastWordIndex];
                lastWordIndex++;
            }
            len = 0;
            i--;
            nWords = 0;
            result.push_back(line);
        }
        if(i == words.size() -1 && len <= maxWidth)
        {
            string line;
            while(lastWordIndex < words.size())
            {
                line += words[lastWordIndex];
                lastWordIndex++;
            }
            for(int j = 0;j < maxWidth - len;j++)
            {
                line +=' ';
            }
            result.push_back(line);
        }
    }
    return result;
}

int main()
{
    vector<string> data;
    data.push_back("this");
    data.push_back("is");
    data.push_back("an");
    data.push_back("example");
    data.push_back("of");
    data.push_back("text");
    data.push_back("justification.");
    vector<string> result = fullJustify(data,16);
    for(int i = 0 ;i < result.size();i++)
    {
        cout << result[i] << endl;
    }
}
