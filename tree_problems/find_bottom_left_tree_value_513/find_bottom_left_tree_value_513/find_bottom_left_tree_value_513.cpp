// find_bottom_left_tree_value_513.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<vector>
#include <deque>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode* left= NULL, * right= NULL;
};

int getindex(vector <struct TreeNode*> v1 , struct TreeNode* n )
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
int findBottomLeftValue(TreeNode* root)
{
    int left_level = 0,i,j,k, bottom_left_level = 0;
    struct TreeNode* p, *bottom_lest_most = root;
    vector <struct TreeNode*> v1;
    vector <int> level;
    deque <struct TreeNode*> q;
    q.push_back(root);
    v1.push_back(root);
    level.push_back(0);

    while (q.size() != 0)
    {
        if (q[0]->left != NULL)
        {
            i = getindex(v1, q[0]);
            q.push_back(q[0]->left);
            v1.push_back(q[0]->left);
            level.push_back(level[i] + 1);
            if ( level[ level.size() - 1] > bottom_left_level)
            {
                bottom_left_level++;
                bottom_lest_most = q[0]->left;
            } 
        }
        if (q[0]->right != NULL)
        {
            i = getindex(v1, q[0]);
            q.push_back(q[0]->right);
            v1.push_back(q[0]->right);
            level.push_back(level[i] + 1);
            if (level[level.size() - 1] > bottom_left_level)
            {
                bottom_left_level++;
                bottom_lest_most = q[0]->right;
            }
        }
        q.pop_front();
    }
    //cout << bottom_left_level;
    return bottom_lest_most->val;
}

int main()
{
    int i, j, k;
    struct TreeNode* root, * current_node, * p, * t, * t2;

    root = new(TreeNode);
    root->val = 1;

    root->left = new(TreeNode);
    root->left->val = 2;
    root->left = NULL;
    root->right = new(TreeNode);
    root->right->val = 1;
    /*
    root->left->left = new(TreeNode);
    root->left->left->val = 4;

    root->right->left = new(TreeNode);
    root->right->left->val = 5;
    root->right->right = new(TreeNode);
    root->right->right->val = 6;

    root->right->left->left = new(TreeNode);
    root->right->left->left->val = 7;
    */
    int ans =  findBottomLeftValue(root);
    cout << ans;
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
