# include <bits/stdc++.h>
using namespace std ;

/*
*/

// Node for BST
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

// Search in BST
// 1. Recursive
bool search ( Node *root , int x )
{
    if ( root == NULL )
        return false ;
    if ( root->key == x )
        return true ;
    
    if ( root->key > x )
        return search(root->left,x) ;
    if ( root->key < x )
        return search(root->right,x) ;
    
    return false ;
}
// 2. Iterative
bool search_iterative (Node *root , int x )
{
    if ( root == NULL )
        return false ;
    if ( root->key == x )
        return false ;
    
    while ( root != NULL )
    {
        if ( root->key == x )
            return true ;
        
        else if ( root->key > x )
            root = root->left ;
        else
            root = root->right ;
    }

    return false ;
}

// Insert in BST
// 1. Recursive
void insert ( Node *root , int x )
{
    // Base Cases
    if ( root == NULL )
        return ;
    else if ( root->key == x )
        return ;

    // Recursion
    if ( root->left == NULL && root->key > x )
        root->left = new Node(x) ;
    else if ( root->right == NULL && root->key < x )
        root->right = new Node(x) ;
    else if ( root->key > x )
        insert(root->left,x) ;
    else
        insert(root->right,x) ;
}
// 2. Recursive GFG
Node *insert_gfg ( Node *root , int x ) // Returns the root node back
{
    if ( root == NULL )
        return new Node(x) ;

    else if ( root->key > x )
        root->left = insert_gfg(root->right,x) ;
    else if ( root->key < x )
        root->right = insert_gfg(root->left,x) ;
    
    return root ;
}
// 3. Iterative
Node *insert_iterative ( Node *root , int x )
{
    Node *temp = new Node(x) ;

    Node *parent = NULL , *cur = root ;

    while ( cur != NULL )
    {
        parent = cur ;
        
        if ( cur->key > x )
            cur = cur->left ;
        else if ( cur->key < x )
            cur = cur -> right ;
        else
            return root ;
    }

    if ( parent == NULL )
        return temp ;
    if ( parent->key > x )
        parent->left = temp ;
    else
        parent->right = temp ;
    
    return root ;
}

// Delete in BST
Node *get_successor ( Node *cur )   // Find the closest greater value of the root(cur)
{   // To find the closest smaller value, do cur->left, then do while for cur->right
    cur = cur->right ;
    
    while ( cur != NULL && cur->left != NULL )
        cur = cur->left ;
    
    return cur ;
}

Node *del_node ( Node *root , int x )
{
    if ( root == NULL )     // Empty BST
        return root ;
    
    if ( root->key > x )    // We recursively solve for the left subtree (sub-problem)
        root->left = del_node(root->left,x) ;
    else if ( root->key < x )   // We recursively solve for the right subtree (sub-problem)
        root->left = del_node(root->right,x) ;
    else        // Else, root->key == x
    {
        if ( root->left == NULL )   // Then root is replaced by root->right
        {
            Node *temp = root->right ;
            delete root ;
            return temp ;
        }
        else if ( root->right == NULL ) // Then root is replaced by root->left
        {
            Node *temp = root->left ;
            delete root ;
            return temp ;
        }
        else    // Both are not NULL, so we need to find the node that replaces this node
        {
            Node *succ = get_successor(root) ;
            root->key = succ->key ;
            root->right = del_node(root->right,succ->key) ;
            // Now, suc, is a root node. So it'll get deleted by the above 2 if-else statements.
        }
    }

    return root ;   // Return the current root, back to the progam that called this function
}

// Floor function in BST
Node *floor ( Node *root , int x )
{
    Node *res = NULL ;

    while ( root != NULL )
    {
        if ( root->key == x )
            return root ;
        else if ( root->key > x )
            root = root->left ;
        else
        {
            res = root ;
            root = root->right ;
        }
    }
    // Returns the value the closest smaller or equal value to the root, present in the BST.
    return res ;
}

// Ceiling function in BST
Node *ceil ( Node *root , int x )
{
    Node *res = NULL ;

    while ( root != NULL )
    {
        if ( root->key == x )
            return root ;
        else if ( root->key < x )
            root = root->right ;
        else
        {
            res = root ;
            root = root->left ;
        }
    }

    return res ;
}

