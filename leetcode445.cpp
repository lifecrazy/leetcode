/*************************************************************************
	> File Name: leetcode445.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Nov 2016 06:40:50 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode result(-1);
    int len1 = 0;
    int len2 = 0;
    ListNode* p = l1;
    while(p != NULL)
    {
        p = p->next;
        len1++;
    }
    p = l2;
    while(p != NULL)
    {
        p = p->next;
        len2++;
    }
    ListNode* pPre = NULL;
    ListNode* pAnother = NULL;
    if(len1 > len2)
    {
        result.next = l1;
        p = l1;
        for(int i = 0 ; i < len1 - len2; i++)
        {
            pPre = p;
            p = p->next;
        }
        pAnother = l2;
    }
    else
    {
        result.next = l2;
        p = l2;
        for(int i = 0;i < len2 -len1; i++)
        {
            pPre = p;
            p = p->next;
        }
        pAnother = l1;
    }
    while(p != NULL && pAnother != NULL)
    {
        int tmp = p->val + pAnother->val;
        pPre->val += tmp/10;
        p->val =tmp % 10;
        pPre = p;
        p = p->next;
        pAnother = pAnother->next;
    }
    return result.next;
}
int main()
{
    ListNode L1(-1);
    ListNode L2(-1);
    ListNode* node1 = new ListNode(7);
    L1.next =node1;
    ListNode* node2 = new ListNode(2);
    node1->next = node2;
    ListNode* node3 = new ListNode(4);
    node2->next = node3;
    ListNode* node4 = new ListNode(3);
    node3->next = node4;
    ListNode* node5 = new ListNode(5);
    L2.next = node5;
    ListNode* node6 = new ListNode(6);
    node5->next = node6;
    ListNode* node7 = new ListNode(4);
    node6->next = node7;
    ListNode* p = L1.next;
    while(p != NULL)
    {
        cout << p->val << '\t';
        p = p->next;
    }
    cout << endl;
    p = L2.next;
    while(p != NULL)
    {
        cout << p->val << '\t';
        p = p->next;
    }
    cout << endl;
    p = addTwoNumbers(L1.next,L2.next);
    while(p != NULL)
    {
        cout << p->val << '\t';
        p = p->next;
    }
    cout << endl;
}
