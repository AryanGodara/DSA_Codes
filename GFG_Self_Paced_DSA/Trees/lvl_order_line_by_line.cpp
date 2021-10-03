# include <bits/stdc++.h>
using namespace std ;

struct Node
{
    int key ;
    Node *left , *right ;
    Node ( int key )
    {
        this -> key = key ;
        left = right = NULL ;
    }
} ;

void printLevel ( Node *root )
{
    if ( root == NULL )
        return ;
    
    queue <Node *> q ;
    q.push(root) ;
    q.push(NULL) ;

    while ( q.size() > 1 )
    {
        Node *curr = q.front() ;
        q.pop() ;               // Now remove this element

        if ( curr == NULL )     // if this element was NULL ( last element of that line )
        {
            cout << endl ;
            q.push(NULL) ;  // Now NULL is present, after all the members of the next line
            continue ;
        }
        cout << curr -> key << " " ;    // Print the element, if it's not NULL

        if ( curr -> left != NULL )
            q.push(curr->left) ;
        if ( curr -> right != NULL)
            q.push(curr->right) ;
    }
}

// Now, instead of inserting NULL, we keep count of the no. of elements, and then print '\n'
void printval_second_method ( Node *root )
{
    if ( root == NULL )
        return ;
    
    queue <Node *> q ;
    q.push(root) ;

    while ( q.empty() == false )
    {
        int count = q.size() ;

        for ( int i = 0 ; i < count ; i++ )
        {
            Node *curr = q.front() ;
            q.pop() ;   // Remove curr from the queue

            cout << curr->key << " " ;  // Print the curr element

            if ( curr -> left != NULL )
                q.push(curr->left) ;
            if ( curr -> right != NULL )
                q.push(curr->right) ;
        }
        cout << endl ;
    }
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
	
	printLevel(root);

    cout << endl << endl ;
    printval_second_method(root) ;

    return 0 ;
}