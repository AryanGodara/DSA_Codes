# include <bits/stdc++.h>
using namespace std ;

// Structure for Node of Binary Tree
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

// Function 1
void printSpiral_1 ( Node *root )
{
    if ( root == NULL )
        return ;
    
    queue <Node *> q ;
    stack <Node *> s ;

    bool reverse = false ;  // Toggles on each level

    q.push(root) ;

    while ( !q.empty() )
    {
        int count = q.size() ;  // No of elements in this row

        for ( int i = 0 ; i < count ; i++ )
        {
            Node *cur = q.front() ;
            q.pop() ;

            // If we have to print this row in reverse, then we'll push all of these in a
            // stack, and then print them in LIFO, so it'll get reversed
            if ( reverse )
                s.push(cur) ;
            else    // Else, we'll just print them in the normal order
                cout << cur->key << " " ;
            
            if ( cur->left != NULL )
                q.push(cur->left) ;
            if ( cur->right != NULL )
                q.push(cur->right) ;

            if ( reverse )  // For printing in reverse order, if application here
            {
                while ( !s.empty() )
                {
                    cout << s.top() -> key << " " ;
                    s.pop() ;
                }
            }
        }
        cout << endl ;
        reverse = !reverse ;
    }

}

// Function 2
void printSpiral_2 ( Node *root )
{
    if ( root == NULL )
        return ;

    stack <Node *> s1 , s2 ;

    s2.push(root) ;

    while ( !s1.empty() || !s2.empty() )
    {
        while ( !s1.empty() )
        {
            Node *temp = s1.top() ;
            s1.pop() ;

            cout << temp->key << " " ;

            if ( temp->right != NULL )
                s2.push(temp->right) ;
            if ( temp->left != NULL )
                s2.push(temp->left) ;
        }

        while ( !s2.empty() )
        {
            Node *temp = s2.top() ;
            s2.pop() ;

            cout << temp->key << " " ;

            if ( temp->left )
                s1.push(temp->left) ;
            if ( temp->right )
                s1.push(temp->right) ;
        }

    }
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Node *root = new Node(1) ;
    root->left = new Node(2) , root->right = new Node(3) ;
    root->left->left = new Node(4) , root->left->right = new Node(5) ;
    root->right->left = new Node(6) , root->right->right = new Node(7) ;
    
    printSpiral_1 ( root ) ;
    cout << endl ;
    printSpiral_2 ( root ) ;

    return 0 ;
}