// partition_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

using namespace std;


struct ListNode
{
    int val;
    struct ListNode* next;
};

ListNode* partition(ListNode* head, int x)
{
	struct ListNode* p, * previous_node = NULL, * current_node, *t;
	int i, j, k, l;

	if (head == NULL || head->next == NULL )
	{
		return head;
	}


	current_node = head;
	while (current_node != NULL)
	{
		if ( current_node->val < x ) 
		{
			previous_node = current_node;
		}
		if ( current_node->next != NULL && current_node->val >= x && current_node->next->val < x)
		{
		    t = current_node->next;
			current_node->next = t->next;
			//t->next = current_node;
			//previous_node = t;
			if (previous_node == NULL)
			{
				t->next = head;
				previous_node = t;
				head = previous_node;
			}
			else
			{
				t->next = previous_node->next;
				previous_node->next = t;
				previous_node = t;
			}
		}
		else
		{
			
			current_node = current_node->next;
		}
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
	p->val = 4;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	
	p = new(ListNode);
	p->val = 3;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;

	p = new(ListNode);
	p->val = 2;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	
	p = new(ListNode);
	p->val = 5;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;

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
	struct ListNode * ans = partition( head, 3);
	current_node = ans;
	while (current_node != NULL)
	{
		cout << current_node->val << " ";
		current_node = current_node->next;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
