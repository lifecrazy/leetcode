/*************************************************************************
	> File Name: leetcode145.cpp
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
void postorder(TreeNode* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        result.push_back(root->val);
    }
}
vector<int> postorderTraversal(TreeNode* root) {
    postorder(root);
    return result;
}

vector<int> postorderTraversal_2(TreeNode* root) {
    vector<int> res;
    if(root == NULL)
    {
        return res;
    }
    TreeNode* pCur = root;
    TreeNode* pPre = root;
    stack<TreeNode*> s;
    s.push(pCur);
    while(!s.empty())
    {
        pCur = s.top();
        if((pCur->left == NULL && pCur->right == NULL)||(pCur->right == NULL && pPre == pCur->left)||pPre == pCur->right)
        {
            res.push_back(pCur->val);
            pPre = pCur;
            s.pop();
        }
        else
        {
            if(pCur->right != NULL)
            {
                s.push(pCur->right);
            }
            if(pCur->left != NULL)
            {
                s.push(pCur->left);
            }
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
    vector<int> result = postorderTraversal(root);
    for(int i = 0 ; i < result.size();i++)
    {
        cout << result[i] << '\t';
    }
    cout << endl;
    result = postorderTraversal_2(root);
    for(int i = 0 ; i < result.size();i++)
    {
        cout << result[i] << '\t';
    }
    cout << endl;
}
