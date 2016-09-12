/*************************************************************************
> File Name: leetcode099.cpp
> Author: 
> Mail: 
> Created Time: Mon 12 Sep 2016 12:09:58 AM PDT
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
void recoverTree(TreeNode* root) 
{
    if(root == NULL)
    {
        return;
    }
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* pCur = root;
    TreeNode* pPre = NULL;
    TreeNode* pMissfirst = NULL;
    TreeNode* pMissSec = NULL;
    bool firstMiss = false;
    while(pCur != NULL || !s.empty())
    {
        if(pCur != NULL)
        {
            s.push(pCur);
            pCur = pCur->left;
        }
        else
        {
            pCur = s.top();
            s.pop();
            if(pPre != NULL)
            {
                if(pCur->val < pPre->val)
                {
                    if(!firstMiss)
                    {
                        pMissfirst = pPre;
                        firstMiss = true;
                    }
                    pMissSec = pCur;
                }
            }
            pPre = pCur;
            pCur = pCur->right;
        }
    }
    int temp = pMissfirst->val;
    pMissfirst->val = pMissSec->val;
    pMissSec->val = temp;
}
void showTree(TreeNode* root)
{
    TreeNode* pCur = root;
    stack<TreeNode*> s;
    while(pCur != NULL || !s.empty())
    {
        if(pCur != NULL)
        {
            s.push(pCur);
            pCur = pCur->left;
        }
        else
        {
            pCur = s.top();
            s.pop();
            cout << pCur->val << '\t';
            pCur = pCur->right;
        }
    }
    cout <<endl;
}
int main()
{
    /*
    *              8
    *        3          10 
    *     1      6           14
    *         4     7    13
    * 中序遍历：1 3 4 6 7 8 10  13   14 
    * */
    TreeNode* first = new TreeNode(8);
    TreeNode* sec = new TreeNode(13);
    TreeNode* third = new TreeNode(10);
    first->left = sec;
    first->right = third;
    TreeNode* fourth = new TreeNode(1);
    TreeNode* five = new TreeNode(6);
    sec->left = fourth;
    sec->right = five;
    TreeNode* six = new TreeNode(4);
    TreeNode* seven = new TreeNode(7);
    five->left = six;
    five->right = seven;
    TreeNode* eight = new TreeNode(14);
    third->right = eight;
    TreeNode* nineth = new TreeNode(3);
    eight->left = nineth;
    showTree(first);
    recoverTree(first);
    showTree(first);
}
