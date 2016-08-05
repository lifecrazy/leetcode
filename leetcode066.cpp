/*************************************************************************
	> File Name: leetcode066.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 04 Aug 2016 08:01:54 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    for(int i = digits.size() - 1 ; i >=0 ; i--)
    {
        carry = carry + digits[i];
        digits[i] = carry % 10;
        carry = carry / 10;
        cout << "carry:" << carry << endl;
    }
    if(carry > 0)
    {
        digits.insert(digits.begin(),carry);
    }
    return digits;
}
int main()
{
    vector<int> data;
    data.push_back(9);
    data.push_back(3);
    for(int i = 0 ;i < data.size();i++)
    {
        cout << data[i] ;
    }
    cout << endl;
    vector<int> result = plusOne(data);
    for(int i = 0 ; i < result.size(); i++)
    {
        cout << result[i];
    }
    cout << endl;
}
