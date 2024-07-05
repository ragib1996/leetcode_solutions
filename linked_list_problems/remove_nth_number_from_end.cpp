#include <iostream>
#include <bits/stdc++.h>

using namespace std;


struct node 
{
  int val;
  struct node *next;
};

node * removeNthFromEnd (struct node * head, int n)
{
    struct node * current_node = head, *p;
    
    int i=0;
    
    while ( current_node != NULL )
    {
        current_node = current_node->next;
        i++;
    }
    int l = i;
    //cout << i << "\n";
    int m = i - n +1;
    i = 1;
    current_node = head;
    while( i != m-1 && m != 1 )
    {
        current_node = current_node->next;
        i++;
    }
     
    
    if ( m == 1 )
    {
        head = head->next;
        current_node->next = NULL;
        return head;
    }
    if ( i == l-1)
    {
        current_node->next = NULL;
        return head;
    }
    
    cout << "\n";
    p = current_node->next;
    current_node->next = p->next;
    p-> next = NULL;
    
    return head;
}


int main()
{
    
    struct node *head, *current_node, *p;
    int n = 2;
    
    head = new(node);
    head-> val = 1;
    head->next = NULL;
    
    current_node = new(node);
    current_node->val = 2;
    current_node->next = NULL;
    head->next = current_node;
    
    p  = new(node);
    p->val = 3;
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
    
    
    p =   removeNthFromEnd( head, 1 );

    while( p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    return 0;
}