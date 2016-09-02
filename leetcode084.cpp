/*************************************************************************
> File Name: leetcode084.cpp
> Author: 
> Mail: 
> Created Time: Wed 31 Aug 2016 01:54:01 AM PDT
************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//方法一 穷举法
int largestRectangleArea(vector<int>& heights) 
{
    int max = 0 ;
    //穷举右边界
    for(int i = 0 ; i < heights.size();i++)
    {
        int area = 0;
        //穷举左边界
        for(int j = 0 ;j <= i;j++)
        {
            int min = heights[j];
            //寻找左右边界之间的最小值
            for(int k = j; k <= i;k++)
            {
                if(min > heights[k])
                {
                    min = heights[k];
                }
            }
            area = min *(i - j +1);
            if(area > max)
            {
                max = area;
            }
        }
    }
    return max;
}

int largestRectangleArea_2(vector<int>& heights) 
{
    int max = 0;
    //穷举左边界
    for(int i = 0 ; i < heights.size() ; i++)
    {
        //寻找右边界
        //当heights[i] > heights[i - 1]时候，选择heights[i]总会比
        //heights[i-1]大
        for(int j = i + 1; j < heights.size(); j++)
        {
            if(heights[j] < heights[j - 1])
            {
                i = j -1;
                break;
            }
            else
            {
                i = j;
            }
        }
        int min = heights[i];
        int area = 0;
        for(int j = i ; j >= 0 ;j--)
        {
            if(heights[j] < min)
            {
                min = heights[j];
            }
            area = min * (i - j + 1);
            if(max < area)
            {
                max = area;
            }
        }
    }
    return max;
}
int main()
{
    vector<int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);
    cout << largestRectangleArea(heights) << endl;
    cout << largestRectangleArea_2(heights) << endl;
}
