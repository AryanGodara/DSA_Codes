// Given a binary tree and a key. The task is to insert the key into the binary tree at first
// position available in level order.
# include <bits/stdc++.h>
using namespace std ;

// A binary tree node
struct Node
{
    int key ;
    struct Node *left , *right ;
} ;

// Utility function to create a new Node
struct Node *newNode ( int key )
{
    struct Node* temp = new Node ;
    temp -> key = key ;
    temp -> left = temp -> right = NULL ;
    return temp ;
}

// Function to print InOrder traversal of a Binary Tree
void inorder ( struct Node* temp )
{
    if ( !temp )
        return ;        // temp == NULL
    
    inorder(temp->left) ;
    cout << temp->key << " " ;
    inorder(temp->right) ;
}

// Function to insert a new element in a Binary Tree
void insert ( struct Node *temp , int key )
{
    queue <struct Node*> q ;
    q.push(temp) ;

    // Do level order traversal until we find an empty place.
    while ( !q.empty() )
    {
        struct Node *temp = q.front() ;
        q.pop() ;

        if ( !temp->left )  // temp->left == NULL
        {
            temp->left = newNode(key) ;
            break ;
        }
        else
            q.push(temp->left) ;    // Normal level order traversal code
        
        if ( !temp->right )
        {
            temp->right = newNode(key) ;
            break ;
        }
        else
            q.push(temp->right) ;
    }
}


// Driver Code
int main ()
{
    // Create the following Binary Tree
    //          10
    //         /  \
    //        11   9
    //       /      \
    //      7        8

    struct Node* root = newNode(10) ;
    root -> left = newNode(11) ;
    root -> right = newNode(9) ;
    root -> left -> left = newNode(7) ;
    root -> right -> right = newNode(8) ;

    cout << "Inorder traversal before insertion :\n" ;
    inorder(root) ;

    int key = 12 ;
    insert (root,key) ;

    cout << "\nInorder traversal after insertion :\n" ;
    inorder(root) ;

    return 0 ;
}