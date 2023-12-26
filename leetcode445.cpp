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
ListNode *ReverseList(ListNode *head)
{
    ListNode *cur = head;
    ListNode *pre = nullptr;
    while (cur != nullptr)
    {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        if (next == nullptr)
        {
            return cur;
        }
        cur = next;
    }

    return head;
}
ListNode *addInList(ListNode *head1, ListNode *head2)
{
    int len1 = 0;
    int len2 = 0;
    ListNode *p = head1;
    while (p != NULL)
    {
        p = p->next;
        len1++;
    }
    p = head2;
    while (p != NULL)
    {
        p = p->next;
        len2++;
    }
    ListNode *p1 = ReverseList(head1);
    ListNode *p2 = ReverseList(head2);
    ListNode *res = new ListNode(-1);
    ListNode *cur = nullptr;
    if (len1 > len2)
    {
        res->next = p1;
        cur = p1;
    }
    else
    {
        res->next = p2;
        cur = p2;
    }
    while (p1 != nullptr && p2 != nullptr)
    {
        int tmp = p1->val + p2->val;
        cur->val = tmp % 10;
        if (cur->next != nullptr)
        {
            cur->next->val += tmp / 10;
        }
        else
        {
            if (tmp > 9)
            {
                ListNode *pTmp = new ListNode(tmp / 10);
                cur->next = pTmp;
            }
        }
        cur = cur->next;
        p1 = p1->next;
        p2 = p2->next;
    }

    while (cur != nullptr && cur->val > 9)
    {
        int tmp = cur->val;
        cur->val = tmp % 10;
        if (cur->next != nullptr)
        {
            cur->next->val += tmp / 10;
        }
        else
        {
            ListNode *pTmp = new ListNode(tmp / 10);
            cur->next = pTmp;
            break;
        }
        cur = cur->next;
    }
    return ReverseList(res->next);
}
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
