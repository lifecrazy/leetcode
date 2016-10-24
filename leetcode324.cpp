/*************************************************************************
	> File Name: leetcode324.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 23 Oct 2016 06:40:01 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*void wiggleSort(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int temp = 0;
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        //当i为偶数的时候满足nums[i] < nums[i - 1]
        if(i % 2 == 0)
        {
            if(i - 1 >= 0)
            {
                //当num[i] > nums[i - 1] 只需要交换两者即可
                if(nums[i] > nums[i - 1])
                {
                    temp = nums[i];
                    nums[i] = nums[i - 1];
                    nums[i - 1] = temp;
                }
                //当nums[i] == nums[i + 1]时，需要向后寻找大于当前值的元素进行交换
                else if(nums[i] == nums[i - 1])
                {
                    int j = i - 1;
                    for(; j >= 0; j--)
                    {
                        if(nums[j] > nums[i - 1])
                        {
                            temp = nums[j];
                            nums[j] = nums[i - 1];
                            nums[i - 1] = temp;
                            break;
                        }
                    }
                }
                //当满足条件的时候不做处理
            }//当超过当前数组大小的时候也不进行处理
        }
        else//当i为奇数的时候满足nums[i] > nums[i - 1]
        {
            if(i - 1 >=0) //i + 1 不能超过数组的大小
            {
                 //当num[i] < nums[i + 1] 只需要交换两者即可
                if(nums[i] < nums[i - 1])
                {
                    temp = nums[i];
                    nums[i] = nums[i - 1];
                    nums[i - 1] = temp;
                }
                //当nums[i] == nums[i + 1]时，需要向后寻找大于当前值的元素进行交换
                else if(nums[i] == nums[i - 1])
                {
                    int j = i - 1;
                    for(; j >= 0; j--)
                    {
                        if(nums[j] < nums[i - 1])
                        {
                            temp = nums[j];
                            nums[j] = nums[i - 1];
                            nums[i - 1] = temp;
                            break;
                        }
                    }
                }
                //当满足条件的时候不做处理
            }//当超过当前数组大小的时候也不进行处理
        }
    }
}*/
void wiggleSort(vector<int>& nums) {
    vector<int> temp = nums;
    sort(temp.begin(),temp.end());
    int j = (nums.size() + 1)/ 2;
    int k = nums.size();
    for(int i = 0 ;i < nums.size();i++)
    {
        nums[i] = (i % 2 != 1) ? temp[--j]:temp[--k];
    }
}
int main()
{
    vector<int> data;
    data.push_back(1);
    data.push_back(3);
    data.push_back(2);
    data.push_back(2);
    data.push_back(3);
    data.push_back(1);
   /* vector<int> data;
    data.push_back(1);
    data.push_back(5);
    data.push_back(1);
    data.push_back(1);
    data.push_back(6);
    data.push_back(5);*/
    /*vector<int> data;
    data.push_back(4);
    data.push_back(5);
    data.push_back(5);
    data.push_back(6);*/
    cout << "------before sort ------" << endl;
    for(int i = 0 ; i < data.size(); i++)
    {
        cout << data[i] << '\t';
    }
    cout << endl;
    wiggleSort(data);
    cout <<"======after sort ======" << endl;
    for(int i = 0 ; i < data.size(); i++)
    {
        cout << data[i] << '\t';
    }
    cout << endl;
}
