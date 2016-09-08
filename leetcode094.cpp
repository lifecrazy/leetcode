/*************************************************************************
	> File Name: leetcode094.cpp
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
void Inorder(TreeNode* root)
{
    if(root != NULL)
    {
        Inorder(root->left);
        result.push_back(root->val);
        Inorder(root->right);
    }
}
vector<int> InorderTraversal(TreeNode* root) {
    Inorder(root);
    return result;
}

vector<int> InorderTraversal_2(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while(p != NULL || !s.empty())
    {
        if(p != NULL)
        {
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            res.push_back(p->val);
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
    vector<int> result = InorderTraversal(root);
    for(int i = 0 ; i < result.size();i++)
    {
        cout << result[i] << '\t';
    }
    cout << endl;
    result = InorderTraversal_2(root);
    for(int i = 0 ; i < result.size();i++)
    {
        cout << result[i] << '\t';
    }
    cout << endl;
}
