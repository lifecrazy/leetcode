/*************************************************************************
	> File Name: leetcode148.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 04 Sep 2016 07:07:04 PM PDT
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};  
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
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
ListNode* sortList(ListNode* head) {
    if(head == NULL ||head->next == NULL)
    {
        return head;
    }
    ListNode* pFast = head;
    ListNode* pSlow = head;
    while(pFast->next != NULL&&pFast->next->next != NULL)
    {
        pFast = pFast->next;
        pFast = pFast->next;
        pSlow = pSlow->next;
    }
    pFast = pSlow;
    pSlow = pSlow->next;
    pFast->next = NULL;
    ListNode* l1 = sortList(head);
    ListNode* l2 = sortList(pSlow);
    return mergeTwoLists(l1,l2);
}    

int main()
{
    srand(unsigned(time(0)));
    int num = 10;
    ListNode list(-1);
    ListNode* p = &list;
    for(int i = 0 ; i < num;i++)
    {
        int temp = rand()%100;
        ListNode* tempNode = new ListNode(temp);
        p->next = tempNode;
        p = p->next;
    }
    p = list.next;
    while(p != NULL)
    {
        cout << p->val <<'\t';
        p = p->next;
    }
    cout << endl;
    p = sortList(list.next);
    while(p != NULL)
    {
        cout << p->val <<'\t';
        p = p->next;
    }
    cout << endl;
}
