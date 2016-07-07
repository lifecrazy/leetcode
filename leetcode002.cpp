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
    ListNode* result;
    ListNode* r ;
    r = result;
    int c = 0;
    while(l1 !=NULL && l2!=NULL)
    {
        int temp = l1->val+ l2->val + c ;
        c = temp / 10;
        ListNode* tempNode = new ListNode(temp<10?temp:temp%10);
        r->next = tempNode;
        l1 = l1->next;
        l2 = l2->next;
        r = r->next;
    }
    r->next = NULL;
    return result->next;
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
