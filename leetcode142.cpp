/*************************************************************************
> File Name: leetcode142.cpp
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
ListNode *detectCycle(ListNode *head) {
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }
    ListNode* first = head;
    ListNode* second = head;
    ListNode* pStart = head;
    while(second != NULL)
    {
        first = first->next;
        second = second->next;
        if(second != NULL)
        {
            second = second->next;
        }
        if(first == second)
        {
            while(first != pStart)
            {
                first = first->next;
                pStart = pStart->next;
            }
            return pStart;
        }
    }
    return NULL;
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
    nodeFour->next = nodeOne;
    ListNode* node = detectCycle(firstList);
    cout <<node->val<<endl;
}
