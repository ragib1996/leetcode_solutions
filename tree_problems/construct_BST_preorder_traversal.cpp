// construct_BST_preorder_traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iostream>
#include<stdio.h>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode* left, * right;
};

void f(struct TreeNode * t , int n )
{
    if (n < t->val && t->left != NULL)
    {
        f(t->left, n);
    }
    else if (n < t->val)
    {
        t->left = new(TreeNode);
        t->left->val = n;
        t->left->left = NULL;
        t->left->right = NULL;
    }
    else if (n > t->val && t->right != NULL)
    {
        f(t->right, n);
    }
    else
    {
        t->right = new(TreeNode);
        t->right->val = n;
        t->right->left = NULL;
        t->right->right = NULL;
    }
}

TreeNode* bstFromPreorder(vector<int>& preorder)
{
    struct TreeNode* ans = NULL;
    int i, j, k;
    for (i = 0; i < preorder.size(); i++)
    {
        if (i == 0)
        {
            ans = new(TreeNode);
            ans->left = NULL;
            ans->right = NULL;
            ans->val = preorder[i];
            continue;
        }
        f(ans, preorder[i]);
        
    }
    return ans;

}

int main()
{
    int i, j, k;
    vector <int> preorder { 8, 5, 1, 7, 10, 12 };

    struct TreeNode* ans = bstFromPreorder(preorder);
    cout << ans->val;

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
