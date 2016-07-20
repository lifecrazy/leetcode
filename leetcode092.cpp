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
ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode* pPre = NULL;
    ListNode* pCur = head;
    for(size_t i = 1 ; i < m; i++)
    {
        pPre = pCur;
        pCur = pCur->next;
    }
    int i = 0;
   /* int count = 0;
    ListNode* tempCount = head;
    while(tempCount != NULL)
    {
        count++;
        tempCount = tempCount->next;
    }
    if(n > count)
    {
        n = count;
    }*/
    ListNode *pStartPre = pPre;
    ListNode *pEnd = pCur;
    while(i < n- m + 1)
    {
        ListNode* pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
        i++;
    }
    if(pStartPre == NULL)
    {
        head = pPre;
    }
    else
    {
        pStartPre->next = pPre;
    }
    pEnd->next = pCur;
    return head;
}
int main()
{
    ListNode* firstList = new ListNode(1);
    ListNode* nodeOne = new ListNode(2);
    firstList->next = nodeOne;
    ListNode* nodeTwo = new ListNode(3);
    nodeOne->next = nodeTwo;
    ListNode* nodeThree = new ListNode(4);
    nodeTwo->next = nodeThree;
    ListNode* nodeFour = new ListNode(5);
    nodeThree->next = nodeFour;
    nodeFour->next =NULL;
    ListNode* p = firstList;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
    ListNode* results = reverseBetween(firstList,1,5);
    p = results;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
}
