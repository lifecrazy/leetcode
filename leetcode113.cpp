/*************************************************************************
	> File Name: leetcode113.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Sep 2016 01:09:18 AM PDT
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
void dfs(TreeNode* root ,int sum ,int cur,vector<int>& curPath,vector<vector<int> >& result)
{
    if(root == NULL)
    {
        return ;
    }

    if(root->left == NULL && root->right == NULL)
    {
        if(cur + root->val == sum)
        {
            curPath.push_back(root->val);
            result.push_back(curPath);
            curPath.pop_back();
        }
        return;
    }
    curPath.push_back(root->val);
    dfs(root->left,sum,cur + root->val,curPath,result);
    dfs(root->right,sum,cur + root->val,curPath,result);
    curPath.pop_back();
}

vector<vector<int> > pathSum(TreeNode* root, int sum) {
    vector<int> curPath;
    vector<vector<int> > result;
    dfs(root,sum,0,curPath,result);
    return result;
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
    TreeNode* eight = new TreeNode(5);
    root->left = left;
    left->left = first;
    first->left = sec;
    first->right = third;
    root->right = forth;
    forth->left = five;
    forth->right = six;
    six->right = seven;
    six->left = eight;
    vector<vector<int> > result = pathSum(root,22);
    for(int i = 0 ; i < result.size();i++)
    {
        for(int j = 0; j <result[i].size();j++)
        {
            cout << result[i][j] << '\t';
        }
        cout << endl;
    }


}
