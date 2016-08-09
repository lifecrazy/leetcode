/*************************************************************************
> File Name: leetcode237.cpp
> Author: 
> Mail: 
> Created Time: Tue 09 Aug 2016 01:06:46 AM PDT
************************************************************************/

#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    ListNode* temp = node->next;
    node->next = node->next->next;
    delete temp;
}
int main()
{
    ListNode data(-1);
    int num = 10;
    ListNode* pCur = &data;
    for(int i = 0 ; i < num; i++)
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
    ListNode* Dnode = data.next->next->next;
    deleteNode(Dnode);
    pCur = data.next;
    while(pCur != NULL)
    {
        cout << pCur->val << "\t";
        pCur = pCur->next;
    }
    cout << endl;

}
