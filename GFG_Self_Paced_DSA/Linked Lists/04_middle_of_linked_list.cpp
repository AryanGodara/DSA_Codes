# include <bits/stdc++.h>
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;

    // Using Initializer Lists
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* middleNode(ListNode* head) 
{
    /*
    Using Fast and Slow Pointer Approach ( Two Pointers )
    When traversing the list with a pointer slow, make another fast pointer that traverses
    twice as fast. When fast reaches the end, slow must be in the middle.
    */
    ListNode *slow = head , *fast = head ;

    while ( fast != NULL && fast->next != NULL )
    {
        slow = slow->next ;
        fast = fast->next->next ;
    }

    return slow ;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode** t1 = &head, *t2 = head;
    for(int i = 1; i < n; ++i)
    {
        t2 = t2->next;
    }
    while(t2->next != NULL)
    {
        t1 = &((*t1)->next);
        t2 = t2->next;
    }
    *t1 = (*t1)->next;
    return head;       
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    ListNode *head = new ListNode(1) , *temp = head ;

    for ( int i = 2 ; i <= 6 ; i++ )
    {
        ListNode *t = new ListNode(i) ;
        temp -> next = t ;
        temp = t ;
    }

    cout << middleNode ( head ) << endl ;

    removeNthFromEnd(head,3) ;

    while ( head != NULL )
    {
        cout << head->val << " " ;
        head = head->next ;
    }
    cout << endl ;

    return 0 ;
}