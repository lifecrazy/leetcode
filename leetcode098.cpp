/*************************************************************************
> File Name: leetcode098.cpp
> Author: 
> Mail: 
> Created Time: Sat 17 Sep 2016 11:28:40 PM PDT
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
bool InorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* p = root;
    TreeNode* pre = NULL;
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
            if(pre != NULL && pre->val > p->val)
            {
                return false;
            }
            pre = p;
            p = p->right;
        }
    }
    return true;
}
bool isValidBST(TreeNode* root) {
    return InorderTraversal(root);
}

int main()
{
    TreeNode* left = new TreeNode(1);
    TreeNode* root = new TreeNode(2);
    TreeNode* right = new TreeNode(3);
    root->left =left;
    root->right = right;
    TreeNode* root1 = new TreeNode(1);
    TreeNode* left1 = new TreeNode(2);
    TreeNode* right1 = new TreeNode(3);
    root1->left = left1;
    root1->right = right1;
    cout << isValidBST(root) << endl;
    cout << isValidBST(root1) << endl;
}
