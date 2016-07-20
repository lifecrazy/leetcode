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
ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode* pPre = NULL;
    ListNode* pCur = head;
    while(pCur != NULL)
    {
        ListNode* pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        if(pNext == NULL)
        {
            return pCur;
        }
        pCur = pNext;
    }
    return pCur;
}
int main()
{
    ListNode* firstList = new ListNode(2);
    ListNode* nodeOne = new ListNode(3);
    firstList->next = nodeOne;
    ListNode* nodeTwo = new ListNode(4);
    nodeOne->next = nodeTwo;
/*    ListNode* nodeThree = new ListNode(5);
    nodeTwo->next = nodeThree;
    ListNode* nodeFour = new ListNode(6);
    nodeThree->next = nodeFour;
    nodeFour->next =NULL;*/
    ListNode* p = firstList;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
    ListNode* results = reverseList(firstList);
    p = results;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
}
