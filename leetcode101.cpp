/*************************************************************************
	> File Name: leetcode101.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 12 Sep 2016 06:45:26 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode* left,TreeNode* right) {
    if(left != NULL && right != NULL)
    {
        return true;
    }
    if(left != NULL || right != NULL)
    {
        return false;
    }
    return left->val == right->val && isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
}
bool isSymmetric(TreeNode* root) {
    return root ==NULL ? true: isSymmetric(root->left,root->right);
}
int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(2);
    root->left = left;
    root->right = right;
    cout << isSymmetric(root) << endl;
}
