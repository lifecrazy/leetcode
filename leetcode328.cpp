/*************************************************************************
	> File Name: leetcode328.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 09 Aug 2016 06:20:26 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode oddNode(-1);
    ListNode evenNode(-1);
    ListNode* pOdd = &oddNode;
    ListNode* pEven = &evenNode;
    ListNode* pCur = head;
    int i = 0;
    while(pCur != NULL)
    {
        if(i % 2 == 0)
        {
            pOdd->next = pCur;
            pOdd = pOdd->next;
        }
        else
        {
            pEven->next = pCur;
            pEven = pEven->next;
        }
        pCur = pCur->next;
        i++;
    }
    pOdd->next = evenNode.next;
    pEven->next = NULL;
    return oddNode.next;
}
int main()
{
    ListNode data(-1);
    ListNode* pCur = &data;
    int num = 3 ;
    for(int i = 0;i < num; i++)
    {
        ListNode* node = new ListNode(i);
        pCur->next = node;
        pCur = pCur->next;
    }
    pCur = data.next;
    while(pCur != NULL)
    {
        cout << pCur->val << "\t";
        pCur = pCur->next;
    }
    cout << endl;
    pCur = oddEvenList(data.next);  
    while(pCur != NULL)
    {
        cout << pCur->val << "\t";
        pCur = pCur->next;
    }
    cout << endl;
}
