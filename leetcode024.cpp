/*************************************************************************
> File Name: leetcode024.cpp
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
ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    int temp = 0;
    ListNode* pCur = head;
    ListNode* pNext = head->next;
    while(pNext->next != NULL)
    {
        temp = pCur->val;
        pCur->val = pNext->val;
        pNext->val = temp;
        pCur = pNext->next;
        if(pCur->next ==NULL)
        {
            return head;
        }
        pNext = pCur->next;
    }
    if(pNext == head->next)
    {
        temp = head->val;
        head->val = head->next->val;
        head->next->val = temp;
    }
    return head;
}
int main()
{
    ListNode* firstList = new ListNode(1);
    ListNode* nodeOne = new ListNode(2);
    firstList->next = nodeOne;
    ListNode* nodeTwo = new ListNode(3);
    nodeOne->next = nodeTwo;
/*    ListNode* secondList = new ListNode(4);
    nodeTwo->next = secondList;
    ListNode* nodeThree = new ListNode(5);
    secondList->next = nodeThree;
    ListNode* nodeFour = new ListNode(6);
    nodeThree->next = nodeFour;
    nodeFour->next = NULL;*/
    ListNode* results = swapPairs(firstList);
    ListNode* p = results;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
}
