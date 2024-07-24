// populating_next_right_pointer_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <deque>
#include<vector>

using namespace std;

struct Node {
    int val;
    Node* left = NULL;
    Node* right = NULL;
    Node* next = NULL;
};

int getindex(vector <struct Node*> v1, struct Node* n)
{
    int i, j, k;
    for (i = 0; i < v1.size(); i++)
    {
        if (v1[i] == n)
        {
            return i;
        }
    }

    return -1;
}

Node* connect(Node* root) 
{
    int left_level = 0, i, j, k, current_level = 0;
    struct Node* p, * bottom_lest_most = root;
    vector <struct Node*> v1;
    vector <int> level;
    vector <vector<int> > v{};
    deque <struct Node*> q;
    q.push_back(root);
    v1.push_back(root);
    level.push_back(0);
    
    if (root == NULL)
    {
        return root;
    }
    
    while (q.size() != 0)
    {
        if (q[0]->left != NULL)
        {
            i = getindex(v1, q[0]);
            q.push_back(q[0]->left);
            v1.push_back(q[0]->left);
            level.push_back(level[i] + 1);

        }
        if (q[0]->right != NULL)
        {
            i = getindex(v1, q[0]);
            q.push_back(q[0]->right);
            v1.push_back(q[0]->right);
            level.push_back(level[i] + 1);

        }
        q.pop_front();
    }
    current_level = 0;
    int h_level = level[level.size() - 1];
    root->next = NULL;
    for (i = 1; i < v1.size(); i++)
    {
        if (level[i] > current_level)
        {
            v1[i - 1]->next = NULL;
            current_level++;
            continue;
        }
        v1[i - 1]->next = v1[i];
    }
    
    v1[i - 1]->next = NULL;

    return root;
}

int main()
{
    struct Node* head = new(Node);
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
    //head->right->left = new(Node);
    //head->right->left->val = 6;
    head->right->right = new(Node);
    head->right->right->val = 7;

    struct Node* ans = connect(head);

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
