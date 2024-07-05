/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


struct node 
{
  int val;
  struct node *next;
};


node* addTwoNumbers(node* l1, node* l2)
{
 
    struct node *p1= l1, *p2 = l2, * ans_head = NULL, *c_ans_node = NULL, *p;
    int c = 0, s= 0;
    
    while (p1 != NULL && p2 != NULL)
    {
        s = c + p1->val + p2->val;
        if (ans_head == NULL)
        {
            ans_head = new(node);
            ans_head->val = s%10;
            ans_head->next = NULL;
            c_ans_node = ans_head;
        }
        else
        {
            c_ans_node->next = new(node);
            c_ans_node->next->val = s%10;
            c_ans_node = c_ans_node->next;
            c_ans_node->next = NULL;
        }
        c = s/10;
        p1 = p1->next;
        p2 = p2->next;
        
    }
    
    if (p1 != NULL)
    {
        p = p1;
    }
    if (p2 != NULL)
    {
        p = p2;
    }
    
    while ( p != NULL)
    {
        s = c + p->val;
        c_ans_node->next = new(node);
        c_ans_node->next->val = s%10;
        c_ans_node = c_ans_node->next;
        c_ans_node->next = NULL;
        c = s/10;
        p = p->next; 
        
    }
    
    if (p == NULL && c != 0 )
    {
        c_ans_node->next = new(node);
        c_ans_node->next->val = c;
        c_ans_node = c_ans_node->next;
        c_ans_node->next = NULL;
    }
    
    p = ans_head;
    
    /*
    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next; 
    }
    */
    
    return p;
    
         
}


int main()
{
        
    struct node *head, *current_node, *p, *head2;
    
    head = new(node);
    head-> val = 9;
    head->next = NULL;
    
    current_node = new(node);
    current_node->val = 9;
    current_node->next = NULL;
    head->next = current_node;
    
    p  = new(node);
    p->val = 9;
    p->next = NULL;
    current_node->next = p;
    current_node = p;
    
    p  = new(node);
    p->val = 9;
    p->next = NULL;
    current_node->next = p;
    current_node = p;
    
    
    p  = new(node);
    p->val = 9;
    p->next = NULL;
    current_node->next = p;
    current_node = p;
    
    p  = new(node);
    p->val = 9;
    p->next = NULL;
    current_node->next = p;
    current_node = p;
    
    p  = new(node);
    p->val = 9;
    p->next = NULL;
    current_node->next = p;
    current_node = p;
    
    
        
    head2 = new(node);
    head2-> val = 9;
    head2->next = NULL;
    
    current_node = new(node);
    current_node->val = 9;
    current_node->next = NULL;
    head2->next = current_node;
    
    p  = new(node);
    p->val = 9;
    p->next = NULL;
    current_node->next = p;
    current_node = p;
    
    p  = new(node);
    p->val = 9;
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
    
    
    p = head2;
    while(p!= NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << "\n";
    
    node * ans = addTwoNumbers(head, head2);
    
    p = ans;
    while (p != NULL)
    {
        cout << p->val << " ";
        p = p->next; 
    }
    
    return 0;
}