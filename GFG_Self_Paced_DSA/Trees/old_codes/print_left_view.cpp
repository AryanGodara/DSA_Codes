# include <bits/stdc++.h>
using namespace std ;


struct Node
{
    int key ;
    struct Node *left , *right ;
    Node(int key)
    {
        this -> key = key ;
        left = right = NULL ;
    }
} ;

int maxlevel = 0 ;  // To prevent us from printing the multiple elements from the same level
void printleft ( Node* root , int level )
{
    if ( root == NULL )
        return ;

    if ( maxlevel < level ) // First element on this level
    {
        cout << root -> key << " " ;
        maxlevel = level ;
    }

    printleft(root->left,level+1) ;
    printleft(root->right,level+1) ;
}

// This is exactly like the levelordertraversal,except that we only print the first element (i==0)
void iterativeprintleft ( Node *root )
{
    if ( root == NULL )
        return ;
    
    queue <Node *> q ;
    q.push(root) ;  // The first element

    while ( q.empty() == false )
    {
        int count = q.size() ;      // Size of the queue

        // This loop, pops out all the element in the particular row, but only prints the leftmost
        for ( int i = 0 ; i < count ; i++ ) 
        {
            Node *cur = q.front() ;
            q.pop() ;   // Remove this item from the queue now

            if ( i == 0 )   // Only for the first element in each row ( leftmost )
                cout << ( cur -> key ) << " " ;
            
            if ( cur -> left != NULL )
                q.push(cur -> left ) ;
            if ( cur -> right != NULL )
                q.push(cur -> right) ;
        }
    }
}


// Driver Code
int main ()
{
    struct Node *root = new Node(10) ;
    root -> left = new Node(20) ;
    root -> right = new Node(30) ;
    root -> right -> left = new Node(40) ;
    root -> right -> right = new Node(50) ;

    printleft(root,1) ;

    return 0 ;
}