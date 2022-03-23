# include <bits/stdc++.h>
using namespace std ;

struct Node {
    int data ;
    Node *next ;

    Node ( int x )
    {
        data = x ;
        next = NULL ;
    }
};

//* O(M+N) time , O(1) auxillary space

// Returns the head of the sorted linked list
Node *sorted_merge ( Node *a , Node *b )
{
    if ( a == NULL )
        return b ;
    if ( b == NULL )
        return a ;
    
    Node *head = NULL , *tail = NULL ;

    if ( a->data <= b->data )
    {
        head = tail = a ;
        a = a->next ;
    }
    else
    {
        head = tail = b ;
        b = b->next ;
    }

    while ( a && b )
    {
        if ( a->data <= b->data )
        {
            tail->next = a ;
            tail = a ;
            a = a->next ;
        }
        else
        {
            tail->next = b ;
            tail = b ;
            b = b->next ;
        }

        if ( !a )
            tail->next = b ;
        else
            tail->next = a ;
    }

    return head ;
}