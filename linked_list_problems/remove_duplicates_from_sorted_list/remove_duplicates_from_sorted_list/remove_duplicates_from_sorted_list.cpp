#include <iostream>
#include <stdio.h>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
};

ListNode* deleteDuplicates(ListNode* head)
{
	struct  ListNode * current_node = head, * p = NULL, * previous_node = NULL;
	bool flag = false;

	while (current_node != NULL)
	{
		if (current_node->next != NULL)
		{
			if (current_node->next->val == current_node->val)
			{
				flag = true;
				current_node = current_node->next;
			}
			else if (flag == true)
			{
				if (current_node->next->next != NULL)
				{
					if (current_node->next->val == current_node->next->next->val)
					{
						current_node = current_node->next->next;
						continue;
					}
				}
				if (previous_node == NULL)
				{
					head = current_node->next;
					current_node->next = NULL;
					current_node = head;
					previous_node = head;
					flag = false;
				}
				else
				{
					previous_node->next = current_node->next;
					current_node->next = NULL;
					current_node = previous_node->next;
					flag = false;
				}
			}
			else
			{
				previous_node = current_node;
				current_node = current_node->next;
				flag = false;
			}
		}
		else
		{
			current_node = current_node->next;
		}
	}

	if (flag == true)
	{
		if (previous_node == NULL)
		{
			return previous_node;
		}
		else
		{
			previous_node->next = NULL;
		}
	}
	return head;
}

int main()
{
	//cout << "Hello world.";

	struct ListNode* head, * p, * current_node;
	head = new (ListNode);
	head->val = 1;
	head->next = NULL;
	current_node = head;

	p = new(ListNode);
	p->val = 1;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	
	p = new(ListNode);
	p->val = 3;
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
	p->val = 3;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	*/

	current_node = head;
	struct ListNode* ans = deleteDuplicates(head);
	current_node = ans;
	while (current_node != NULL)
	{
		cout << current_node->val << " ";
		current_node = current_node->next;
	}

	
	return 0;
}