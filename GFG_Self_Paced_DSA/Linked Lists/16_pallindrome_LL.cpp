# include <bits/stdc++.h>
using namespace std ;

// Get to the middle of the linked list, using slow and fast pointer
// Reverse the linked list after the middle node
// Traverse from head, and last node, until they point to the same node, and then check
// If values on the left and right are equal

struct Node {
    int data ;
    Node *next ;

    Node ( int x )
    {
        data = x ;
        next = NULL ;
    }
};

Node *reverseLL ( Node *head )
{
    Node *cur = head , *prev = NULL ;

    while ( cur != NULL )
    {
        Node *next = cur->next ;
        cur->next = prev ;
        prev = cur ;
        cur = next ;
    }

    return head ;
}

bool isPallindrome ( Node *head )
{
    if ( !head )
        return true ;
    
    Node *slow = head , *fast = head ;

    while ( fast->next && fast->next->next )
    {
        slow = slow->next ;
        fast = fast->next->next ;
    }

    Node *rev = reverseLL(slow->next) , *cur = head ;

    while ( rev != NULL )
    {
        if ( rev->data != cur->data )
            return false ;
        
        rev = rev->next ;
        cur = cur->next ;
    }

    return true ;
}