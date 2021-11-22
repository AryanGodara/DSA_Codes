# include <iostream>
# include <queue>

using namespace std ;

// A binary tree node
struct Node
{
    int data ;
    struct Node *left , *right ;
} ;

// Utility function to create a new node
Node* newNode (int data )
{
    Node *temp = new Node ;
    temp -> data = data ;
    temp -> left = temp -> right = NULL ;
    return temp ;
}

// Function to print level order traversal of the binary tree
void printLevelOrder ( Node *root )
{
    // Base Case
    if ( root == NULL )
        return ;

    // Create an empty queue for level order traversal
    queue <Node *> q ;

    // Enqueue Root and initialize height
    q.push(root) ;

    while ( q.empty() == false )
    {
        // Print front of queue and remove it from queue
        Node *node = q.front() ;
        cout << node -> data << " " ;
        q.pop() ;

    // Enqueue left child
    if ( node -> left != NULL )
        q.push(node->left) ;
    
    // Enqueue right child
    if ( node -> right != NULL )
        q.push(node->right) ;
    }
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

    struct Node *root  = newNode(1) ;
    root -> left = newNode(2) ;
    root -> right = newNode(3) ;

    root -> left -> left = newNode(4) ;
    root -> left -> right = newNode(5) ;

    cout << "Level Order traversal of binary tree is :-" << endl ;
    printLevelOrder(root) ;

    return 0 ;
}