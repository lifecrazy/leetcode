/*************************************************************************
> File Name: leetcode021.cpp
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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1 == NULL)
    {
        return l2;
    }
    if(l2 == NULL)
    {
        return l1;
    }
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode newList(-1);
    ListNode* pCur = &newList;
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->val < p2->val)
        {
            pCur->next = p1;
            p1 = p1->next;
        }
        else
        {
            pCur->next = p2;
            p2 = p2->next;
        }
        pCur = pCur->next;
    }
    if(p1 != NULL)
    {
        pCur->next = p1;
    }
    else
    {
        pCur->next = p2;
    }
    return newList.next;
}
int main()
{
    ListNode* firstList = new ListNode(2);
    ListNode* nodeOne = new ListNode(5);
    firstList->next = nodeOne;
    ListNode* nodeTwo = new ListNode(10);
    nodeOne->next = nodeTwo;
    nodeTwo->next = NULL;
    ListNode* secondList = new ListNode(4);
    ListNode* nodeThree = new ListNode(6);
    secondList->next = nodeThree;
    ListNode* nodeFour = new ListNode(49);
    nodeThree->next = nodeFour;
    nodeFour->next = NULL;
    ListNode* results = mergeTwoLists(firstList,secondList);
    ListNode* p = results;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
}
