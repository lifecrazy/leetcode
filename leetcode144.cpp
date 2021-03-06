/*************************************************************************
	> File Name: leetcode144.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 07 Sep 2016 06:50:11 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//方法一递归
vector<int> result;
void preorder(TreeNode* root)
{
    if(root != NULL)
    {
        result.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
}
vector<int> preorderTraversal(TreeNode* root) {
    preorder(root);
    return result;
}

vector<int> preorderTraversal_2(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while(p != NULL || !s.empty())
    {
        if(p != NULL)
        {
            s.push(p);
            res.push_back(p->val);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
    return res;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* first = new TreeNode(2);
    TreeNode* sec = new TreeNode(3);
    root->right = first;
    first->left = sec;
    vector<int> result = preorderTraversal(root);
    for(int i = 0 ; i < result.size();i++)
    {
        cout << result[i] << '\t';
    }
    cout << endl;
    result = preorderTraversal_2(root);
    for(int i = 0 ; i < result.size();i++)
    {
        cout << result[i] << '\t';
    }
    cout << endl;
}
