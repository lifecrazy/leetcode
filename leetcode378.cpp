/*************************************************************************
	> File Name: leetcode378.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 26 Oct 2016 07:53:36 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//方法一：
int kthSmallest(vector<vector<int> >& matrix, int k) {
    int left = matrix[0][0];
    int right = matrix.back().back();
    while(left < right)
    {
        int mid = left +(right - left) /2; 
        int count = 0;
    for(int i = 0 ; i < matrix.size(); i++)
    {
        count += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin();
    }
        if(count < k) 
        {
            left = mid +1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}
//方法二
int Search_Less_Equal(vector<vector<int> >& matrix,int target)
{
    int num = matrix.size();
    int i = num - 1;
    int j = 0;
    int result = 0;
    while(i >= 0 && j < num)
    {
        if(matrix[i][j] <= target)
        {
            result += (i + 1);
            j++;
        }
        else
        {
            --i;
        }
    }
    return result;
}

int kthSmallest_2(vector<vector<int> >& matrix, int k) {
    int left = matrix[0][0];
    int right = matrix.back().back();
    while(left < right)
    {
        int mid = left +(right - left) / 2;
        int count = Search_Less_Equal(matrix,mid);
        if(count < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}
int main()
{
    //matrix = [
    //   [ 1,  5,  9 ],
    //   [10, 11, 13],
    //   [12, 13, 15] 
    //   ],
    //         k = 8,
    //  return 13.
    vector<vector<int> > matrix;
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(5);
    nums1.push_back(9);
    vector<int> nums2;
    nums2.push_back(10);
    nums2.push_back(11);
    nums2.push_back(13);
    vector<int> nums3;
    nums3.push_back(12);
    nums3.push_back(13);
    nums3.push_back(15);
    matrix.push_back(nums1);
    matrix.push_back(nums2);
    matrix.push_back(nums3);
    cout << kthSmallest(matrix,8) << endl;
    cout << kthSmallest_2(matrix,8) << endl;
}
