# include <bits/stdc++.h>
using namespace std ;

struct Node
{
    int key ;
    Node *left , *right ;
    int l_count ;   // No. of elements in the left subtree of the element

    Node ( int key )
    {
        this->key = key ;
        this->l_count = 0 ;
        this->left = this->right = NULL ;
    }
};

Node* insert ( Node *root , int x )
{
    if ( root == NULL )     // A new tree is created
        return new Node(x) ;
    
    if ( x < root->key )    // Goes to its left subtree
    {
        root->l_count++ ;
        root->left = insert(root->left,x) ;
    }
    
    else if ( x > root->key )
    {
        root->right = insert(root->right,x) ;
    }

    return root ;
}

Node* k_th_smallest ( Node *root , int k )
{
    if ( root == NULL )
        return NULL ;
    
    int count = root->l_count + 1 ; // This is the 'ascending' rank of the current 'root' element

    if ( count == k )
        return root ;
    
    if ( count > k )    // We have to look in the left subtree
        return k_th_smallest(root->left,k) ;
    
    return k_th_smallest(root->right,k-count) ; // Look in the right subtree
}


// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int k = 4 ;
    Node *root = NULL ;
    vector <int> key = { 20 , 8 , 22 , 4 , 12 , 10 , 14 } ;

    for ( int x : key )
        root = insert (root,x) ;
    
    Node *res = k_th_smallest(root,k) ;
    if ( res == NULL )
        cout << "There are less than k nodes in the BST" ;
    else
        cout << "K'th element is " << res->key << endl ;

    return 0 ;
}