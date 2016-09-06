/*************************************************************************
	> File Name: leetcode075.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 05 Sep 2016 02:07:49 AM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

void sortColors(vector<int>& nums) {
    int i = -1;
    int j = -1;
    int k = -1;
    for(int n = 0; n < nums.size(); n++)
    {
        if(nums[n] == 0)
        {
            nums[++k] = 2;
            nums[++j] = 1;
            nums[++i] = 0;
        }
        else if(nums[n] == 1)
        {
            nums[++k] = 2;
            nums[++j] = 1;
        }
        else
        {
            nums[++k] = 2;
        }
    }
}
void sortColors_3(vector<int>& nums) {
    int left = 0;
    int right = nums.size() -1;
    int i = 0;
    while(i <= right)
    {
        if(nums[i] == 0)
        {
            int temp = nums[left];
            nums[left] = nums[i];
            nums[i] = temp;
            left++;
            i++;
        }
        else if(nums[i] == 1)
        {
            i++;
        }
        else
        {
            int temp = nums[right];
            nums[right] = nums[i];
            nums[i] = temp;
            right--;
        }
    }
}
void sortColors_2(vector<int>& nums) {
    int colors[3] = {0};
    for(int i = 0 ; i < nums.size();i++)
    {
        colors[nums[i]]++;
    }
    int index = 0;
    for(int i = 0 ; i < 3; i++)
    {
        for(int k = 0 ;k < colors[i];k++)
        {
            nums[index++] = i;
        }
    }
}
int main()
{
    srand(unsigned(time(0)));
    int num = 10;
    vector<int> data;
    for(int i = 0;i < num;i++)
    {
        int temp = rand()%3;
        cout << temp << '\t';
        data.push_back(temp);
    }
    cout << endl;
    sortColors(data);
    for(int i = 0 ; i < data.size();i++)
    {
        cout << data[i] << '\t';
    }
    cout << endl;
}
