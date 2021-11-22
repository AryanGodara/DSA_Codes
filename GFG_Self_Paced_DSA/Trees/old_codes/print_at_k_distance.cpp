
// Given a tree, print all the elements at distance k from the root
# include <bits/stdc++.h>
using namespace std ;

struct Node
{
    int data ;
    struct Node *left , *right ;

    Node ( int key )
    {
        data = key ;
        left = NULL ;
        right = NULL ;
    }
} ;

void printKDist ( struct Node *root , int k )    // recursive function
{
    if ( root == NULL ) // Base case
        return ;
    
    if ( k == 0 )     // We have reached that level
        cout << root -> data << " " ;
    
    else
    {
        printKDist(root->left , k-1) ;
        printKDist(root->right , k-1) ;
    }
}


// Driver Code
int main ()
{
    struct Node *root = new Node(10) ;    // we may even omit the word 'struct' at the beginning
	root->left = new Node(20) ;
	root->right = new Node(30) ;
	root->left->left = new Node(40) ;
	root->left->right = new Node(50) ;
	root->right->right = new Node(70) ;
	root->right->right->right = new Node(80) ;
	int k = 2 ;
	
	printKDist(root,k);

    return 0 ;
}