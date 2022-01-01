# include <bits/stdc++.h>
using namespace std ;

// Structure for the BST Node
struct Node
{
    int key ;
    struct Node *left, *right ;

    Node ( int k )
    {
        key = k ;
        left = right = NULL ;
    }
};

// Approach1 : Naive Solution

int max_value ( Node *root )    // Returns the max element in this subtree
{
    if ( root == NULL )
        return INT_MIN ;

    int res = root->key , lres = max_value(root->left) , rres = max_value(root->right) ;

    if ( lres > res )
        res = lres ;
    if ( rres > res )
        res = rres ;
    
    return res ;
}

int min_value ( Node *root )
{
    if ( root == NULL )
        return INT_MAX ;
    
    int res = root->key , lres = min_value(root->left) , rres = min_value(root->right) ;

    res = min ( res , min ( lres , rres ) ) ;

    return res ;
}

bool is_BST ( Node *root )
{
    if ( root == NULL )
        return true ;
    
    if ( root->left != NULL && max_value(root->left) > root->key )
        return false ;
    
    if ( root->right != NULL && min_value(root->right) < root->key )
        return false ;
    
    return true ;
}


// Approach 2

bool is_BST_2 ( Node *root , int min , int max )   // cur element must be b/w min and max
{
    if ( root == NULL )
        return true ;
    
    return ( root->key > min && root->key < max && is_BST_2(root->left,min,root->key) && is_BST_2(root->right,root->key,max) ) ;
}

// Approach 3
// In the Inorder traversal of the tree, the order of elements should be ascending
// So, each element should be greater than its 'previous' 'inorder' traversal character.

int prevv = INT_MIN ;

bool is_BST_3 ( Node *root )
{
    if ( root == NULL )
        return true ;
    
    if ( is_BST_3(root->left) == false )
        return false ;
    
    if ( root->key <= prevv )
        return false ;
    
    // ELSE
    prevv = root->key ;

    return is_BST_3(root->right) ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    
    Node *root = new Node(4) ;
    root->left = new Node(2) , root->right = new Node(5) ;
    root->left->left = new Node(1) , root->left->right = new Node(3) ;

    cout << boolalpha << is_BST(root) << endl ;
    cout << boolalpha << is_BST_2(root,INT_MIN,INT_MAX) << endl ;
    cout << boolalpha << is_BST_3(root) << endl ;

    return 0 ;
}