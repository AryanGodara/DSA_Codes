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

void printList ( Node *head )
{
    Node *cur = head ;

    while ( cur != NULL )
    {
        cout << cur->data << " " ;
        cur = cur->next ;
    }

    cout << endl ;
}

Node *reverse_iterative ( Node *head )
{
    if ( head == NULL )
        return head ;
    
    Node *cur = head , *prev = NULL ;

    while ( cur != NULL )
    {
        Node *next = cur->next ;

        cur->next = prev ;
        prev = cur ;
        cur = next ;
    }

    return prev ;
}

Node *reverse_recursive_1 ( Node *head )
{
    if ( !head || !head->next ) // Single or 0 elements
        return head ;
    
    Node *rest_head = reverse_recursive_1(head->next) ; // Points to the last element ig
    Node *rest_tail = head->next ; // Points to the new last element (original head->next)
    rest_tail->next = head ; // Next of this tail, is now cur head (cur last element)
    head->next = NULL ; // Head is last, so its next = null

    return rest_head ; // This is the last element ig
}

Node *reverse_rev_2 ( Node *cur , Node *prev ) // Similar to the recursive method
{
    if ( cur == NULL )
        return prev ;
    
    Node *next = cur->next ;
    cur->next = prev ;

    return reverse_rev_2(next,cur) ;
}

int main ()
{
    Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	printList(head);
	// head=reverse(head); //? Try all three separately
	printList(head);
	return 0;
}