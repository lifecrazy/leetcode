/*************************************************************************
	> File Name: leetcode199.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 08 Sep 2016 06:11:40 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if(root == NULL)
    {
        return result;
    }
    TreeNode* pCur = root;
    queue<TreeNode* > q;
    q.push(pCur);
    while(!q.empty())
    {
        queue<TreeNode*> qTemp;
       while(!q.empty())
        {
            pCur = q.front();
            if(q.size() == 1)
            {
                result.push_back(pCur->val);
            }
            q.pop();
            if(pCur->left != NULL)
            {
                qTemp.push(pCur->left);
            }
            if(pCur->right != NULL)
            {
                qTemp.push(pCur->right);
            }
        }
        q = qTemp;
    }
    return result;
}
int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* first = new TreeNode(2);
    TreeNode* sec = new TreeNode(3);
    TreeNode* third = new TreeNode(4);
    TreeNode* forth = new TreeNode(5);
    TreeNode* five = new TreeNode(6);
    TreeNode* six = new TreeNode(7);
    root->left = first;
    root->right = sec;
    first->left = third;
    sec->left = forth;
    sec->right = five;
    five->left = six;
    vector<int> result = rightSideView(root);
    for(int i = 0 ; i < result.size();i++)
    {
        cout << result[i] << '\t';
    }
    cout << endl;
}
