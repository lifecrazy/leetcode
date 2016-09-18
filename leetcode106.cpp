/*************************************************************************
> File Name: leetcode106.cpp
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
TreeNode* getTree(vector<int>& in,int inStart,int inEnd,vector<int>& post,int postStart,int postEnd)
{
    if(inStart > inEnd || postStart > postEnd)
    {
        return NULL;
    }
    int i = 0 ;
    for(;i <= inEnd;i++)
    {
        if(in[i] == post[postEnd])
        {
            break;
        }
    }
    int len = inEnd - i;
    TreeNode* root = new TreeNode(post[postEnd]);
    root->right = getTree(in, i + 1, inEnd, post, postEnd-len, postEnd-1);
    root->left = getTree(in, inStart, i - 1, post, postStart, postEnd-len-1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder) {
    return getTree(inorder,0,inorder.size() -1,postorder,0,postorder.size()-1);
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
    vector<int> post ;
    post.push_back(7);
    post.push_back(4);
    post.push_back(2);
    post.push_back(5);
    post.push_back(8);
    post.push_back(6);
    post.push_back(3);
    post.push_back(1);
    vector<int> in;
    in.push_back(4);
    in.push_back(7);
    in.push_back(2);
    in.push_back(1);
    in.push_back(5);
    in.push_back(3);
    in.push_back(8);
    in.push_back(6);
    TreeNode* tree = buildTree(in,post);
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
