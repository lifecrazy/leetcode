/*************************************************************************
	> File Name: leetcode042.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 04 Aug 2016 01:47:30 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//方法一：
//每当下一个高度比前一个高度高时，就计算一次高度差即为当前位置能够存储的水的总量
//然后将所有的位置的水量相加即的最后的结果
int trap(vector<int>& height) {
    int result = 0 ;
    int max = 0;
    for(int i = 0 ; i < height.size(); i++)
    {
        if(height[i] > height[max])
        {
            max = i;
        }
    }
    int top = 0 ;
    for(int i = 0 ; i < max; i++)
    {
        if(height[i] > top)
        {
            top = height[i];
        }
        else
        {
            result += (top - height[i]);
        }
    }
    top = 0 ;
    for(int i = height.size() - 1 ; i > max; i-- )
    {
        if(height[i] > top)
        {
            top = height[i];
        }
        else
        {
            result += (top - height[i]);
        }
    }
    return result;
}
//方法二：
//计算所有突出的面积，然后减去高度的和
int trap_2(vector<int>& height) {
    int result = 0 ;
    int max = 0;
    int totalHeight = 0;
    for(int i = 0 ; i < height.size(); i++)
    {
        totalHeight += height[i];
        if(height[i] > height[max])
        {
            max = i;
        }
    }
    int width = 0;
    int top = height[0] ;
    for(int i = 0 ; i < max; i++)
    {
        if(height[i] > top)
        {
            result += top * width;
            top = height[i];
            width = 1;
        }
        else
        {
            width++;
        }
    }
    if(width > 1)
    {
        result += top * width;
    }
    width = 0;
    top = height[height.size() - 1];
    for(int i = height.size() - 1 ; i > max; i-- )
    {
        if(height[i] > top)
        {
            result += top * width;
            top = height[i];
            width = 1;
        }
        else
        {
            width++;
        }
    }
    if(width > 1)
    {
        result += top * width;
    }
    result = result - totalHeight + height[max];
    return result;
}
int main()
{
    //0,1,0,2,1,0,1,3,2,1,2,1
    vector<int> data;
/*    data.push_back(0);
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
    data.push_back(1);*/
    data.push_back(2);
    data.push_back(0);
    data.push_back(2);
    cout << trap(data)<< endl;
    cout << trap_2(data) << endl;
}
