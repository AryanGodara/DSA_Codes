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
end, the whole list has to traverseed. If instead of start pointer, we take a pointer to the last 
node then in both cases there won't be any need to traverse the whole list. So, insertion in 
the beginning or at the end takes constant time irrespective of the end of the list.
*/

// Implementation of Circular Linked List :-

// Circular linked list node :
struct Node
{
    int data ;
    struct Node* next ;

    Node ()
    {
        next = NULL ;
    }

    Node ( int x )
    {
        data = x ;
        next = NULL ;
    }
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
        cout << p -> data << " " ;
        p = p -> next ;
    } while (p != last -> next) ;   // p != head_ptr
}


void traverse_for ( Node *head )
{
    if ( head == NULL )
        return ;
    
    cout << head->data << " " ;

    for ( Node *cur = head->next ; cur != head ; cur = cur->next )
        cout << cur->data << " " ;
    
    cout << endl ;
}

void traverse_do_while ( Node *head )
{
    if ( head == NULL )
        return ;
    
    Node *p = head ;

    do {
        cout << p->data << " " ;
        p = p->next ;
    } while ( p != head ) ;

    cout << endl ;
}

Node *insert_begin_naive ( Node *head , int x )
{
    Node *temp = new Node(x) ;

    if ( head == NULL )
        temp->next = temp ;
    else
    {
        Node *cur = head ;
        while ( cur->next != NULL )
            cur = cur->next ;
        
        cur->next = temp ;
        temp->next = head ;
    }

    return temp ;
}

Node *insert_begin_efficient ( Node *head , int x )
{
    Node *temp = new Node(x) ;

    if ( head == NULL )
    {
        temp->next = temp ;
        return temp ;
    }
    else
    {
        temp->next = head->next ;
        head->next = temp ;
        //* temp was connected between head and head->next ;
        int t = head->data ;
        head->data = temp->data ;
        temp->data = t ;
        //* simply swapped the data of temp and head

        return head ;
    }
}

Node *insert_end_naive ( Node *head , int x )
{
    Node *temp = new Node(x) ;

    if ( head == NULL )
    {
        temp->next = temp ;
        return temp ;
    }
    else
    {
        Node *cur = head ;

        while ( cur->next != NULL )
            cur = cur->next ;
        
        temp->next = cur->next ; // == head
        cur->next = temp ;

        return head ;
    }
}

Node *insert_end_efficient ( Node *head , int x )
{
    Node *temp = new Node(x) ;
    if ( head == NULL )
    {
        temp->next = temp ;
        return temp ;
    }
    else
    {
        temp->next = head->next ;
        head->next = temp ;
        //* insert temp between head and head->next

        int t = head->data ;
        head->data = temp->data ;
        temp->data = t ;
        //* swapped data of head and temp, now : last->temp->head->head->next

        return temp ;
    }
}

Node *del_head_naive ( Node *head )
{
    if ( head == NULL ) // No elements in the CLL
        return NULL ;
    if ( head->next == head )   // Only one element in the CLL
    {
        delete head ; // Free up the space
        return NULL ;
    }

    Node *cur = head ;
    while ( cur->next != head )
        cur = cur->next ;

    cur->next = head->next ;
    delete head ;
    return cur->next ;
}

Node *del_head_efficient ( Node *head )
{
    if ( head == NULL ) // No elements in the CLL
        return NULL ;
    if ( head->next == head )   // Only one element in the CLL
    {
        delete head ; // Free up the space
        return NULL ;
    }

    int t = head->data ;
    head->data = head->next->data ; // Store value of second node in first node
    Node *temp = head->next ;   // Store the pointer to this second node
    head->next = head->next->next ;

    delete temp ;
    return head ;
}

Node *del_k_th ( Node *head , int k )
{
    if ( head == NULL )
        return head ;
    if ( k==1 )
        return del_head_efficient(head) ;   // Removes head, and returns the new head

    Node *cur = head ;  // k = 1
    for ( int i = 0 ; i < k-2 ; i++ ) // k = k-1
        cur = cur->next ;
    //TODO: Remove cur->next
    Node *temp = cur->next ;
    cur->next = cur->next->next ;

    delete temp ;
    return head ;
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