// populating_next_right_pointer_in_each_node.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<deque>>
#include<queue>

using namespace std;

struct Node {
    int val;
    Node* left= NULL;
    Node* right = NULL ;
    Node* next = NULL ; 
};


Node* connect(Node* root)
{
    struct Node* current_node, * t, * t2;
    int i, j, k;
    if (root == NULL)
    {
        return root;
    }
    current_node = root;
    root->next = NULL;
    while (current_node->left)
    {
        current_node->left->next = current_node->right;

        t = current_node;
        while (t->next)
        {
            t->right->next = t->next->left;
            t = t->next;
            t->left->next = t->right;
        }

        current_node = current_node->left;
    }

    return root;

}


int main()
{
    struct Node *head = new(Node);
    head->val = 1;
    // level 1
    head->left = new(Node);
    head->left->val = 2;
    head->right = new(Node);
    head->right->val = 3;
    // level 2
    head->left->left = new(Node);
    head->left->left->val = 4;
    head->left->right = new(Node);
    head->left->right->val = 5;
    head->right->left = new(Node);
    head->right->left->val = 6;
    head->right->right = new(Node);
    head->right->right->val = 7;

    struct Node * ans = connect(head);
    struct Node* current_node = ans;
    struct Node* temp = NULL;

    while (current_node != NULL)
    {
        temp = current_node;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        current_node = current_node->left;
        cout << "\n";
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
