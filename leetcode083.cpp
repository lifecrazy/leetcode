/*************************************************************************
> File Name: leetcode083.cpp
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
ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
		return head;
	}
	ListNode* pPre = head;
	ListNode* pCur = head->next;
	while (pCur != NULL)
	{
		if (pPre->val == pCur->val)
		{
			pPre->next = pCur->next;
			pCur = pCur->next;
		}
		else
		{
			pPre = pPre->next;
			pCur = pCur->next;
		}
	}
	return head;
}

int main()
{
	ListNode* firstList = new ListNode(1);
	ListNode* nodeOne = new ListNode(1);
	firstList->next = nodeOne;
	ListNode* nodeTwo = new ListNode(2);
	nodeOne->next = nodeTwo;
	ListNode* secondList = new ListNode(2);
	nodeTwo->next = secondList;
	ListNode* nodeThree = new ListNode(3);
	secondList->next = nodeThree;
	ListNode* nodeFour = new ListNode(4);
	nodeThree->next = nodeFour;
	nodeFour->next = NULL;
	ListNode* p = firstList;
	while (p != NULL)
	{
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
	ListNode* results = deleteDuplicates(firstList);
	p = results;
	while (p != NULL)
	{
		cout << p->val << "\t";
		p = p->next;
	}
	cout << endl;
	getchar();
}
