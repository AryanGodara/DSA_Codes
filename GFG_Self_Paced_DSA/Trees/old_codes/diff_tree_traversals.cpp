# include <bits/stdc++.h>
using namespace std ;

// Different ways to traverse through a tree

// A binary tree node has data, pointer to left child, and pointer to right child
struct Node
{
    int data ;

    struct Node *left , *right ;

    Node ( int data )       // Constructing a new node, with data 'data'
    {
        this -> data = data ;
        left = right = NULL ;
    }
} ;

// Function to print the postorder traversal of a binary tree
void printPostOrder ( struct Node* node )   // address of head?
{
    if ( node == NULL )
        return ;

    // first recur on left subtree          // recursion to the rescue lol
    printPostOrder(node->left) ;

    // then recur the right subtree
    printPostOrder(node->right) ;

    // now deal with the node       // base step
    cout << node -> data << " " ;
}

// Function to print the inorder traversal of a binary tree
void printInOrder ( struct Node* node )
{
    if ( node == NULL )
        return ;
    
    // first recur on left child
    printInOrder(node->left) ;

    // then print the data on the node
    cout << node -> data << " " ;

    // now recur on the right child
    printInOrder(node->right) ;
}

// Function to print the preorder traversal of a binary tree
void printPreOrder ( struct Node* node )
{
    if ( node == NULL )
        return ;
    
    // first print the data of the node
    cout << node -> data << " " ;

    // then recur on left subtree
    printPreOrder(node->left) ;

    // now recur on right subtree
    printPreOrder(node->right) ;
}


// Driver Code

int main ()
{
    // Construct the tree
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5

    struct Node *root  = new Node(1) ;
    root -> left = new Node(2) ;
    root -> right = new Node(3) ;

    root -> left -> left = new Node(4) ;
    root -> left -> right = new Node(5) ;

    cout << "Preorder traversal of binary tree is \n" ;
    printPreOrder(root) ;
    cout << endl ;

    cout << "\nInorder traversal of binary tree is \n" ;
    printInOrder(root) ;
    cout << endl ;

    cout << "\nPostorder traversal of binary tree is \n" ;
    printPostOrder(root) ;
    cout << endl ;

    return 0 ;
}