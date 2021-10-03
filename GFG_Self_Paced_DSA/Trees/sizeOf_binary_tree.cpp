# include <bits/stdc++.h>
using namespace std ;

struct Node
{
    int data ;
    Node *left , *right ;

    Node ( int key )
    {
        data = key ;
        left = right = NULL ;
    }
} ;

int getSize ( Node *root )          // THE MAIN FUNCTION
{
    if ( root == NULL )
        return 0 ;
    else
        return 1 + getSize(root->left) + getSize(root->right) ;
}


// Driver Code

int main ()
{
    Node *root = new Node(10) ;
	root->left = new Node(20) ;
	root->right = new Node(30) ;
	root->left->left = new Node(40) ;
	root->left->right = new Node(50) ;
	root->right->left = new Node(60) ;
	root->right->right = new Node(70) ;

    cout << getSize(root) << endl ;

    return 0 ;
}