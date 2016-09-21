/*************************************************************************
	> File Name: leetcode129.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 13 Jul 2016 08:04:40 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void dfs(TreeNode* root ,int& cur,int& result)
{
    if(root == NULL)
    {
        return ;
    }
    if(root->left == NULL && root->right == NULL)
    {
        result  += (cur * 10 + root->val);
        return;
    }
    cur = cur * 10 + root->val;
    dfs(root->left,cur,result);
    dfs(root->right,cur,result);
    cur = cur / 10;
}
int sumNumbers(TreeNode* root) {
    int cur = 0;
    int result = 0;
    dfs(root,cur,result);
    return result;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);
    TreeNode* leftleft = new TreeNode(2);
    root->left = left;
    root->right = right;
    left->left = leftleft;
    cout << sumNumbers(root) <<endl;
}