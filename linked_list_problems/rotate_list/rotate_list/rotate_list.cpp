// rotate_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
};


ListNode* rotateRight(ListNode* head, int n)
{
	struct ListNode* current_node = head, *t, *t2;
	int i=0,j,k;

	while (current_node != NULL)
	{
		
		current_node = current_node->next;
		i++;
	}
	
	if (i != 0)
	{
		n = n % i;
	}
	
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	for (i = 1; i <= n; i++)
	{
		current_node = head;
		while (current_node->next->next != NULL)
		{
			current_node = current_node->next;
		}
		t = current_node;
		t2 = current_node->next;

		t2->next = head;
		t->next = NULL;
		head = t2;


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
	*/
	
	struct ListNode *l = NULL;
	struct ListNode* ans = rotateRight(l,  2000000000  );
	current_node = ans;
	while (current_node != NULL)
	{
		cout << current_node->val << " ";
		current_node = current_node->next;
	}
	return 0;

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
