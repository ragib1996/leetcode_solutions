// course_schedule_207.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
#include<unordered_map>
#include<vector>
#include<deque>

using namespace std;

struct Node
{
    int val;
    vector <struct Node*> p;
};

bool iscycle(struct Node* course_j, struct Node* course_k)
{
    struct Node *current_node = course_j;
    deque <struct Node*>q;
    q.push_back(current_node);

    while (q.size() != 0)
    {
        vector <struct Node*> v = q[0]->p;

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == course_k)
            {
                return false;
            }
            q.push_back(v[i]);
        }
        q.pop_front();
    }
    /*
    while (current_node != NULL)
    {
        current_node = current_node->p;
        if (current_node == course_k)
        {
            return false;
        }
    }
    */
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    int i, j, k;
    unordered_map <int, int> um;
    struct Node* courses[2000];

    for (i = 0; i < numCourses; i++)
    {
        courses[i] = new(Node);
        courses[i]->val = i;
        courses[i]->p = {};
    }

    for (i = 0; i < prerequisites.size(); i++)
    {
        j = prerequisites[i][0];
        k = prerequisites[i][1];


        courses[k]->p.push_back(courses[j]) ;
        bool b = iscycle(courses[j], courses[k]);
        if (b == false)
        {
            return b;
        }
        
    }

    return true;
}

int main()
{
    int numCourses = 2;
    vector < vector <int> > v{   {1,0} };

    bool ans = canFinish(numCourses, v);
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
