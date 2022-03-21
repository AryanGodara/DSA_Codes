//? Remove duplicates from sorted linked list

# include <bits/stdc++.h>
using namespace std ;

struct Node {
    int data ;
    Node *next ;

    Node ( int x ) {
        data = x ;
        next = NULL ;
    }
};

void remove_duplicates ( Node *head )
{
    Node *cur = head ;

    while ( cur && cur->next )
    {
        if ( cur->data == cur->next->data )
        {
            Node *temp = cur->next ;
            cur->next = cur->next->next ;
            delete (temp) ;
        }
        cur = cur->next ;
    }
}