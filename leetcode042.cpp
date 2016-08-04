/*************************************************************************
	> File Name: leetcode042.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 04 Aug 2016 01:47:30 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
    int sum = 0 ;
    int max = 0;
    int maxIndex = 0;
    for(int i = 0 ; i < height.size(); i++)
    {
        sum += height[i];
        if(height[i] > max)
        {
            max = height[i];
            maxIndex = i;
        }
    }
    int width = 0;
    int sumall = 0;
    max = height[0];
    int tempheight = height[0];
    for(int i = 0 ; i <= maxIndex; i++)
    {
        if(height[i]>max)
        {
            max = height[i];
            sumall += tempheight * width;
            tempheight = height[i];
            width = 0;
        }
        width++;
    }
    width = 0;
    max = height[height.size() - 1];
    tempheight = height[height.size() -1];
    for(int i = height.size() - 1 ; i >= maxIndex;i--)
    {
         if(height[i]>max)
        {
            max = height[i];
            sumall += tempheight * width;
            tempheight = height[i];
            width = 0;
        }
        width++; 
    }
    sumall = sumall + height[maxIndex];
    return sumall -sum;
}
int main()
{
    //0,1,0,2,1,0,1,3,2,1,2,1
    vector<int> data;
    data.push_back(0);
    data.push_back(1);
    data.push_back(0);
    data.push_back(2);
    data.push_back(1);
    data.push_back(0);
    data.push_back(1);
    data.push_back(3);
    data.push_back(2);
    data.push_back(1);
    data.push_back(2);
    data.push_back(1);
    cout << trap(data)<< endl;
}
