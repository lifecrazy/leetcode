/*************************************************************************
	> File Name: leetcode095.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Sep 2016 08:19:17 PM PDT
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
vector<TreeNode*> generateTrees(int begin ,int end)
{
    vector<TreeNode*> res;
    if(begin > end)
    {
        res.push_back(NULL);
        return res;
    }
    for(int i = begin; i <= end; i++)
    {
        //以i为根节点的由左子树【begin,i-1】构成右子树由【i+1,end】构成
        //返回的不同二叉树的根节点有几种二叉树就返回几种根结点
        vector<TreeNode*> leftSubTree = generateTrees(begin,i - 1);
        vector<TreeNode*> rightSubTree = generateTrees(i + 1,end);
        for(int k = 0; k < leftSubTree.size();k++)
        {
            for(int j = 0; j < rightSubTree.size();j++)
            {
                TreeNode* node = new TreeNode(i);
                node->left = leftSubTree[k];
                node->right = rightSubTree[j];
                res.push_back(node);
            }
        }
    }
    return res;
}
vector<TreeNode*> generateTrees(int n) {
    if(n <= 0)
    {
        return generateTrees(1,0);
    }
    else
    {
        return generateTrees(1,n);
    }
}
void PreOrder(TreeNode* root)
{
    if(root != NULL)
    {
        cout << root->val << '\t';
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
int main()
{
    vector<TreeNode*> res = generateTrees(4);
    for(int i = 0 ; i < res.size();i++)
    {
        PreOrder(res[i]);
        cout << endl;
    }
}
