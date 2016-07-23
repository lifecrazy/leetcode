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
//思路：设置两个指针让一个指针行走k步，
//然后让两个指针同时向前行走直到第一个指针走到末尾
//第二个指针所指的下一个结点即为要反转的结点的头结点
//边界问题：当k 为链表的长度时直接返回该链表即为结果。
ListNode* rotateRight(ListNode* head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;   
    }
    ListNode* pPre = head;
    int count = 0;
    while (pPre != NULL)
    {
        pPre = pPre->next;
        count++;    
    }
    ListNode* pCur = head;
    pPre = head;
    for (int i = 0; i < k % count; i++)
    {
        pPre = pPre->next;    
    }
    /*这样的方法去找第k个节点当k很大的时候会超时
    *  ListNode* pPre = head;
    *  ListNode* pCur = head;
    *  for (int i = 0; i < k ; i++)
    *  {
    *       if (pPre == NULL)
    *       {
    *           pPre = head;
    *       }
    *       pPre = pPre->next;
    *  }*/
    if (pPre != NULL)
    {
        while (pPre->next != NULL)
        {
            pPre = pPre->next;
            pCur = pCur->next;        
        }
        pPre->next = head;
        head = pCur->next;
        pCur->next = NULL;    
    }
    return head;
}


/*ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode* pPre = NULL;
    ListNode* pCur = head;
    ListNode* pStart = NULL;
    ListNode* pEnd = NULL;
    int i = 1;
    while(pCur != NULL)
    {
        ListNode* pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        if(i % k == 0|| pNext == NULL)
        {
            if(pStart == NULL)
            {
                //记录子链的尾节点
                pEnd = head;
                //设置头结点
                head = pCur;
                //链接剩下的结点
                pEnd->next = pNext;
                //记录下一个子链的起点
                pStart = pNext;
            }
            else
            {
                //链接反转后的头结点到已经翻转的链表上
                pEnd->next = pCur;
                //链接翻转后尾节点和后边尚未反转的链表
                pStart->next = pNext;
                //设置尾节点
                pEnd = pStart;
                //将翻转后的子链和原来的链表剩余的结点连接起来
                pStart = pNext;
            }
        }
        pCur = pNext;
        i++;
    }
    return head;
}*/
int main()
{
    ListNode* firstList = new ListNode(2);
    ListNode* nodeOne = new ListNode(3);
    firstList->next = nodeOne;
    ListNode* nodeTwo = new ListNode(4);
    nodeOne->next = nodeTwo;
    ListNode* nodeThree = new ListNode(5);
    nodeTwo->next = nodeThree;
    ListNode* nodeFour = new ListNode(6);
    nodeThree->next = nodeFour;
    ListNode* p = firstList;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
    ListNode* results = rotateRight(firstList,5);
    p = results;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->next;
    }
    cout << endl;
}
