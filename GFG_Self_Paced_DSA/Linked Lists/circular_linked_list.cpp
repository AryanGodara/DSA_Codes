/*
A circular linked list is a linked list where all nodes are connected to form a circle. There is no
NULL at the end. A circular linked list can be singly circular linked list or a DCLL.
*/
# include <bits/stdc++.h>
using namespace std ;


// Implementation
/*
To implement a circular singly linked list, we take an external pointer that points to the last
node of the list. If we have a pointer last pointing to the last node, then last-> next will point
to the firs node.
*/

// Why have we taken a pointer that points to the last node instead of first node?
/*
For insertion of node in the beginning we need traverse the whole list. Also, for insertion at the
end, the whole lsit has to traverseed. If instead of start pointer, we take a pointer to the last node
then in both cases there won't be any need to traverse the whole list. So, insertion in the 
beginning or at the end takes constant time irrespective of the end of the list
*/

// Implementation of Circular Linked List :-

// Circular linked list node :
struct Node
{
    int data ;
    struct Node* next ;
} ;

// Function to add a node at the end of a circular linked list
struct Node* addEnd ( struct Node* last , int data )
{
    if ( last == NULL )
    {
        // Creating a node dynamically
        struct Node* temp = new Node ;

        // Assigning the data
        temp -> data = data ;
        last = temp ;

        return last ;
    }

    struct Node* temp = new Node ;

    temp -> data = data ;
    temp -> next = last-> next ;        // Points to the head of the linked list
    last -> next = temp ;
    last = temp ;

    return last ;
}

// Function to traverse Circular linked list using a pointer to the last node
void traverse ( struct Node* last )
{
    struct Node* p ;

    // If list is empty, return.
    if ( last == NULL )
    {
        cout << "The list is empty\n" ;
        return ;
    }

    // Pointing to the first node of the list
    p = last -> next ;

    // Traversing the list
    do
    {
        /* code */
        cout << p -> data << " " ;
        p = p -> next ;
    } while (p != last -> next) ;   // p != head_ptr
}

// Driver Program
int main ()
{
    struct Node* last = NULL ;

    last = addEnd(last,6) ;
    last = addEnd(last,4) ;
    last = addEnd(last,2) ;
    last = addEnd(last,8) ;
    last = addEnd(last,12) ;
    last = addEnd(last,61) ;

    traverse (last) ;

    return 0 ;
}