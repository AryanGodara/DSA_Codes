/*
Given the head pointer pointing to the head of a singly
linked list, and a node to be deleted from the list. Delete
the given node from the linked list
*/
# include <bits/stdc++.h>
using namespace std ;

// A linked list node
struct Node
{
    int data ;
    struct Node *next ;
} ;



/*
Like inserting a node in a linked list, there can be many situations when it comes 
to deleting a node from a linked list. Some of th emost frequent situations are :
1. Given the data value of a node, delete the first occurence of that data in the list
2. Given the position of a node, delete the node present at the given position in the list
3. Given a pointer to the node to be deleted, delete the node
*/

// Deleting the first occurence of the element

// Given a reference (pointer to pointer) to the head of the list and a key, delete the first occurence of key in linked list
void deleteNode ( struct Node **head_ref , int key )
{
    // Store head node
    struct Node* temp = *head_ref ;
    struct Node* prev ;

    // If head node itself holds the key to be deleted
    if ( temp != NULL && temp -> data == key )
    {
        *head_ref = temp -> next ;  // Change head
        free(temp) ;                // free old head
        return ;
    }

    // Search for the key to be deleted, keep track of the previous node as we need to change 'prev->next'
    while ( temp != NULL && temp->data != key )
    {
        prev = temp ;
        temp = temp -> next ;
    }

    // If key was not present in the linke list
    if ( temp == NULL )
        return ;
    
    // Unlink the node from the linked list
    prev -> next = temp -> next ;
    free(temp) ;    // Free the memory
}
// Time Complexity = O(N)


// Deleting a node at a given position

// Given a reference (pointer to pointer) to the head of a list and a position
void deleteNode ( struct Node** head_ref , int position )
{
    // If linked list is empty
    if ( *head_ref == NULL )
        return ;

    // Store head node
    struct Node* temp = *head_ref ;

    // If head needs to be removed
    if ( position == 0 )
    {
        *head_ref = temp -> next ;  // Change head
        free(temp) ;            // Free old head
        return ;
    }

    // Find the previous node to be deleted
    for ( int i = 0 ; temp != NULL && i < position ; i++ )
        temp = temp -> next ;
    
    // If position is more than the number of nodes
    if ( temp == NULL && temp -> next == NULL )
        return ;

    // Node temp->next of the node to be deleted
    // Store pointer to the next of node to be deleted
    struct Node* next = temp -> next -> next ;

    // Unlink the node from linked list
    free (temp-> next) ;    // Free memory

    temp -> next = next ;   // Unlink the deleted node from list
}


// Deleting a node whose pointer is given
/*
The efficient solution is to copy the data from the next node to the node to be deleted and delete
the next node. Suppose the node to be delted is node_ptr, it can be deleted as :-
*/
// struct Node* node_ptr = the_pointer_which_has_to_be_deleted ;
void delete_ptr ( struct Node* node_ptr )
{
    // Find next node using next pointer
    struct Node* temp = node_ptr -> next ;

    // Copy data of next node to this node
    node_ptr -> data = temp -> data ;

    // unlink next node
    node_ptr -> next = temp -> next ;

    // Delete next node
    free(temp) ;
}
// Note: This solution fails if the node to be deleted is the last node of the list