# include <bits/stdc++.h>
using namespace std ;

struct Node {
    int data ;
    Node *prev , *next ;

    Node ( int x )
    {
        data = x ;
        prev = next = NULL ;
    }
};

void printList ( Node *head )
{
    if ( head == NULL )
        return ;
    
    Node *p = head ;

    do {
        cout << p->data ;
        p = p->next ;
    } while ( p != head ) ;
}

Node * insert_at_head ( Node *head , int x )
{
    Node *temp = new Node(x) ;
    temp->next = head ;
    temp->prev = head->prev ;
    head->prev->next = temp ;
    head->prev = temp ;

    return temp ;
}

//? Driver Function
int main ()
{
    Node *head=new Node(10);
	Node *temp1=new Node(20);
	Node *temp2=new Node(30);
	
    head->next=temp1;
	
    temp1->next=temp2;
	temp2->next=head;

	temp2->prev=temp1;
	temp1->prev=head;
	
    head->prev=temp2;
	
    head=insert_at_head(head,5);
	
    printList(head);
	return 0;
}