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
    string::size_type i = 0;
    while(string::npos !=(i = s.find(' ',i+1)))
    {
        result++;
    }
    return result;
}
int main()
{
    string s = "Hello, my name is John";
    cout << countSegments(s) << endl;
}
