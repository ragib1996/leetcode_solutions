
#include <iostream>
#include <stdio.h>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* swapPairs(ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	struct ListNode * current_node = NULL, * p_t = NULL, *c_t = NULL, *a;
	current_node = head;

	while (current_node != NULL)
	{
		if (current_node == head)
		{
			head = current_node->next;
		}
		if (current_node->next != NULL)
		{
			c_t = current_node->next->next;

		}
		
		if (p_t != NULL)
		{
			if (current_node->next != NULL)
			{
				p_t->next = current_node->next;
			}
			else
			{
				p_t->next = current_node;
			}
			
		}
		a = current_node->next;
		if (a != NULL)
		{
			a->next = current_node;
		}
		else
		{
			current_node = a;
			continue; 
		}
		p_t = current_node;
		p_t->next = NULL;
		current_node = c_t; 

	}

	return head;

}


int main()
{
	//cout << "Hello world.";

	struct ListNode* head, *p, *current_node;
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
	*/

	
	struct ListNode * ans = swapPairs(head);

	current_node = ans;

	while (current_node != NULL)
	{
		cout << current_node->val << " ";
		current_node = current_node->next;
	}
	

	return 0;
}