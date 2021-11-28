// Given a complete Binary tree, calculate the number of nodes in the binary tree

# include <bits/stdc++.h>
using namespace std ;

// Naive Solution : Simple dfs traversal, takes O(N) time.

// Efficient Solution : Takes O( log(N)*log(N) ) time.
// We use the fact that the given tree is a complete binary tree. So, the no of nodes in a 
// complete binary tree of height h = 2^h - 1.
// We just check if the left and right subtree of a root node are complete, if they are,
// we have the answer. Else, if we travel further down and then if the subtrees are complete
// or not. And thus, we get the final solution

// Structure for Node of Binary Tree
struct Node
{
    int key ;
    Node *left , *right ;

    Node ( int k )
    {
        key = k ;
        left = right = NULL ;
    }
};

int count_nodes ( Node *root )
{
    int lh = 0 , rh = 0 ;

    Node *cur = root ;      // Calculating height of left subtree
    while ( cur != NULL )
    {
        lh++ ;
        cur = cur->left ;
    }

    cur = root ;           // Calculating height of right subtree
    while ( cur != NULL )
    {
        rh++ ;
        cur = cur->right ;
    }

    if ( lh == rh ) // The tree from this node is a complete binary tree
        return ( pow(2,lh) - 1 ) ; // Simple formula derived from sum of a Geometric Progression
    
    // Else, we have to individually check for the left and right subtree
    return 1 + count_nodes(root->left) + count_nodes(root->right) ;
}

// Driver Function
int main ()
{
    Node *root = new Node(10) ;
    root->left = new Node(20) , root->right = new Node(30) ;
    root->left->left = new Node(40) , root->left->right = new Node(50) ;
    root->right->left = new Node(60) , root->right->right = new Node(70) ;
    root->left->left->left = new Node(80) , root->left->left->right = new Node(90) ;
    root->left->right->left = new Node(100) , root->left->right->right = new Node(110) ;
    root->right->left->left = new Node(120) ;

    cout << count_nodes(root) << endl ;
}