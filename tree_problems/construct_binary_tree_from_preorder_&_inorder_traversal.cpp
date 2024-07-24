// construct_binary_tree_from_preorder_&_inorder_traversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode* left, * right;
};

int preorder_index = -1;
int findindex(vector<int> inorder, int left, int right, int value)
{
    int i, j, k;
    for (i = left; i <= right; i++)
    {
        if (inorder[i] == value)
        {
            return i;
        }
    }

    return -1;
}

TreeNode* convert(vector <int> preorder,  vector <int> inorder, int inorder_left, int inorder_right)
{

    if ( inorder_right < inorder_left || inorder_right >= inorder.size()  )
    {
        return NULL;
    }
    preorder_index++;
    struct TreeNode *a = new(TreeNode);
    a->val = preorder[preorder_index];
    int index = findindex (inorder, inorder_left, inorder_right, preorder[preorder_index]);
    a->left = convert(preorder, inorder, inorder_left, index-1);
    a->right = convert(preorder,  inorder, index + 1, inorder_right);

    return a;
}


TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder)
{
    struct TreeNode* ans = convert(preorder,  inorder, 0, inorder.size()- 1 );
    return ans;
}

int main()
{
    //vector <int> preorder { 3,9,1,2,20,15,7 };
    //vector<int> inorder{ 1,9,2,3,15,20, 7 };

    vector <int> inorder{ 4,2,1,7,5,8,3,6 };
    vector <int> preorder {1,2,4,3,5,7,8,6};

    //cout << preorder.size() << " " << inorder.size();
    struct TreeNode * ans = buildTree(preorder, inorder);
    cout << ans->val;
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
