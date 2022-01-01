# include <bits/stdc++.h>
using namespace std ;

// Structure for BST node
struct Node
{
    int key ;
    Node *left, *right ;

    Node ( int key )
    {
        this->key = key ;
        left = right = NULL ;
    }
};

/*
    Derive an fast algorithm to find the k'th smallest element in a binary search tree (BST).
*/

// Naive Solution
// You keep a 'reference' 'count' variable, which keeps track of how many nodes you visited.
// Do an inorder traversal of the BST (is ascending in nature), and stop when count == k.
// If we were using a set, that would simply be printing the k'th element of the set.

void print_kth ( Node *root , int k , int &count )
{
    if ( root != NULL )
    {
        print_kth(root->left,k,count) ; // Keep going till you reach the smallest node?
        count++ ;

        if ( count == k )
        {
            cout << root->key << endl ;
            return ;
        }
        print_kth(root->right,k,count) ;
    }
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Node *root = new Node(15) ;
    root->left = new Node(5) , root->right = new Node(20) ;
    root->left->left = new Node(3) , root->right->left = new Node(18) ;
    root->right->left->left = new Node(16) , root->right->right = new Node(80) ;

    int k = 3 , count = 0 ;
    print_kth(root,k,count) ;

    return 0 ;
}