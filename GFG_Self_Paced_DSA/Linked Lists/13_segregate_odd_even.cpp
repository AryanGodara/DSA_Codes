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

//? Given a singly linked list, the task is to segregate or separate the even and odd nodes.

//! Individual order of odd and even nodes must be reserved, but all the even nodes should be
//! shifted to the front of the error.

// O(2N) solution is : Move to the end of the linked list (get reference to the last node)
// Now, traverse the LL again, and everytime you encounter an 'odd' node, delete it from its
// position, and then append it to the end of the linked list

Node *segregate_even_odd ( Node *head )
{
    // Keep connecting even and odd nodes (evenstart evenend , oddstart oddend)
    Node *es = NULL , *ee = NULL ;
    Node *os = NULL , *oe = NULL ;

    for ( Node *cur = head ; cur != NULL ; cur = cur->next )    // For loop
    {
        int x = cur->data ;

        if ( x & 1 ) // Odd no
        {
            if ( es == NULL )
            {
                es = cur ;
                ee = es ;   // Start and end coincide
            }
            else
            {
                ee->next = cur ;
                ee = ee->next ; // Move it forward
            }
        }
        else
        {
            if ( os == NULL )
            {
                os = cur ;
                oe = os ;
            }
            else
            {
                oe->next = cur ;
                oe = oe->next ;
            }
        }
    }

    if ( os == NULL || oe == NULL ) // Only one type of elements (no segregation required)
        return head ;

    ee->next = os ;
    oe->next = NULL ;

    return es ;
}