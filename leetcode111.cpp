/*************************************************************************
	> File Name: leetcode111.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Sep 2016 12:43:15 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int minDepth(TreeNode* root) {
    if(root == NULL)
    {
        return 0;
    }
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if(l == 0)
    {
        return r + 1;
    }
    if(r == 0)
    {
        return l + 1;
    }
    return l > r ? r + 1:l + 1;
} 
int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* first = new TreeNode(1);
    TreeNode* sec = new TreeNode(1);
    TreeNode* third = new TreeNode(1);
    TreeNode* forth = new TreeNode(1);
    TreeNode* five = new TreeNode(1);
    TreeNode* six = new TreeNode(1);
    root->left = first;
    root->right = sec;
    sec->right = third;
    third->left = forth;
    forth->left = five;
    first->left = six;
    cout << minDepth(root) << endl;
}
