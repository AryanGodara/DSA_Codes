// Inorder Conversion of Binary Tree to Doubly Linked List ( in place )
/*
    We can't allocate any new memory and so, we have to repurpose the left and right
    pointers as prev and next pointers, respectively.

    Hint: We need to do inorder traversal of the Tree and while doing inorder traversal, we
    can simply maintain a previous pointer or reference of the previously traversed node.
    And change right child of the previous node to current node and elft child of current
    node to previous node.
*/
# include <bits/stdc++.h>
using namespace std ;

// Tree Data Structure
struct Node
{
    int key ;
    Node *left , *right ;

    Node ( int key )
    {
        this->key = key ;
        left = right = NULL ;
    }
};

// Print the linked list
void printList ( Node *head )
{
    Node *cur = head ;

    while ( cur != NULL )
    {
        cout << cur->key << " " ;
        cur = cur -> right ;
    }
    cout << endl ;
}

// The Primary Utility Function
Node * bt_to_dll ( Node *root )
{
    if ( root == NULL )
        return root ;

    static Node *prev = NULL ;

    Node *head = bt_to_dll(head->left) ;

    if ( prev == NULL )
        head = root ;
    else
        root->left = prev , root->right = root ;

    prev = root ;
    
    bt_to_dll(root->right) ;

    return head ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Node *root = new Node(10) ;
    root->left = new Node(5) , root->right = new Node(20) ;
    root->right->left = new Node(30) , root->right->right = new Node (35) ;

    Node *head = bt_to_dll (root) ;

    printList ( head ) ;

    return 0 ;
}