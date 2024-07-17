// binary_tree_level_order_traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<vector>
#include <deque>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode* left = NULL, * right = NULL;
};

int getindex(vector <struct TreeNode*> v1, struct TreeNode* n)
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
vector<vector<int>> levelOrder(TreeNode* root)
{
    int left_level = 0, i, j, k, current_level = 0;
    struct TreeNode* p, * bottom_lest_most = root;
    vector <struct TreeNode*> v1;
    vector <int> level;
    vector <vector<int> > v{};
    deque <struct TreeNode*> q;
    q.push_back(root);
    v1.push_back(root);
    level.push_back(0);

    if (root == NULL)
    {
        return v;
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
    //cout << bottom_left_level;
    int highest_level = level[level.size() - 1];
    j = 0;
    vector <int> temp{};
    for (i = 0; i < v1.size(); i++)
    {
        if (level[i] != j)
        {
            v.push_back(temp);
            temp = {};
            j++;
        }
        temp.push_back(v1[i]->val);

    }

    if (temp.size() != 0 )
    {
        v.push_back(temp);
    }
    return v;
}

int main()
{
    int i, j, k;
    struct TreeNode* root, * current_node, * p, * t, * t2;

    root = new(TreeNode);
    root->val = 3;
    
    root->left = new(TreeNode);
    root->left->val = 9;
    root->right = new(TreeNode);
    root->right->val = 20;
    /*
    root->left->left = new(TreeNode);
    root->left->left->val = 4;
    */
    root->right->left = new(TreeNode);
    root->right->left->val = 15;
    root->right->right = new(TreeNode);
    root->right->right->val = 7;
    /*
    root->right->left->left = new(TreeNode);
    root->right->left->left->val = 7;
    */
    vector <vector <int>> ans = levelOrder(root);
    cout << ans[0][0];
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
