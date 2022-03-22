# include <bits/stdc++.h>
using namespace std ;

struct Node {
    int data ;
    Node* next ;

    Node ( int x )
    {
        data = x ;
        next = NULL ;
    }
};

void printlist ( Node *head )
{
    Node *curr = head ;
    
    while( curr != NULL )
    {
        cout << curr->data << " " ;
        curr = curr->next ;
    }
    
    cout << endl ;
}

Node *reverseK_recursive ( Node *head , int k )
{
    Node *cur = head , *next = NULL , *prev = NULL ;

    int count = 0 ;

    while ( cur != NULL && count < k )
    {
        next = cur->next ;  // Normal Reversing of linked list
        cur->next = prev ;  // Change the direction of next
        prev = cur ;    // Update the previous node
        cur = next ;    // Mode foward in the list

        count++ ;
    }
    
    if ( next != NULL ) // At this point, next is the 'current' node -> next
    {
        Node *rest_head = reverseK_recursive(next,k) ;  // reverse the ll, AFTER the cur k nodes
        head->next = rest_head ; // head rn, is the 'last node' of the reversed 'k nodes'
    }

    return prev ;
}

Node *reverseK_iterative ( Node *head , int k )
{
    Node *cur = head , *prevFirst = NULL ;
    bool isFirstPass = true ;

    while ( cur != NULL )
    {
        Node *first = cur , *prev = NULL ;
        int count  = 0 ;
        while(cur != NULL && count < k)
        {
        Node *next = cur->next ;
        cur->next = prev ;
        prev = cur ;
        cur = next ;
        count++ ;
        }

        if ( isFirstPass )
        {
            head = prev ;
            isFirstPass = false ; 
        }
        else
        {
            prevFirst->next = prev ;
        }
        
        prevFirst = first ;
    }

    return head ;
}


//? Driver Function
int main() 
{ 
	Node *head = new Node(10) ;
    
	head->next = new Node(20) ;
	head->next->next = new Node(30) ;
	head->next->next->next = new Node(40) ;
	head->next->next->next->next = new Node(50) ;
	head->next->next->next->next->next = new Node(60) ;
	head->next->next->next->next->next->next = new Node(70) ;

	printlist ( head ) ;

	head = reverseK_iterative ( head , 3 ) ;
	printlist ( head ) ;
	return 0;
} 