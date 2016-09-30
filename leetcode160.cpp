/*************************************************************************
	> File Name: leetcode160.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 30 Sep 2016 01:17:36 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//思路：1.遍历两个链表看是否相交并统计链表的长度lenA 和lenB
//      2.让较长的链表先遍历|lenA -lenB|的距离，然后同时遍历
//      两个链表如果遇到相同的结点则返回这个结点即为交点
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL)
    {
        return NULL;
    }
    ListNode* pA = headA;
    ListNode* pB = headB;
    int lenA = 0;
    int lenB = 0;
    while(pA != NULL)
    {
        lenA++;
        pA = pA->next;
    }
    while(pB != NULL)
    {
        lenB++;
        pB = pB->next;
    }
    if(pA != pB)
    {
        return NULL;
    }
    pA = headA;
    pB = headB;
    int i = 0;
    if(lenA > lenB)
    {
        while(i < lenA - lenB)
        {
            pA = pA->next;
            i++;
        }
    }
    else
    {
        while(i < lenB -lenA)
        {
            pB = pB->next;
            i++;
        }
    }
    while(pA != NULL && pB != NULL)
    {
        if(pA == pB)
        {
            return pA;
        }
        pA = pA->next;
        pB = pB->next;
    }
    return NULL;
}
int main()
{

}
