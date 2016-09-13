/*************************************************************************
	> File Name: leetcode100.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 12 Sep 2016 06:24:35 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL)
    {
        return true;
    }
    else if(p == NULL || q == NULL)
    {
        return false;
    }
    return p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}
int main()
{
    TreeNode* first = new TreeNode(1);
    TreeNode* sec = new TreeNode(2);
    TreeNode* third = new TreeNode(3);
    first->right = sec;
    sec->left = third;
    TreeNode* fourth = new TreeNode(1);
    TreeNode* five = new TreeNode(2);
    TreeNode* six = new TreeNode(3);
    fourth->right = five;
    five->left = six;
    cout << isSameTree(first,fourth) << endl;
}

