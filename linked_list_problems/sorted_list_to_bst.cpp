

#include <iostream>
#include<stdio.h>

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

struct ListNode* mid(ListNode* l, ListNode* h)
{
	struct ListNode* fast = l, * slow = l;
	while (fast != h && fast->next != h)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

struct TreeNode* convert(ListNode* l, ListNode* h)
{
	struct TreeNode* a = NULL;
	if (l == h)
	{
		return NULL;
	}
	struct ListNode* m = mid(l, h);
	a = new(TreeNode);
	a->val = m->val;

	a->left = convert(l, m);
	a->right = convert(m->next, h);


	return a;
}

struct TreeNode* sortedListToBST(ListNode* head)
{
	int i = 0;
	struct TreeNode* a = NULL, * p;

	a = convert(head, NULL);


	return a;
}
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
	/*
	p = new(ListNode);
	p->val = 5;
	p->next = NULL;
	current_node->next = p;
	current_node = current_node->next;
	*/
	current_node = head;
	struct TreeNode* ans = sortedListToBST(head);
	struct TreeNode *current_tree = ans;
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
