/*************************************************************************
> File Name: leetcode025.cpp
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
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL || k <= 1)
    {
        return head;
    }
    ListNode* pCur = head;
    ListNode* pPre = NULL;
    ListNode* pStart = NULL;
    ListNode* pEnd = NULL;
    ListNode* pTemp = head;
    int len = 0;
    while(pTemp != NULL)
    {
        pTemp = pTemp->next;
        len++;
    }
    int j = 0;
    int i = 1;
    while(j < (len/k))
    {
        cout << "j: "<< j << "len/k"<<(len/k)<<endl;
        ListNode* pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
        if(i == k)
        {
            j++;
            i = 1;
            if(pStart == NULL)
            {
                head->next = pCur;
                pStart = head;
                head = pPre;
            }
            else
            {
                pEnd->next = pCur;
                pStart->next = pPre;
                pStart = pEnd;
            }
            pEnd = pCur;
        }
        else
        {
            i++;    
        }
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
    ListNode* secondList = new ListNode(4);
    nodeTwo->next = secondList;
    ListNode* nodeThree = new ListNode(5);
    secondList->next = nodeThree;
    ListNode* nodeFour = new ListNode(6);
    nodeThree->next = nodeFour;
    nodeFour->next = NULL;
    ListNode* p = firstList;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
    ListNode* results = reverseKGroup(firstList,4);
    p = results;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
}
