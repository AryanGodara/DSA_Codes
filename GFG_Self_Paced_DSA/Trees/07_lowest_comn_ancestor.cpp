// Find the Lowest Common Ancestor (LCA) of two nodes in O(N) time complexity.

# include <bits/stdc++.h>
using namespace std ;

// Node Structure for Binary Tree
struct Node
{
    int key ;
    Node *left , *right ;

    Node ( int k )
    {
        key = k ;
        left = right = NULL ;
    }
};

bool find_path ( Node *root , vector <Node *> &p , int n )
{
    if ( root == NULL )
        return false ;
    
    p.push_back(root) ;

    if ( root->key == n )
        return true ;

    if ( find_path(root->left,p,n) || find_path(root->right,p,n) )    
        return true ;
    
    p.pop_back() ;

    return false ;
}

Node *lca_1 ( Node *root , int n1 , int n2 )
{
    vector <Node *> path1 , path2 ;

    if ( !find_path(root,path1,n1) || !find_path(root,path2,n2) )
        return NULL ;
    
    for ( int i = 0 ; i < min( path1.size() , path2.size() ) - 1 ; i++ )
    {
        if ( path1[i+1] != path2[i+1] )
            return path1[i] ;
    }

    return NULL ;
}

/*
    The idea for the efficient solution :-
        We do a normal recursive traversal. We have the following cases for every node :-
        1. If it's same as n1 or n2.
        2. If one of its substrees contains n1 and other contains n2.
        3. If one of its subtrees contains both n1 and n2.
        4. If none of its subtrees contain any of n1 or n2.
*/
Node *lca_2 ( Node *root , int n1 , int n2 )
{
    if ( root == NULL )
        return NULL ;

    // We're assuming that both the key exist in the key, so if we find one key first.
    // Then we assume that the other key also exists. Therefore, this key is the lca.
    if ( root->key == n1 || root->key == n2 )
        return root ;
    
    Node *lca1 = lca_2(root->left,n1,n2) ;
    Node *lca2 = lca_2(root->right,n1,n2) ;

    if ( lca1 != NULL && lca2 != NULL )
        return root ;   // left subtree contains one key, and right subtree contains another
    if ( lca1 != NULL )
        return lca1 ;   // left subtree contains at least one of n1 and n2
    else
        return lca2 ;   // right subtree contains atleast one of n1 and n2
}

// Driver Function
int main()
{
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    // Construct the Binary Tree
    Node *root = new Node(10) ;
    root->left = new Node(20) , root->right = new Node(30) ;
    root->right->left = new Node(40) , root->right->right = new Node(50) ;


    // Method 1 : Requires two traversals of the tree
    int n1 = 20 , n2 = 50 ;
    Node *ans1 = lca_1 ( root , n1 , n2 ) ;
    cout << "LCA_1 : " << ans1->key << endl << endl ;

    // Method 2 : Efficient Approach, requires only a single traversal, but both nodes
    // should be present.
    Node *ans2 = lca_2 ( root , n1 , n2 ) ;
    cout << "LCA_2 : " << ans2->key << endl << endl ;

    return 0 ;
}