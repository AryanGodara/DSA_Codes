// Given a Binary Tree, we need to print all vertical lines starting from leftmost to rightmost

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

    * OP : 5 10 20 15 30
*/

void preorder ( Node *root , map <int,vector<Node*>> &mp , int hor ) // hor = horizontal distance
{
    if ( root == NULL )
        return ;
    
    mp[hor].push_back(root) ;

    preorder(root->left,mp,hor-1);
    preorder(root->right,mp,hor+1);
}

void vertical_traversal ( Node *root )
{
    if ( root == NULL )
        return ;

    map <int,vector<Node*>> mp ;

    preorder(root,mp,0) ;

    for ( auto &x : mp )
    {
        for ( auto &y : x.second )
            cout << y->key << " " ;
        cout << endl ;
    }
}

void v_traversal_iterative ( Node *root )
{
    if ( root == NULL )
        return ;
    
    map < int , vector<int> > mp ;

    queue < pair<Node*,int> > q ;
    q.push({root,0}) ;

    while ( q.empty() == false )
    {
        auto p = q.front();
        Node *cur = p.first ;

        int hd = p.second ;

        mp[hd].push_back(cur->key);
        
        q.pop() ;

        if (cur->left != NULL )
            q.push({cur->left,hd-1}) ;
        if ( cur->right != NULL )
            q.push({cur->right,hd+1}) ;
    }

    for ( auto &x: mp )
    {
        for ( int &y: x.second )
            cout << y << " " ;
        cout << endl ;
    }
}

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

    vertical_traversal(root);

    return 0 ;
}