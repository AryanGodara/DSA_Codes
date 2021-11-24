// Diameter of a binary tree is the max no. of nodes between any two nodes
// Or the 'no of nodes' on the longest path between two leaf nodes

# include <bits/stdc++.h>
using namespace std ;

// Structure for Node of Binary Tree
struct Node
{
    int key ;
    Node *left , *right ;

    Node ( int key )
    {
        this -> key = key ;
        left = right = NULL ;
    }
};

// Naive Function
int height ( Node *root )
{
    if ( root == NULL )
        return 0 ;
    
    return 1 + max ( height(root->left) , height(root->right) ) ;
}
int diameter ( Node *root )
{
    // Either this node is part of the diamter, or we check its left and right subtrees
    // So, we take the maximum of the three values

    if ( root == NULL )
        return 0 ;
    
    int d1 = 1 + height(root->left) + height(root->right) ; // Diameter from this node

    int d2 = diameter(root->left) , d3 = diameter(root->right) ;

    return max ( d1 , max ( d2 , d3 ) ) ;
}

// Efficient_code   // Just store all the heights in an unordered_map (pre-computation)

// Driver Function
int main ()
{
    Node *root = new Node(10) ;
    root->left = new Node(20) , root->right = new Node(30) ;
    root->right->left = new Node(40) , root->right->right = new Node(60) ;
    root->right->left->left = new Node(40) , root->right->right->right = new Node(60) ;

    cout << diameter ( root ) << endl ;

    return 0 ;
}