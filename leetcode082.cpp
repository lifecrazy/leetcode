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
    ListNode* deleteDuplicatessec(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* first = head->next;
        ListNode* sec = head;
        ListNode* pre = nullptr;
        while (first) {
            if (first->val == sec->val) {
                do {
                    first = first->next;
                } while (first && sec->val == first->val);
                if (pre) {
                    pre->next = first;
                } else {
                    head = first;
                }
                sec = first;
                if (first) {
                    first = first->next;
                }
            } else {
                first = first->next;
                pre = sec;
                sec = sec->next;
            }
        }
        return head;
    }
ListNode* deleteDuplicates(ListNode* head) {
    //只有一个节点或者没有节点的情况
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode *first = head;
	ListNode *pre = head;
	ListNode *second = head->next;
	int count = 1;
	while (second != NULL)
	{
		if (first->val == second->val)
		{
			second = second->next;
			count++;
		}
		else
		{
			if (count == 1)
			{
				pre = first;
				first = first->next;
				second = second->next;
			}
			else
			{
				if (pre == first)
				{
					head = second;
					pre = head;
					first = head;
					second = second->next;
				}
				else
				{
					pre->next = second;
					first = second;
					second = second->next;
				}
				count = 1;
			}
		}
	}
	if (count != 1)
	{
		if (pre == head&&pre == first)
		{
			return NULL;
		}
		else {
			pre->next = NULL;
		}
	}
	return head;
}

int main()
{
	ListNode* firstList = new ListNode(1);
	ListNode* nodeOne = new ListNode(2);
	firstList->next = nodeOne;
	ListNode* nodeTwo = new ListNode(2);
	nodeOne->next = nodeTwo;
	//ListNode* secondList = new ListNode(2);
	//nodeTwo->next = secondList;
	//ListNode* nodeThree = new ListNode(3);
	//secondList->next = nodeThree;
	//ListNode* nodeFour = new ListNode(4);
	//nodeThree->next = nodeFour;
	//nodeFour->next = NULL;
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
