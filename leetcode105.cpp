/*************************************************************************
> File Name: leetcode105.cpp
> Author: 
> Mail: 
> Created Time: Sat 17 Sep 2016 06:46:08 PM PDT
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
//根据
TreeNode* getTree(vector<int>& pre,int preStart,int preEnd,vector<int>& in,int inStart,int inEnd)
{
    if(inStart > inEnd || preStart > preEnd)
    {
        return NULL;
    }
    int i = 0 ;
    for(;i <= inEnd;i++)
    {
        if(in[i] == pre[preStart])
        {
            break;
        }
    }
    int len = i - inStart;
    TreeNode* root = new TreeNode(pre[preStart]);
    root->left = getTree(pre,preStart+1,preStart+len,in,inStart,i-1);
    root->right = getTree(pre,preStart+len+1,preEnd,in,i+1,inEnd);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return getTree(preorder,0,preorder.size() -1,inorder,0,inorder.size()-1);
}
vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > result;
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
        vector<int> vecTemp;
        while(!q.empty())
        {
            pCur = q.front();
            vecTemp.push_back(pCur->val);
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
        result.push_back(vecTemp);
        q = qTemp;

    }
    return result;

}
int main()
{
    vector<int> pre ;
    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(4);
    pre.push_back(7);
    pre.push_back(3);
    pre.push_back(5);
    pre.push_back(6);
    pre.push_back(8);
    vector<int> in;
    in.push_back(4);
    in.push_back(7);
    in.push_back(2);
    in.push_back(1);
    in.push_back(5);
    in.push_back(3);
    in.push_back(8);
    in.push_back(6);
    TreeNode* tree = buildTree(pre,in);
    vector<vector<int> > result = levelOrder(tree);
    for(int i = 0 ; i < result.size();i++)
    {
        for(int j = 0; j < result[i].size();j++)
        {
            cout << result[i][j] << '\t';

        }
        cout << endl;

    }
}
