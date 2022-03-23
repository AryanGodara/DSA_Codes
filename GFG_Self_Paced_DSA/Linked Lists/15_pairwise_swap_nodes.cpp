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

//! Simply Swapping the data, although O(N), can be very costly if data is very complex.
void pairwiseSwap(Node *head){
    Node *curr=head;
    while(curr!=NULL&&curr->next!=NULL){
        swap(curr->data,curr->next->data);
        curr=curr->next->next;
    }
}

//* Efficient Approach
Node *pairwiseSwap_efficient(Node *head){
    if(head==NULL||head->next==NULL)
        return head;
    Node *curr=head->next->next;
    Node *prev=head;
    head=head->next;
    head->next=prev;
    while(curr!=NULL&&curr->next!=NULL){
        prev->next=curr->next;
        prev=curr;
        Node *next=curr->next->next;
        curr->next->next=curr;
        curr=next;
    }
    prev->next=curr;
    return head;
}