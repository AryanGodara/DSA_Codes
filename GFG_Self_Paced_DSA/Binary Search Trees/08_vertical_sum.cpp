// Given a binary tree, we need ot find the sum of nodes in all vertical lines from the leftmost
// line to the rightmost list

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

    * OP : 5 10 35 30            ( (5) (20) (10+15) (30) )
*/

// Create a map, that stores sum for a given Horizontal distance
// Then, traverse the map and print the values
//* Hor(root) = 0 , Hor(left_child) = Hor(par)-1 , Hor(right_child) = Hor(par)+1

void preorder ( Node *root , map<int,int> &mp , int hor ) // hor = horizontal distance
{
    if ( root == NULL )
        return ;
    
    mp[hor] += root->key ;

    preorder(root->left,mp,hor-1);
    preorder(root->right,mp,hor+1);
}

void vertical_sum ( Node *root )
{
    if ( root == NULL )
        return ;
    
    map<int,int> mp ;

    preorder(root,mp,0);

    for ( auto &x: mp )
        cout << x.second << " " ;
    cout << endl ;
}

int main ()
{
    ios_base :: sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Node *root = new Node(20) ;
    root->left = new Node(10) , root->right = new Node(30);
    root->left->left = new Node(5) , root->left->right = new Node(15) ;

    vertical_sum(root) ;

    return 0 ;
}