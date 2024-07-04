/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


struct node 
{
  int val;
  struct node *next;
};

node* mergeNodes(node* head)
{
    
    struct node *current_node = head->next, *c_ans = NULL, *ans = NULL, *p;
    int s = 0;
    while (current_node != NULL)
    {
        s = 0;
        while (current_node->val != 0)
        {
            s = s + current_node->val;
            current_node= current_node->next;
        }
        
        if (ans == NULL)
        {
            ans = new(node);
            ans->val = s;
            ans->next = NULL;
            c_ans = ans;
        }
        else
        {
            p = new(node);
            p->val = s;
            p->next = NULL;
            c_ans->next = p;
            c_ans = p;
        }
        current_node = current_node->next;
        
    }
    
    return ans;

}

int main()
{
    //list <int> a  {0,3,1,0,4,5,2,0};
    struct node *head, *current_node, *p;
    
    head = new(node);
    head-> val = 0;
    head->next = NULL;
    
    current_node = new(node);
    current_node->val = 3;
    current_node->next = NULL;
    head->next = current_node;
    
    p  = new(node);
    p->val = 1;
    p->next = NULL;
    current_node->next = p;
    current_node = p;
    
    p  = new(node);
    p->val = 0;
    p->next = NULL;
    current_node->next = p;
    current_node = p;
    
    
    p  = new(node);
    p->val = 4;
    p->next = NULL;
    current_node->next = p;
    current_node = p;
    
    p  = new(node);
    p->val = 5;
    p->next = NULL;
    current_node->next = p;
    current_node = p;
    
    p  = new(node);
    p->val = 2;
    p->next = NULL;
    current_node->next = p;
    current_node = p;
    
    p  = new(node);
    p->val = 0;
    p->next = NULL;
    current_node->next = p;
    current_node = p;
    
    p = head;
    while(p!= NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << "\n";
    struct node *ans = mergeNodes(head); 
    
    current_node = ans;
    while(current_node!= NULL)
    {
        cout << current_node->val << " ";
        current_node = current_node-> next;
    }
    /*
    for (int i = 0; i< a.size() ; i++)
    {
        if (i == 0)
        {
            current_node = new(node);
            head = current_node;
            head->val = a[i];
            head->next = NULL;
            continue;
        }
        
        p = new (node);
        p->val =  a[i];
        p->next = NULL;
        current_node -> next = p;
        current_node = p;
        
        
        
    }
    */

    return 0;
}