// In a balanced binary tree, for every node, the difference between heights of left subtree
// and right subtree should not be more than one.

# include <bits/stdc++.h>
using namespace std ;

// Structure for Binary Tree node
struct Node
{
    int key ;
    Node *left , *right ;

    Node ( int key )
    {
        this->key = key ;
        this->left = this->right = NULL ;
    }
};

// Naive Version O(n^2)
int height ( Node *root )
{
    if ( root == NULL )
        return 0 ;
    
    return ( 1 + max ( height(root->left) , height(root->right) ) ) ;
}

bool is_balanced_simple ( Node *root )
{
    if ( root == NULL )
        return true ;

    return ( abs( height(root->left) - height(root->right) ) <= 1 ) ;
}

// Efficient Version O(n)
int is_balanced ( Node *root )
{
    if ( root == NULL )
        return 0 ;

    int lh = is_balanced(root->left) ;
    if ( lh == -1 )
        return -1 ;
    
    int rh = is_balanced(root->right) ;
    if ( rh == -1 )
        return -1 ;

    if ( abs(lh-rh) > -1 )
        return -1 ;
    else
        return max(lh,rh) + 1 ;
}
// Every Function call does two things : It tells whether the subtree is balanced or not,
// and it also includes height
// The function returns -1, if the tree is unbalanced, else they return the height

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Node *root = new Node(10) ;
    root->left = new Node(5) , root->right = new Node(30) ;
    root->right->left = new Node(15) , root->right->right = new Node(20) ;

    cout << boolalpha << is_balanced_simple (root) << endl ;

    cout << ( (is_balanced (root)) ? "Balanced\n" : "Not Balanced\n" ) ;

    cout << is_balanced(root) << endl ;

    return 0 ;
}