// We are given a binary tree and and a laft node, we need to find time to burn the binary 
// tree if we burn the given leaf at 0th second

// After going through a few examples, we'll notice that each node gets burned, at
// the second equal to its distance from the orig leaf node.
// So, the final ans = max distance of a node, from the orig leaf node.

// Hint : The farthest node must be reachable through one of the ancestors of the original
// leaf node. These ancestors, also include the leaf node itself.

// So, the ans will be the max value for each ancestor : distance of the ancestor from the
// leaf node + the height of the other subtree of the ancestor(the one not containing leaf node)

# include <bits/stdc++.h>
using namespace std ;

// Structure of Node of Binary Tree
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

int res = 0 ;   // Global variable to store the result, can also be passed by reference.

int burnTime ( Node *root , int leaf , int &dist )
{
    if ( root == NULL )
        return 0 ;

    if ( root->key == leaf )    // We found the original leaf node
    {
        dist = 0 ;
        return 1 ;
    }

    int l_dist = -1 , r_dist = -1 ;

    int lh = burnTime(root->left,leaf,l_dist) , rh = burnTime(root->right,leaf,r_dist) ;

    if ( l_dist != -1 )
    {
        dist = l_dist + 1 ;
        res = max ( res , dist + rh ) ;
    }
    else if ( r_dist != -1 )
    {
        dist = r_dist + 1 ;
        res = max ( res , dist + lh ) ;
    }

    return max ( lh , rh ) + 1 ;
}

int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    // Constructing the Binary Tree
    Node *root = new Node(10) ;
    root->left = new Node(20) , root->right = new Node(30) ;
    root->left->left = new Node(40) , root->left->right = new Node(50) ;
    root->left->left->left = new Node(60) , root->left->left->left->left >= new Node(70) ;

    int dist = -1 , leaf = 50 ;

    cout << burnTime ( root , leaf , dist ) << endl ;

    return 0 ;
}