/*
Doubly Linked Lists are also a sequential data structure with the only difference that doubly linked
lists contains two pointers instead of one to store the address of both next node and previous 
node respectively.
*/
# include <bits/stdc++.h>
using namespace std ;

/*
Advantages of Doubly Linked Lists :-

1. A DLL can be traversed in both forward and backward directions.
2. The delete operation in DLL is more efficient if the pointer to the node to be deleted is given.
3. We can quickly insert a new node be
4. In a singly linked list, to delete a node, a pointer to the previous node is needed. To get this
   previous node, sometimes the lsit is traversed. In DLL, we can get the previous node using the
   previous pointer.

Disadvantages of Doubly Linked Lists :-

1. Extra space is required for the extra pointer.
2. All operations require an extra pointer previous to be maintained.
*/


// Creating and Traversing a DLL


// Node of a doubly linked list
struct Node
{
    int data ;
    struct Node* next ;     // Pointer to next node in DLL
    struct Node* prev ;     // Pointer to previous node in DLL
} ;

// This function prints the content of the DLL, list starting from the given node
void printList ( struct Node* node )
{
    struct Node* last ;

    // Traverse the linked list in forward direction using at the next node's pointer present 
    // at each node
    cout << endl << "Traversal in forward direction " << endl ;

    while ( node != NULL )
    {
        cout << node -> data << " " ;
        last = node ;
        node = node -> next ;
    }

    // Traverse the linked list in reversion direction using the previous pointer
    cout << endl << "Traversal in reverse direction " << endl ;
    
    while ( last != NULL )
    {
        cout << last -> data << " " ;
        last = last -> prev ;
    }
}

// Given a reference to the head of the DLL and an int, this function inserts a new node at the end
void append ( struct Node** head_ref , int new_data )
{
    // 1. Allocate node
    Node* new_node = new Node ;
    struct Node* last = *head_ref ;     // Used in step 5

    // Put in the data
    new_node -> data = new_data ;
    
    // 3. This new node is going to be the last node, so make its next, NULL
    new_node -> next = NULL ;

    // 4. If the linked list is empty, then make the new node as hea
    if ( *head_ref == NULL )
    {
        new_node -> prev = NULL ;
        *head_ref = new_node ;
        return ;
    }

    // 5. Else traverse till the last node
    while ( last -> next != NULL )
        last = last-> next ;

    // 6. Change the next of last node
    last -> next = new_node ;

    // 7. Make last node as previous of new node
    new_node -> prev = last ;

    return  ;
}


// Driver program to test above functions
int main ()
{
    // Start with the empty lsit
    struct Node* head = NULL ;

    // Insert 6. so the linked list becomes 6->NULL
    append(&head,6) ;

    // Insert 6. so the linked list becomes 6->7->NULL
    append(&head,7) ;

    // Insert 1. so the linked list becomes 6->7->1->NULL
    append(&head,1) ;

    // Insert 4. so the linked list becomes 6->7->1->4->NULL
    append(&head,4) ;

    cout << "Created DLL is : \n" ;
    printList(head) ;

    return 0 ;
}