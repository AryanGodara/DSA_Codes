# include <bits/stdc++.h>
using namespace std ;

// Node structure for binary tree
struct Node
{
    int key ;
    struct Node *left , *right ;

    Node ( int k ) 
    {
        key = k ;
        left = right = NULL ;
    }
};

// The three Functions below are different methods of printing graph using DFS

void preorder ( Node *root )    // root left right
{
    if ( !root)
        return ;
    cout << root->key << " " ;
    preorder(root->left) ;
    preorder(root->right) ;
}

void inorder ( Node *root )     // left root right
{
    if ( !root )
        return ;
    inorder(root->left) ;

    cout << root->key << " " ;

    inorder(root->right) ;
}

void postorder ( Node *root )   // left right root
{
    if ( !root )
        return ;
    postorder(root->left) ;
    postorder(root->right) ;

    cout << root->key << " " ;
}

int height ( Node *root )
{
    if ( !root )
        return 0 ;

    return ( 1 + max ( height(root->left) , height(root->right) ) ) ;
}

void nodes_at_k_th_distance ( Node *root , int k )  // k = distance from root node
{
    if ( !root )
        return ;

    else if (!k)
    {
        cout << root->key << " " ;
        return ;    // No need to check any further
    }
    nodes_at_k_th_distance(root->left,k-1) ;
    nodes_at_k_th_distance(root->right,k-1) ;
}

int size_of_graph ( Node *root )    // No. of elements in graph
{
    if ( !root )
        return 1 ;
    return 1 + size_of_graph(root->left) + size_of_graph(root->right) ;
}

int max_in_tree ( Node *root )      // Maximum Element in the Graph
{
    if ( !root )
        return INT_MIN ;

    return max ( root->key , max ( max_in_tree(root->left) , max_in_tree(root->right) ) ) ;
}

// Max Width of a graph ( Max no of elements at a level (all having same depth) )
int max_width ( Node *root )
{
    if ( !root )
        return 0 ;
    
    queue <Node *> q ;
    q.push(root) ;

    int ans = 0 ;

    while ( !q.empty() )
    {
        int cur = q.size() ;    // Currently, stores all elements of a single row
        ans = max ( ans , cur ) ;

        Node *cur_node = q.front() ;
        q.pop() ;

        if ( cur_node->left )   // Left subtree exists
            q.push(cur_node->left) ;
        if ( cur_node->right )   // Right subtree exists
            q.push(cur_node->right) ;
    }

    return ans ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Node *root = new Node(10) ;
    root->left = new Node(20) , root->right = new Node(30) , root->left->left = new Node(40) ;
    
    root->left->right = new Node(50) , root->right->right = new Node(60) ;
    root->left->right->left = new Node(70) , root->left->right->right = new Node(80) ;

    cout<<root->key<<" "<<root->left->key<<" "<< root->right->key<<" "<<root->left->left->key ;
    cout << endl << endl ;

    preorder(root) ;
    cout << endl << endl ;
    
    inorder(root) ;
    cout << endl << endl ;
    
    postorder(root) ;
    cout << endl << endl ;

    cout << height(root) << endl << endl ;
    
    nodes_at_k_th_distance (root,2) ;   // root node is at distance k = 0
    cout << endl << endl ;

    return 0 ;
}