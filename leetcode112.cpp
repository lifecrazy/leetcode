/*************************************************************************
	> File Name: leetcode112.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Sep 2016 01:09:18 AM PDT
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool dfs(TreeNode* root ,int sum ,int cur)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return cur + root->val == sum;
    }
    return dfs(root->left,sum,cur + root->val)||dfs(root->right,sum,cur + root->val);
}
bool hasPathSum(TreeNode* root, int sum) {
    return dfs(root, sum,0);
}
int main()
{
    TreeNode* root = new TreeNode(5);
    TreeNode* left = new TreeNode(4);
    TreeNode* first = new TreeNode(11);
    TreeNode* sec = new TreeNode(7);
    TreeNode* third = new TreeNode(2);
    TreeNode* forth = new TreeNode(8);
    TreeNode* five = new TreeNode(13);
    TreeNode* six = new TreeNode(4);
    TreeNode* seven = new TreeNode(1);
    root->left = left;
    left->left = first;
    first->left = sec;
    first->right = third;
    root->right = forth;
    forth->left = five;
    forth->right = six;
    six->right = seven;
    cout << hasPathSum(root,22)<<endl;


}
