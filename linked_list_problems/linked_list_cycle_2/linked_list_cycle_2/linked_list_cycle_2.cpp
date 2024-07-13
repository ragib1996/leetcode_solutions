// linked_list_cycle_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

using namespace std;



struct ListNode 
{
    int val;
    struct ListNode* next = NULL ;
};


ListNode* detectCycle(ListNode* head)
{
	struct ListNode* fast = head, * slow = head, * t, * t2;
	if (head == NULL)
	{
		return NULL;
	}

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;

			while (slow != fast)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return slow;
		}

		
	}
	return NULL;
}

int main()
{

	struct ListNode* head, * p, * current_node, *t ;
	head = new (ListNode);
	head->val = 1;
	head->next = NULL;
	current_node = head;
	
	p = new(ListNode);
	p->val = 2;
	p->next = head;
	t = p;
	current_node->next = p;
	current_node = current_node->next;
	/*
	p = new(ListNode);
	p->val = 0;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;

	p = new(ListNode);
	p->val = -4;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;

    p = new(ListNode);
    p->val = 5;
    p->next = t;
    current_node->next = p;
    current_node = current_node->next;
	*/
    struct ListNode* ans = detectCycle(head);
	if (ans != NULL)
    cout << ans->val;
	else
	{
		cout << "Null";
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
