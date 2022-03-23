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

//TODO: 1. Detect Loop using Floyd's detection algorithm
//TODO: 2. Move the slow_ptr to the beginning of the linked list, and keep 'fast' at the 
//TODO:    meeting point.
//TODO: 2. Now, one by one, move slow and fast (at same speed). The first node where they
//TODO:    meet is the first node of the loop.
//TODO: 

void detectRemoveLoop ( Node *head)
{
    Node *slow = head , *fast = head ;

    while ( fast && fast->next )
    {
        slow = slow->next ;
        fast = fast->next->next ;

        if ( slow == fast )
            break ;
    }

    if ( slow != fast ) // No loop exists
        return ;

    slow = head ;   // Move slow back to the beginning

    while ( slow->next != fast->next )
    {
        slow = slow->next ;
        fast = fast->next ;
    }

    // Now, slow->next or fast->next is the 'first' node of the loop, so removing it will 'cut'
    // off the loop from the linked list
    fast->next = NULL ;
}

int main ()
{

}