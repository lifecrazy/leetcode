/*************************************************************************
	> File Name: leetcode434.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 04 Dec 2016 11:23:35 PM PST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int countSegments(string s) {
   int result = 1;
	int i = 0;
	//去除最左端的空格
	while (s[i] == ' ')
	{
		i++;
	}
	//全是空格的处理
	if (i >= s.size())
	{
		return 0;
	}
	for (; i < s.size(); i++)
	{
		if (i + 1 < s.size() && s[i] == ' '&& s[i + 1] != ' ')
		{
			result++;
		}
	}
	return result;
}
int main()
{
    string s = "Hello, my name is John";
    cout << countSegments(s) << endl;
}
