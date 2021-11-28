// Iterative Inorder Traversal of the given binary tree

# include <bits/stdc++.h>
using namespace std ;

// Structure for Tree Node
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

// The Three Iterative Traversal Functions
void inorder_iterative ( Node *root )
{
    if ( root == NULL )
        return ;
    
    stack <Node *> s ;

    Node *cur = root ;  // Used to store the 'current' node

    while (  cur || !s.empty() )
    {
        while ( cur != NULL )
        {
            s.push(cur) ;
            cur = cur->left ;
        }

        cur = s.top() ; // This is a leaf node at this point
        s.pop() ;
        cout << cur->key << " " ;
        cur = cur->right ;
    }
    cout << endl ;
}

void preorder_iterative ( Node *root )
{
    if ( root == NULL )
        return ;
    
    stack <Node *> s ;
    s.push(root) ;

    while ( !s.empty() )
    {
        Node *cur = s.top() ;
        cout << cur->key << " " ;
        s.pop() ;

        if ( cur->right != NULL )
            s.push(cur->right ) ;
        if ( cur->left != NULL )
            s.push(cur->left) ;
        // We push right before left is because, we're using a stack, and so, it is FIFO
    }
    cout << endl ;
}

void preorder_iterative_space_efficient ( Node *root )
{
    if ( root == NULL )
        return ;
    
    stack <Node *> s ;
    Node *cur = root ;

    while ( cur != NULL || !s.empty() )
    {
        while ( cur != NULL )
        {
            cout << cur->key << " " ;

            if ( cur->right != NULL )
                s.push(cur->right) ;

            cur = cur->left ;
        }
        if ( !s.empty() )
        {
            cur = s.top() ;
            s.pop() ;
        }
    }

    cout << endl ;
}

// Driver Function
int main ()
{
    Node *root = new Node(10) ;
    root->left = new Node(20) , root->right = new Node(30) ;   
    root->left->left = new Node(40) , root->left->right = new Node(50) ;
    root->right->left = new Node(60) ;

    inorder_iterative(root) ;
    preorder_iterative(root) ;
    preorder_iterative_space_efficient(root) ;

    return 0 ;
}