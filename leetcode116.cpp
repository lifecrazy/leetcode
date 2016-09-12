/*************************************************************************
	> File Name: leetcode116.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 11 Sep 2016 10:47:26 PM PDT
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
void connect(TreeLinkNode *root) {
    if(root == NULL)
    {
        return;
    }
    queue<TreeLinkNode*> q;
    q.push(root);
    while(!q.empty())
    {
        queue<TreeLinkNode*> tempQ;
        TreeLinkNode* pCur = NULL;
        while(!q.empty())
        {
            if(pCur != NULL)
            {
                pCur->next = q.front();
            }
            pCur = q.front();
            q.pop();
            if(pCur->left != NULL)
                tempQ.push(pCur->left);
            if(pCur->right != NULL)
                tempQ.push(pCur->right);
        }
        pCur = NULL;
        q = tempQ;
    }
}
int main()
{
    TreeLinkNode* first = new TreeLinkNode(1);
    TreeLinkNode* sec = new TreeLinkNode(2);
    TreeLinkNode* third = new TreeLinkNode(3);
    TreeLinkNode* fourth = new TreeLinkNode(4);
    TreeLinkNode* five = new TreeLinkNode(5);
    TreeLinkNode* six = new TreeLinkNode(6);
    TreeLinkNode* seven = new TreeLinkNode(7);
    first->left = sec;
    first->right = third;
    sec->left = fourth;
    sec->right = five;
    third->left = six;
    third->right = seven;
    connect(first);
    TreeLinkNode* pLeft = first;
    TreeLinkNode* pNext = first;
    while(pLeft != NULL)
    {
        while(pNext != NULL)
        {
            cout << pNext->val << '\t';
            pNext = pNext->next;
        }
        pLeft = pLeft->left;
        pNext = pLeft;
        cout <<endl;
    }
}
