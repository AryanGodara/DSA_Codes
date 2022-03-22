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

//? Method 1: Changes references/pointers
// Change the next of each node to the same node 'temp'
// If we encounter a node whose next is already pointerd to 'temp', this means that we've
// reached this node a second time, therefore, a loop exists
//! This destroys the linked list , O(N)
bool isLoop ( Node *head )
{
    Node *temp = new Node(0) , *cur = head ;

    while ( cur != NULL )
    {
        if ( cur->next == NULL )
            return false ;  // No loop is present
        if ( cur->next == temp )
            return true ;   // Found a loop
        
        Node *cur_next = cur->next ; // Create a new node, to store the cur->next
        cur->next = temp ; // change the 'next' of each node in the LL to 'temp'
        cur = cur_next ; // Move on to the next node
    }

    return false ;  // No loop is present
}

//? Method 2: Hashing
bool hasLoop ( Node *head )
{
    unordered_set <Node *> s ;

    for ( Node *cur = head ; cur != NULL ; cur = cur->next )
        if ( s.find(cur) != s.end() )
            return true ;
        else
            s.insert(cur) ;
        
    return false ;
}

//* Floyd Cycle Detection (Hare and Turtle)
bool loop_check ( Node *head )
{
    Node *slow = head , *fast = head ;

    do
    {
        if ( !fast || !fast->next ) // We reach a 'null'
            return false ;  // No loop exists
        slow = slow->next ;
        fast = fast->next->next ;
    } while ( slow != fast ) ;

    return true ;   // We reach here, only if slow == fast (Meaning, there's a loop)
}

bool isLoop_GFG ( Node* head )
{ 
    Node *slow_p = head, *fast_p = head ;
  
    while (fast_p!=NULL && fast_p->next!=NULL) 
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        
        if (slow_p == fast_p)
            return true; 
    } 

    return false; 
}

//? Driver Function
int main ()
{
    Node *head=new Node(15);
	head->next=new Node(10);
	head->next->next=new Node(12);
	head->next->next->next=new Node(20);
	head->next->next->next->next=head->next;

	if (isLoop(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
	return 0;

}