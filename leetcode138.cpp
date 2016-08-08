/*************************************************************************
> File Name: leetcode138.cpp
> Author: 
> Mail: 
> Created Time: Mon 08 Aug 2016 12:16:43 AM PDT
************************************************************************/

#include<iostream>
using namespace std;
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode* pCur = head;
    while(pCur != NULL)
    {
        RandomListNode* temp = new RandomListNode(pCur->label);
        temp->next = pCur->next;
        temp->random = pCur->random;
        pCur->next = temp;
        pCur = pCur->next->next;
    }
    pCur = head;
    while(pCur != NULL)
    {
        if(pCur->random != NULL)
        {
            pCur->next->random = pCur->random->next;
        }
        pCur = pCur->next->next;
    }
    pCur = head->next;
    RandomListNode* pResult = pCur;
    RandomListNode* pLast = head; 
    while(pCur != NULL)
    {
        pLast->next = pCur->next;
        if(pLast->next != NULL)
        {
            pCur->next = pLast->next->next;
        }
        pLast = pLast->next;
        pCur = pCur->next;
    }
    return pResult;
}
int main()
{
    RandomListNode* nodeOne = new RandomListNode(1);
    RandomListNode* nodeTwo = new RandomListNode(2);
    RandomListNode* nodeThree = new RandomListNode(3);
    RandomListNode* nodeFour = new RandomListNode(4);
    RandomListNode* nodeFive = new RandomListNode(5);
    RandomListNode* nodeSix = new RandomListNode(6);
    nodeOne->next = nodeTwo;
    nodeTwo->next = nodeThree;
    nodeThree->next = nodeFour;
    nodeFour->next = nodeFive;
    nodeFive->next = nodeSix;

    nodeOne->random = nodeFour;
    nodeTwo->random = nodeThree;
    nodeThree->random = NULL;
    nodeFour->random = nodeOne;
    nodeFive->random = nodeFive;
    nodeSix->random = nodeTwo;

    RandomListNode* result = copyRandomList(nodeOne);

    RandomListNode* p = result;
    while(p != NULL)
    {
        cout << p->label << "\t";
        p = p->next;
    }
    cout << endl;

}
