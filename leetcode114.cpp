/*************************************************************************
	> File Name: leetcode114.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 11 Sep 2016 06:14:10 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//层次遍历展示每层的结点
void showAccordingthelevel(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        queue<TreeNode*> temp;
        while(!q.empty())
        {
            TreeNode* tempNode = q.front();
            cout << tempNode->val <<'\t';
            q.pop();
            if(tempNode->left != NULL)
                temp.push(tempNode->left);
            if(tempNode->right != NULL)
                temp.push(tempNode->right);
        }
        cout << endl;
        q = temp;
    }
}
//方法一 借用队列 开辟o(n)空间辅助
void flatten(TreeNode* root) {
    if(root == NULL)
    {
        return;
    }
    stack<TreeNode*> s;
    queue<TreeNode*> q;
    TreeNode* pCur = root;
    while(pCur != NULL || !s.empty())
    {
        if(pCur != NULL)
        {
            s.push(pCur);
            q.push(pCur);
            pCur = pCur->left;
        }
        else
        {
            pCur = s.top();
            s.pop();
            pCur = pCur->right;
        }
    }
    pCur = q.front();
    q.pop();
    while(!q.empty())
    {
        pCur->left = NULL;
        pCur->right = q.front();
        pCur = pCur->right;
        q.pop();
    }
}
//方法二：
void flatten_2(TreeNode* root)
{
     if(root == NULL)
    {
        return;
    }
    while(root != NULL)
    {
        if(root->left)
        {
            TreeNode* pPre = root->left;
            while(pPre->right != NULL)
            {
                pPre = pPre->right;
            }
            pPre->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
}
int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* sec = new TreeNode(2);
    TreeNode* third = new TreeNode(3);
    TreeNode* forth = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    TreeNode* six = new TreeNode(6);
    root->left = sec;
    root->right = five;
    sec->left = third;
    sec->right = forth;
    five->right = six;
    flatten;
    showAccordingthelevel(root);
    flatten_2(root);
    showAccordingthelevel(root);
}

