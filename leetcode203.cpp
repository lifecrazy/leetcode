/*************************************************************************
	> File Name: leetcode203.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 12 Jul 2016 06:06:45 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* cur = head;
    ListNode* pre = NULL;
    while(cur != NULL)
    {
        if(val == cur->val)
        {
            if(pre == NULL)
            {
                head = cur->next;
            }
            else
            {
                pre->next = cur->next;
            }
        }
        else
        {
            pre = cur;
        }
        cur = cur->next;
    }
    return head;
}
int main()
{
    //1  2 6 3 4 5 6
    ListNode* list = new ListNode(1);
    ListNode* nodeTwo = new ListNode(2);
    ListNode* nodeThree = new ListNode(6);
    ListNode* nodeFour = new ListNode(3);
    ListNode* nodeFive = new ListNode(4);
    ListNode* nodeSix = new ListNode(5);
    ListNode* nodeSeven = new ListNode(6);
    list->next = nodeTwo;
    nodeTwo->next = nodeThree;
    nodeThree->next = nodeFour;
    nodeFour->next = nodeFive;
    nodeFive->next = nodeSix;
    nodeSix->next =nodeSeven;
    nodeSeven->next = NULL;
    ListNode* cur = list;
    while(cur != NULL)
    {
        cout << cur->val << "\t";
        cur = cur->next;
    }
    cout << endl;
    removeElements(list,6);
}
