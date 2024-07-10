// flatten_binary_tree_to_lined_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <deque>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode * left= NULL, *right = NULL;
};

void flatten(struct TreeNode* head)
{

    stack <struct TreeNode* > s;
    struct TreeNode* current_node, * p, * t, * t2;
    current_node = head;

    if (current_node == NULL)
    {
        return;
    }

    while (current_node != NULL)
    {
        if (current_node->right != NULL)
        {
            s.push(current_node->right);
        }
 
        current_node->right = current_node->left;
        current_node->left = NULL;
        if (current_node->right == NULL && s.empty() == false)
        {
            current_node->right = s.top();
            s.pop();
            current_node = current_node->right;
        }
        else
        {
            current_node = current_node->right;
        }
       
    }

     
}

int main()
{
    struct TreeNode* head, * current_node, * p;
    
    head = new(TreeNode);
    head->val = 1;
    
    head->left = new(TreeNode);
    head->left->val = 2;
    head->right = new(TreeNode);
    head->right->val = 5;

    head->left->left = new(TreeNode);
    head->left->left->val = 3;
    head->left->right = new(TreeNode);
    head->left->right->val = 4;

    head->right->right = new(TreeNode);
    head->right->right->val = 6;
    
    flatten(head);

    current_node = head;


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
