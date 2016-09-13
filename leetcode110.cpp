/*************************************************************************
> File Name: leetcode110.cpp
> Author: 
> Mail: 
> Created Time: Mon 12 Sep 2016 08:01:11 PM PDT
************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int height (TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        if(root->left == NULL)
        {
            return height(root->right) + 1;
        }
        else if(root->right == NULL)
        {
            return height(root->left) + 1;
        }
        else
        {
            int l = height(root->left);
            int r = height(root->right);
            return l < r ? (r + 1) : (l + 1);
        }
    }
}
bool isBalanced(TreeNode* root) {
    if(root == NULL)
    {
        return true;
    }
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        if(l - r <= 1 && l - r >= -1)
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }
        else
        {
            return false;
        }
    }
}
int main()
{
    TreeNode* first = new TreeNode(7);
    TreeNode* sec = new TreeNode(3);
    TreeNode* third = new TreeNode(10);
    first->left = sec;
    first->right = third;
    TreeNode* fourth = new TreeNode(1);
    TreeNode* five = new TreeNode(6);
    sec->left = fourth;
    sec->right = five;
    TreeNode* six = new TreeNode(4);
    TreeNode* seven = new TreeNode(8);
    five->left = six;
    five->right = seven;
    TreeNode* eight = new TreeNode(14);
    third->right = eight;
    TreeNode* nineth = new TreeNode(13);
    eight->left = nineth;
    cout << isBalanced(first) << endl;
}
