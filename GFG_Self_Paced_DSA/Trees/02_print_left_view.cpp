// Print the Left View of Binary Tree

# include <bits/stdc++.h>
using namespace std ;

// Tree Node structure
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

// Main Utility Function
void left_view ( Node *root )
{
    queue <Node*> q ;               // For performing BFS on the tree

    vector <Node*> mp (1e5,NULL) ;  // Let, 1e5 = max possible height of a tree
    
    unordered_map <Node*,int> level ;   // Stores the level of each node
    
    q.push(root) ;

    mp[0] = root ;
    level[root] = 0 ;

    while ( !q.empty() )
    {
        Node *cur = q.front() ;
        q.pop() ;

        //cout << cur->key << " " ;

        int cur_level = level[cur] ;

        if ( cur->left )
        {
            q.push(cur->left) ;
            level[cur->left] = cur_level + 1 ;
            if ( !mp[cur_level+1] )   // If this doesn't already exist
                mp[cur_level+1] = cur->left ;
        }

        if ( cur->right )
        {
            q.push(cur->right) ;
            level[cur->right] = level[cur->right]+1 ;
            if ( !mp[cur_level+1] )   // If this doesn't already exist
                mp[cur_level+1] = cur->right ;
        }

        //cout << level[cur] << endl ;
        //cout << cur_level << " " << mp[cur_level]->key << endl ;
    }

    auto it = mp.begin() ;
    while ( *it != NULL )
    {
        cout << (*it)->key << " " ;
        it++ ;
    }
    cout << endl ;
}


// Easier, much simpler print_left, how did I not think of this
void printLeft_solve ( Node *root , int level , int &max_level )
{
    if ( root == NULL )
        return ;

    if ( max_level < level )    // We haven't reached this level before, so this is leftmost
    {
        cout << root->key << " " ;
        max_level = level ; // So, this is the new max_level
        // and we won't print any more nodes that are on this level
    }
    // Else, we don't have to print this node, and we move on to its
    // children nodes, and we call left subtree first, as we have to print the left view
    printLeft_solve(root->left,level+1,max_level) ;
    printLeft_solve(root->right,level+1,max_level) ;
}
void print_left ( Node *root )
{
    int max_level = 0 ;     // This has to act like a static variable, not an argument
    // Call the utility function
    printLeft_solve(root,1,max_level) ;
    cout << endl ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;

    Node *root = new Node (10) ;
    root->left = new Node(50) , root->right = new Node(60) , root->right->right = new Node(20) ;
    root->right->left = new Node(70) , root->right->left->right = new Node(8) ;

    left_view(root) ;
    print_left(root) ;

    return 0 ;
}