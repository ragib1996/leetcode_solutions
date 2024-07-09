#include <iostream>
#include <stdio.h>
#include <deque>

using namespace std;


struct ListNode
{
    int val;
    struct ListNode* next;
};

ListNode* reverseBetween(ListNode* head, int left, int right)
{

	struct ListNode* current_node, * p, * previous_node = NULL, *next_node = NULL, *t, *t2;
	int i=0, j, k, l;
	deque < struct ListNode* > q;

	current_node = head;
	while (current_node != NULL)
	{
		i++;
		if (i == left - 1)
		{
			previous_node = current_node;
		}
		else if (i == right + 1)
		{
			next_node = current_node;
		}
		if (i >= left && i <= right)
		{
			q.push_back(current_node);
		}
		current_node = current_node->next;

	}
	
	if (q.size() == 1)
	{
		return head;
	}

	/*
	for (i = 0; i < q.size(); i++)
	{
		cout << q.at(i)->val << " ";
	}
	cout << "\n" << previous_node->val;
	cout << "\n" << next_node->val; 
	*/
	while (q.size() > 2)
	{
		if (previous_node != NULL)
		{
			previous_node->next = q.back();
		}
		q.back()->next = q.at(1);
		t = q.back();
		q.pop_back();
		q.front()->next = next_node;
		q.back()->next = q.front();
		t2 = q.front();
		q.pop_front();
		if (previous_node == NULL)
		{
			head = t;
		}
		previous_node = t;
		next_node = t2;
	}

	if (q.size() == 2)
	{
		if (previous_node != NULL)
		{
			previous_node->next = q.at(1);
		}
		q.at(1)->next = q.front();
		q.at(0)->next = next_node;
		if (previous_node == NULL)
		{
			head = q.at(1);
		}
		q.pop_back();
		q.pop_front();


	}


	return head;
}


int main()
{

	struct ListNode* head, * p, * current_node;
	head = new (ListNode);
	head->val = 1;
	head->next = NULL;
	current_node = head;
	
	p = new(ListNode);
	p->val = 2;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	
	p = new(ListNode);
	p->val = 3;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	/*
	p = new(ListNode);
	p->val = 4;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	
	p = new(ListNode);
	p->val = 5;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	/*
	p = new(ListNode);
	p->val = 2;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	/*
	p = new(ListNode);
	p->val = 5;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	/*
	p = new(ListNode);
	p->val = 3;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	*/

	current_node = head;

	struct ListNode * ans = reverseBetween (head, 1, 3);
	current_node = ans;

	while (current_node != NULL)
	{
		cout << current_node->val << " ";
		current_node = current_node->next;
	}

    return 0;
}