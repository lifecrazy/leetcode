/*************************************************************************
> File Name: leetcode019.cpp
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
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL || n <= 0)
    {
        return head;
    }
    ListNode* first = head;
    for(int i = 0 ; i < n;i++)
    {
        first = first->next;
    }
    ListNode* pCur = head;
    ListNode* pPre = head;
    while(first != NULL)
    {
        first = first->next;
        pPre = pCur;
        pCur = pCur->next;
    }
    pPre->next = pCur->next;
    return head;
}
int main()
{
    ListNode* firstList = new ListNode(1);
    ListNode* nodeOne = new ListNode(2);
    firstList->next = nodeOne;
    ListNode* nodeTwo = new ListNode(3);
    nodeOne->next = nodeTwo;
    ListNode* secondList = new ListNode(4);
    nodeTwo->next = secondList;
    ListNode* nodeThree = new ListNode(5);
    secondList->next = nodeThree;
    ListNode* nodeFour = new ListNode(6);
    nodeThree->next = nodeFour;
    nodeFour->next = NULL;
    ListNode* results = removeNthFromEnd(firstList,2);
    ListNode* p = results;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
}
