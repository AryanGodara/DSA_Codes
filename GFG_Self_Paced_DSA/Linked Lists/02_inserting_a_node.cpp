/*
There can be many different situations that arise while
inerting a node in a linked list. Three most frequent
situations are :-
1. inserting a node at the start of the list
2. inserting a node after any given node in the list
3. inseting a node at the end of the list
*/
# include <bits/stdc++.h>
using namespace std ;

// A linked list node
struct Node
{
    int data ;
    struct Node *next ;
} ;


// Inserting a node at the beginning is a 4 step process.
void push_front ( struct Node** head_ref , int new_data )
{
    // head is already a pointer, so **head_ref, is a
    // pointer to that pointer

    // 1. allocate new node
    Node* new_node = new Node ;

    // 2. put in the data
    new_node -> data = new_data ;

    // 3. make next of new node as head
    new_node -> next = (*head_ref) ;

    // 4. move the head to point to the new head
    (*head_ref) = new_node ;
}
// Time complexity = O(1).


// Inserting a node after given node
// Given a reference (pointer to pointer) and the data
void insertAfter ( struct Node* prev_node , int new_data )
{
    // 1. check if the given previous node is NULL
    if ( prev_node == NULL )
    {
        cout << "The given previous node can't be null\n" ;
        return ;
    }

    // 2. allocate new node
    Node* new_node = new Node ;

    // 3. put in the data
    new_node -> data = new_data ;

    // 4. make next of new node as next of prev_node
    new_node -> next = prev_node -> next ;

    // 5. move the next of prev_node to new_node
    prev_node -> next = new_node ;
}
// Time complexity = O(1)


// Inserting at the end
void append ( struct Node** head_ref , int new_data )
{
    // 1. allocate node
    Node* new_node = new Node ;

    struct Node* last = *head_ref ; // used in step 5

    // 2. put in the data
    new_node -> data = new_data ;

    // 3. this new node is going to be the last node,
    //    so make next of it as NULL
    new_node -> next = NULL ;

    // 4. if the linked list is empty, then make the new
    //    node the head node
    if ( *head_ref == NULL )
    {
        *head_ref = new_node ;
        return ;
    }

    // 5. else traverse till the last node
    while ( last -> next != NULL )
        last = last -> next ;
    
    // 6. change the next of last node
    last -> next = new_node ;
    
    return ;
}
// Time complexity = O(N)
// Where, n is the number of nodes in the linked list.