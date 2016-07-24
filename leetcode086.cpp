/*************************************************************************
> File Name: leetcode002.cpp
> Author: 
> Mail: 
> Created Time: Wed 06 Jul 2016 10:41:58 PM PDT
************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* partition(ListNode* head, int x) {
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode* pCur = head;
    ListNode pLeftHead(-1);
    ListNode pRightHead(-1);
    ListNode* left = &pLeftHead;
    ListNode* right = &pRightHead;
   while(pCur != NULL)
    {
        if(pCur->val < x)
        {
            //当left 为NULL时，记录 头结点的位置
            left->next = pCur;
            left = pCur;
        }
        else
        {
            right->next = pCur;
            right = pCur;
        }
        pCur = pCur->next;
    }
    left->next = pRightHead.next;
    right->next = NULL;
    return  pLeftHead.next;

}

int main()
{
    ListNode* firstList = new ListNode(1);
    ListNode* nodeOne = new ListNode(4);
    firstList->next = nodeOne;
    ListNode* nodeTwo = new ListNode(3);
    nodeOne->next = nodeTwo;
    ListNode* secondList = new ListNode(2);
    nodeTwo->next = secondList;
    ListNode* nodeThree = new ListNode(5);
    secondList->next = nodeThree;
    ListNode* nodeFour = new ListNode(2);
    nodeThree->next = nodeFour;
    nodeFour->next = NULL;
    ListNode* p = firstList;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
    ListNode* results = partition(firstList,4);
    p = results;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
}
