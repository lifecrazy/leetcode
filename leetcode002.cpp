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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    if(l1 == NULL)
    {
        return l2;
    }
    if(l2 == NULL)
    {
        return l1;
    }
    int carry = 0;
    int temp = 0;
    ListNode* result = NULL;
    ListNode* cur = NULL;
    while(l1 != NULL || l2 != NULL)
    {
        if(l1 == NULL)
        {
            temp = 0 + l2->val + carry;
            l2 = l2 ->next;
        }
        else if(l2 == NULL)
        {
            temp = l1->val + 0 + carry;
            l1 = l1->next;
        }
        else
        {
            temp = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
        }
        carry = temp / 10;
        ListNode* tempNode = new ListNode(temp % 10);
        if(result == NULL)
        {
            result = tempNode;
            cur = tempNode;
        }
        else
        {
            cur->next = tempNode;
            cur = cur->next;
        }
    }
    if(carry != 0)
    {
        cur->next = new ListNode(carry);
    }
return result; 
}
int main()
{
    ListNode* firstList = new ListNode(2);
    ListNode* nodeOne = new ListNode(4);
    firstList->next = nodeOne;
    ListNode* nodeTwo = new ListNode(3);
    nodeOne->next = nodeTwo;
    nodeTwo->next = NULL;
    ListNode* secondList = new ListNode(5);
    ListNode* nodeThree = new ListNode(6);
    secondList->next = nodeThree;
    ListNode* nodeFour = new ListNode(4);
    nodeThree->next = nodeFour;
    nodeFour->next = NULL;
    ListNode* results = addTwoNumbers(firstList,secondList);
    ListNode* p = results;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
}
