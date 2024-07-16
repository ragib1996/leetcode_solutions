// validate_bst.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include<deque>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode* left = NULL, * right = NULL;
};

bool f(TreeNode* root, TreeNode* n)
{
    struct TreeNode* current_node, * p, * t, * t2;
    current_node = root;
    while (current_node != NULL)
    {
        if (current_node == n)
        {
            return true;
        }
        if (current_node != n && current_node->val == n->val)
        {
            return false;
        }
        if (n->val < current_node->val)
        {
            current_node = current_node->left;
        }
        else if (n->val > current_node->val)
        {
            current_node = current_node->right;
        }
    }
    return false;
}

bool isValidBST(TreeNode* root)
{
    deque < struct TreeNode*> q;
    bool b;
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return true;
    }
    q.push_back(root);
    while (q.size() != 0)
    {
        if (q[0]->left != NULL)
        {
            if (q[0]->left->val < q[0]->val)
            {
                b = f(root, q[0]->left);
                if (b == false)
                {
                    return false;
                }
                q.push_back(q[0]->left);
            }
            else
            {
                break;
            }
        }
        if (q[0]->right != NULL)
        {
            if (q[0]->right->val > q[0]->val)
            {
                b = f(root, q[0]->right);
                if (b == false)
                {
                    return false;
                }
                q.push_back(q[0]->right);
            }
            else
            {
                break;
            }
        }
        q.pop_front();

    }
    if (q.size() == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    int i, j, k;
    struct TreeNode* root, *current_node, * p, * t, * t2;

    root = new(TreeNode);
    root->val = 3;

    root->left = new(TreeNode);
    root->left->val = 1;
    root->right = new(TreeNode);
    root->right->val = 5;

    root->left->left = new(TreeNode);
    root->left->left->val = 0;
    root->left->right = new(TreeNode);
    root->left->right->val = 2;

    root->right->left = new(TreeNode);
    root->right->left->val = 4;
    root->right->right = new(TreeNode);
    root->right->right->val = 6;

    root->left->right->right = new(TreeNode);
    root->left->right->right->val = 3;

    
    bool ans = isValidBST(root);
    cout << ans;
    

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
