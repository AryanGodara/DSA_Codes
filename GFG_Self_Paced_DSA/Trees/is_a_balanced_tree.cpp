/*
In a Balanced Binary Tree for every node, the difference between the heights of left subtree and 
right subtree shouldn't be more than one.
*/
# include <bits/stdc++.h>
using namespace std ;

struct Node
{
    int key ;
    struct Node *left , *right;

    Node ( int k ) 
    {
        key = k ;
        left = right = NULL ;
    }
} ;


// The first method, this has a time complexity of O(n^2)

int height ( Node *root )       // O(N)
{
    if ( root == NULL )
        return 0 ;
    return 1 + max( height(root -> left) , height(root->right) ) ;
}

bool isBalanced ( Node *root )  // O(N) * O(N)[from the height function] == O(N^2)
{
    if ( root == NULL )
        return true ;
    
    int lh = height ( root -> left ) ;
    int rh = height ( root -> right ) ;

    return ( abs((lh-rh)) <= 1 && isBalanced(root->left) && isBalanced(root->right) ) ;
}


// The second method, this has a time complexity of O(N)

int BalancedTree ( Node *root )
{
    if ( root == NULL ) // The height below it is zero
        return 0 ;

    int lh = BalancedTree(root->left) ;
    if ( lh == -1 )     // root -> left is not balanced
        return -1 ;     // This tree is not balanced

    int rh = BalancedTree(root->right) ;
    if ( rh == -1 )     // root -> right is not balanced
        return -1 ;     // This tree is not balanced
    
    if ( abs (lh-rh) > 1 )
        return -1 ; // This node, and hence this tree, is not balanced
    
    else    // Part of recursion
        return max(lh,rh) + 1 ;
    // height from a node = max of heights of its left and right children + 1, to account for itself
}

int main ()
{
    Node *root = new Node(10) ;
    root -> left = new Node(5) ;
    root -> right = new Node(30) ;
    root -> right -> left = new Node(15) ;
    root -> right -> right = new Node(20) ;

    cout << boolalpha << isBalanced(root) << endl ;
    cout << ( ( BalancedTree(root) != -1 ) ? "true" : "false" ) << endl ;
}