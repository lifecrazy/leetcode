/*************************************************************************
	> File Name: leetcode143.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Aug 2016 06:16:13 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//思路：1.将链表分为前后两半部分
//2.将后半部分链表逆置
//3.合并两个链表
void divideList(ListNode* head, ListNode* &front, ListNode* &end)
{
    ListNode* first = head;
    ListNode* sec = head;
    ListNode* pPre = head;
    while(first != NULL)
    {
        pPre = sec;
        first = first->next;
        if(first != NULL)
        {
            first = first->next;
        }
        sec = sec->next;
    }
    front = head;
    end = pPre->next;
    pPre->next = NULL;
}
void reverseList(ListNode* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return ;
    }
    ListNode* pCur = head;
    ListNode* pPre = NULL;
    while(pCur != NULL)
    {
        ListNode* pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        if(pNext == NULL)
        {
            break;
        }
        pCur = pNext;
    }
    head = pCur;
}
void reorderList(ListNode* head) {
    ListNode* front;
    ListNode* end;
    divideList(head,front,end);
    reverseList(end);
    while(front != NULL)
    {
        ListNode* temp = front->next;
        front->next = end;
        end = end->next;
        front = front->next;
        front->next = temp;
        front = front->next;
    }
}
int main()
{
    ListNode* list = new ListNode(0);
    int num = 10;
    ListNode* temp = list;
    for(int i = 1 ; i < num; i++)
    {
        ListNode* node = new ListNode(i);
        temp->next = node;
        temp = temp->next;
    }
    ListNode* p = list;
    while(p!= NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
    reorderList(list);
    p = list;
    while(p!= NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
}

