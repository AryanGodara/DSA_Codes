// Given the two arrays storing the preorder and inorder traversal of a binary tree.
// Construct the original binary tree.

# include <bits/stdc++.h>
using namespace std ;

// Node structure for the binary tree
struct Node
{
    int key ;
    Node *left , *right ;

    Node ( int key )
    {
        this -> key = key ;
        this -> left = this -> right = NULL ;
    }
};

// Functions to print the tree, in order to check our answer
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

void level_order ( Node *root ) // BFS
{
    if ( root == NULL )
        return ;
    
    queue <Node *> q ;
    q.push(root) ;

    while ( !q.empty() )
    {
        Node *cur = q.front() ;
        q.pop() ;
        cout << cur->key << " " ;

        if ( cur->left != NULL )
            q.push(cur->left) ;
        if ( cur->right != NULL )
            q.push(cur->right) ;
    }
}

            // DOESN'T WORK, BUT IT'S OKAY, DID SOME BREANSTORMING, SO IT WAS WORTH IT
// Utility Function, to help find elements in the array
int find_first ( int x , vector <int> &arr )
{
    for ( int i = 0 ; i < arr.size() ; i++ )
        if ( arr[i] == x )
            return x ;
    
    return -1 ;
}
// The main Utility Function
Node* solve ( vector <int> in , vector <int> pre , int is , int ps , int ie , int pe )
{
    if ( ie<=is )  // The preorder array is empty
        return NULL ;
    
    Node *head = new Node (pre[0]) ;    // The head of the newly formed BT

    // Base Cases
    if ( ie-is+1 == 3 )   // or pre.size() == 3
    {
        head->left = new Node(pre[1]) ;
        head->right = new Node(pre[2]) ;
        
        return head ;
    }
    else if ( ie-is+1 == 2 )
    {
        head->left = new Node(pre[1]) ;
        head->right = NULL ;

        return head ;
    }
    else if ( ie-is+1 == 1 )
    {
        head->left = head->right = NULL ;   // Don't actually need to write this lol

        return head ;
    }

    // Now, find the pos of pre[0] in the 'in' array, all the nos. to the left of pre[0]
    // are head->left, and all the nos on the right are head->right

    int pos = find_first(pre[0],in) ;
    if ( pos == -1 )    // The given arrays are invalid
        return NULL ;

    // Let's eliminate the two corner cases first
    if ( pos == 0 )
    {
        head->left = NULL ; // No left subtree, and all the rest, is from the right subtree
        is++ , ps++ ;
        //in = vector <int> ( in.begin()+1 , in.end() ) ;
        //pre = vector <int> ( pre.begin()+1 , pre.end() ) ;

        head->right = solve ( in , pre , is , ps , ie , pe ) ;

        return head ;
    }
    else if ( pos == in.size()-1 )
    {
        head->right = NULL ; // No right subtree, and all the rest is from the left subtree
        ie-- , ps++ ;
        //in.pop_back() ; // Remove the last element
        //pre = vector <int> ( pre.begin()+1 , pre.end() ) ;  // Remove the first element

        head->left = solve ( in , pre , is , ps , ie , pe ) ;

        return head ;
    }

    // Now, form two arrays 'left' and 'right', for the two recursive function calls

    int lps = ps+1 , rps = pos+1 , lpe = pe , rpe = pe ;
    //vector <int> left_pre = vector <int> ( pre.begin()+1 , pre.begin() + pos + 1 ) ;
    //vector <int> right_pre = vector <int> ( pre.begin()+pos+1 , pre.end() ) ;

    int lis = is , ris = pos+1 , lie = pos-1 , rie = ie ;
    //vector <int> left_in = vector <int> ( in.begin() , in.begin()+pos ) ;
    //vector <int> right_in = vector <int> ( in.begin()+pos+1 , in.end() ) ;

    // Now do the two recursive calls

    head->left = solve ( in , pre , lis , lps , lie , lpe ) ;
    head->right = solve ( in , pre , ris , rps , rie , rpe ) ;

    return head ;   // Return the head of the BT
}


// ACTUAL WORKING CODE
int preIndex = 0 ;

Node *cTree ( vector <int> &in , vector <int> &pre , int is , int ie )
{
    if ( is > ie )
        return NULL ;   // Invalid, or we exhausted all the nodes

    Node *root = new Node ( pre[preIndex++] ) ;

    int inIndex ;
    for ( int i = is ; i <= ie ; i++ )
        if ( in[i] == root->key )
        {
            inIndex = i ;
            break ;
        }
    
    root -> left = cTree ( in , pre , is , inIndex-1 ) ;
    root -> right = cTree ( in , pre , inIndex+1 , ie ) ;

    return root ;
}


// Driver Function
int main ()
{
    vector <int> in = { 40 , 20 , 60 , 50 , 70 , 10 , 80 , 100 , 30 } ;
    vector <int> pre = { 10 , 20 , 40 , 50 , 60 , 70 , 30 , 80 , 100 } ;

    // int n = in.size()-1 ;   // Pos of the last element, NOT SIZE OF ARRAY

    // Node *root = solve(in,pre,0,0,n,n) ;  // Stores the head of the newly formed binary tree

    Node *root = cTree ( in , pre , 0 , in.size()-1 ) ;
    // The functions below, print the binary tree

    cout << "Preorder : \n" ;
    preorder(root) ;
    cout << endl ;

    cout << "Inorder : \n" ;
    inorder(root) ;
    cout << endl ;
    
    cout << "Postorder : \n" ;
    postorder(root) ;
    cout << endl ;

    cout << "Level_Order : \n" ;
    level_order(root) ;
    cout << endl ;

    return 0 ;
}