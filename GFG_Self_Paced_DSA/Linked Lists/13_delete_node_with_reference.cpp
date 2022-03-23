# include <bits/stdc++.h>
using namespace std ;

//? We're given the reference to a random node inside a linked list.
//? We don't have info about the head, or the neighbours of the given node's linked list
//TODO: Delete this node from the linked list

//* Hint: This is a node in the middle (never the last node of the linked list)

struct Node {
    int data ;
    Node *next ;

    Node ( int x )
    {
        data = x ;
        next = NULL ;
    }
};

void delete_node ( Node *cur )
{
    Node *temp = cur->next ;    // Store the node temporarily
    cur->data = cur->next->data ; // Copy data of the next element
    cur->next = cur->next->next ;   // Breaking this code

    delete temp ; // Freeing up the memory
}