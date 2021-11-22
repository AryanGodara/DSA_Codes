/*
Children Sum Property is a property in which the sum of values of the left child and right child
should be equal to the value of their node if both the children are present. Else if, only one child
is present then the value of the child should be equal to its node value.
*/
# include <bits/stdc++.h>
using namespace std ;


struct Node
{
    int data ;
    Node *left , *right ;

    Node ( int key )    // Constructor
    {
        this -> data = key ;
        left = right = NULL ;
    }
} ;

bool child_sum_property ( Node* root )
{
    if ( root == NULL )     // Base Condition
        return true ;       // check this with examples
    
    // Recursive steps
    if ( root->left != NULL && root->right != NULL )
    {
        if ( root->left->data + root->right->data == root->data )
            return ( child_sum_property(root->left) && child_sum_property(root->right) ) ;
        return false ;  // It was already proven to not satisfy this property
    }
    else if ( root->left != NULL ) // Means that root -> right == NULL
    {
        if ( ( root -> left -> data ) == ( root -> data ) )
            return ( child_sum_property(root->left) ) ;
        return false ;  // if the above comparision is not true ;
    }
    else if ( root->right != NULL ) // Means that root -> left == NULL
    {
        if ( root -> right -> data == root -> data )
            return ( child_sum_property(root->right) ) ;
        return false ;
    }
    
    return true ;   // This is a leaf node, so no point in checking here
}

// 2nd way to write this program
bool isCsum ( Node *root )
{
    if ( root == NULL )
        return true ;   // Base case, in case this happens
    if ( root -> left == NULL && root -> right == NULL )
        return true ;   // This was a leaf node
    
    int sum = 0 ;

    if ( root -> left != NULL )
        sum += root -> left -> data ;
    if ( root -> right != NULL )
        sum += root -> right -> data ;
    
    return ( ( root -> data == sum ) && isCsum(root->left) && isCsum(root->right) ) ;
}

int main ()
{
    Node *root = new Node(5) ;
    root -> left = new Node (2) ;
    root -> right = new Node (3) ;
    root -> right -> left = new Node (1) ;
    //root -> right -> right = new Node (2) ;

    cout << boolalpha << child_sum_property(root) << endl ;
    cout << boolalpha << isCsum(root) << endl ;

    return 0 ;
}