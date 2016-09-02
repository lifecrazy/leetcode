/*************************************************************************
	> File Name: leetcode147.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 02 Sep 2016 12:34:39 AM PDT
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
ListNode* insertionSortList(ListNode* head) {
    if(head == NULL)
        return head;
    ListNode list(-1);
    ListNode* pCur = head;
    ListNode* pNew = &list;
    ListNode* pPre = &list;
    while(pCur != NULL)
    {
        bool flag= false;
        while(pNew->next != NULL)
        {
            if(pNew->next->val < pCur->val)
            {
                pPre = pNew->next;
                pNew = pNew ->next;
            }
            else
            {
                ListNode* temp = new ListNode(pCur->val);
                temp->next = pNew->next;
                pPre->next = temp;
                flag = true;
                break;
            }
        }
        //
        if(!flag)
        {
            ListNode * temp = new ListNode(pCur->val);
            pPre->next = temp;
        }
        pCur = pCur->next;
        pNew = &list;
        pPre = &list;
    }
    return list.next;
}
int main()
{
    srand(unsigned(time(0)));
    int num = 10 ;
    ListNode list(-1);
    ListNode* p = &list;
    for(int i = 0 ; i < num;i++ )
    {
        int temp = rand()%100;
        ListNode* tempNode = new ListNode(temp);
        p->next = tempNode;
        p = p->next;
    }
    p = list.next;
    while(p != NULL)
    {
        cout << p->val<<'\t';
        p = p->next;
    }
    cout << endl;
    p = insertionSortList(list.next);
    while(p != NULL)
    {
        cout << p->val <<'\t';
        p = p->next;
    }
    cout << endl;
}
