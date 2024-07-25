// clone_graph_my_tiral.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<list>
#include<unordered_map>
#include<stack>
#include<vector>

using namespace std;

struct Node {
    int val;
    vector <struct Node* > neighbors{};
};

Node* cloneGraph(Node* node)
{
    if (node == NULL)
    {
        return node;
    }
    struct Node* n, * p, *p1, *temp;
    int i, j, k;
    unordered_map < struct Node*, struct Node* > um;
    stack <struct Node*> s, s1;
    struct Node * ans = new(Node);
    ans->val = node->val;

    um[node] = ans;
    s.push(node);
    s1.push(ans);

    while (s.size() != 0)
    {
        p = s.top();
        s.pop();
        p1 = s1.top();
        s1.pop();

        vector <struct Node * > l = p->neighbors;
        while (l.size() != 0)
        {
            n = l.back();
            if (um.find(n) == um.end()) // if not present
            {
                temp = new(Node);
                temp->val = n->val;
                p1->neighbors.push_back(temp);
                s1.push(temp);
                s.push(n);
                um[n] = temp;
            }
            else
            {
                p1->neighbors.push_back(um[n]);
            }
            l.pop_back() ;
        }
    }


    return ans;
}
int main()
{
    struct Node* head = new(Node);
    head->val = 1;
    
    struct Node* head2 = new(Node);
    head2->val = 2;

    struct Node* head3 = new(Node);
    head3->val = 3;

    struct Node* head4 = new(Node);
    head4->val = 4;

    head->neighbors.push_back(head2);
    head->neighbors.push_back(head4);

    head2->neighbors.push_back(head);
    head2->neighbors.push_back(head3);

    head3->neighbors.push_back(head2);
    head3->neighbors.push_back(head4);

    head4->neighbors.push_back(head3);
    head4->neighbors.push_back(head);
    
    struct Node* ans = cloneGraph(head);

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
