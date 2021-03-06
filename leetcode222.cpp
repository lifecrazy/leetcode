/*************************************************************************
	> File Name: leetcode144.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 07 Sep 2016 06:50:11 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//按照前序遍历 超时
int countNodes_2(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* p = root;
    int count = 0;
    while(p != NULL || !s.empty())
    {
        if(p != NULL)
        {
            s.push(p);
            count++;
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
    return count;
}
int countNodes(TreeNode* root) {
    int lCount = 0;
    int rCount = 0;
    TreeNode* pLeft = root;
    TreeNode* pRight = root;
    while(pLeft != NULL)
    {
        lCount++;
        pLeft = pLeft->left;
    }
    while(pRight != NULL)
    {
        rCount++;
        pRight = pRight->right;
    }
    if(lCount == rCount)
    {
        return pow(2,lCount) - 1;
    }
    return countNodes(root->left) + countNodes(root->right) +1;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* first = new TreeNode(2);
    TreeNode* sec = new TreeNode(3);
    root->right = first;
    first->left = sec;
    cout << countNodes(root) << endl;
}
