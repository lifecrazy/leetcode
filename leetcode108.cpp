/*************************************************************************
> File Name: leetcode108.cpp
> Author: 
> Mail: 
> Created Time: Sun 18 Sep 2016 12:28:59 AM PDT
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
TreeNode* getTree(vector<int>& nums,int left,int right)
{
    if(left > right)
    {
        return NULL;
    }
    int mid = (left + right) / 2;
    TreeNode* leftNode = getTree(nums,left,mid - 1);
    TreeNode* rightNode = getTree(nums,mid+1,right);
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = leftNode;
    node->right = rightNode;
    return node;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return getTree(nums,0,nums.size() - 1);
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
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    TreeNode* root = sortedArrayToBST(nums);
    vector<vector<int> > result = levelOrder(root);
    for(int i = 0 ; i < result.size();i++)
    {
        for(int j = 0; j < result[i].size();j++)
        {
            cout << result[i][j] << '\t';

        }
        cout << endl;

    }
}
