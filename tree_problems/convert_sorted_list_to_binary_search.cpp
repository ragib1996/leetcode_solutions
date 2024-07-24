// convert_sorted_list_to_binary_search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<deque>
#include<vector>
#include <algorithm>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct TreeNode
{
	int val;
	struct TreeNode* left, * right;
};


ListNode* Mid(ListNode* l, ListNode* h)
{
	ListNode* slow = l, * fast = l;
	while (fast != h && fast->next != h)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


TreeNode* Convert(ListNode* l, ListNode* h)
{
	if (l == h) return nullptr;

	ListNode* m = Mid(l, h);
	TreeNode* a = new (TreeNode);
	a->val = m->val; ;

	a->left = Convert(l, m);
	a->right = Convert(m->next, h);
	return a;
}


TreeNode* sortedListToBST(ListNode* head) 
{
	return Convert(head, nullptr);
}



// Find's Middle Node Of List !

		


int main()
{

	struct ListNode* head, * p, * current_node;
	head = new (ListNode);
	head->val = -10;
	head->next = NULL;
	current_node = head;

	p = new(ListNode);
	p->val = -3;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;

	p = new(ListNode);
	p->val = 0;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	
	p = new(ListNode);
	p->val = 5;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;

	p = new(ListNode);
	p->val = 9;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	/*
	p = new(ListNode);
	p->val = 2;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	*/
	struct TreeNode * ans = sortedListToBST(head);


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
