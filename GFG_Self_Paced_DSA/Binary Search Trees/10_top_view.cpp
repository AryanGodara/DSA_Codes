// Given a BST, we need to print the top view of the tree

# include <bits/stdc++.h>
using namespace std ;

// BST Node Struct
struct Node {
    int key ;
    Node *left , *right ;

    Node ( int x )
    {
        key = x ;
        left = right = NULL ;
    }
};

/*
 * Example

            20
           /  \
          /    \
        10      30
       /  \
      /    \
     5      15

    * OP : 5 10 20 30
*/

void preorder ( Node *root , map <int,Node*> &mp , int hor ) // hor = horizontal distance
{
    if ( root == NULL )
        return ;
    
    if ( mp[hor] == NULL )
        mp[hor] = (root) ;

    preorder(root->left,mp,hor-1);
    preorder(root->right,mp,hor+1);
}

void top_view ( Node *root )
{
    if ( root == NULL )
        return ;
    
    map <int,Node*> mp ;

    preorder(root,mp,0) ;

    for ( auto &x : mp )    // For each hor value, print only the first item
        cout << x.second->key << " " ;
}

void top_view_iterative ( Node *root )
{
    if ( root == NULL )
        return ;
    
    map < int,int> mp ;

    queue < pair<Node*,int> > q ;
    q.push({root,0}) ;

    while ( q.empty() == false )
    {
        auto p = q.front();
        Node *cur = p.first ;

        int hd = p.second ;

        if ( mp.find(hd) == mp.end() )
            mp[hd] = cur->key ;
        
        q.pop() ;

        if (cur->left != NULL )
            q.push({cur->left,hd-1}) ;
        if ( cur->right != NULL )
            q.push({cur->right,hd+1}) ;
    }

    for ( auto &x: mp )
        cout << x.second << " " ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Node *root = new Node(20) ;
    root->left = new Node(10) , root->right = new Node(30);
    root->left->left = new Node(5) , root->left->right = new Node(15) ;
    root->left->right->left = new Node(14) , root->left->right->left->left = new Node(13) ;
    root->left->right->left->left->left = new Node(12) ;

    top_view(root);

    return 0 ;
}