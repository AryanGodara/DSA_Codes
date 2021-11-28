// Preorder Traversal based approach for serializing and deserializing a Binary Tree

# include <bits/stdc++.h>
using namespace std ;

// The process of converting a binary tree into a string or an array is called serializing
// And the reverse process, i.e., converting a string or an array, that has all the 
// necessary information about the binary tree, back into a binary tree is called deserializing.

struct Node
{
    int key ;
    Node *left , *right ;

    Node ( int key )
    {
        this->key = key ;
        left = right = NULL ;
    }
};

const int null = -1 ;   // We assume that, no node has the value -1

void serialize ( Node *root , vector <int> &arr )
{
    if ( root == NULL )
    {
        arr.push_back(null) ;
        return ;
    }

    arr.push_back(root->key) ;

    serialize(root->left,arr) ;
    serialize(root->right,arr) ;

}

Node* deserialize ( vector<int> &arr , int &index )
{
    if ( index == arr.size() )
        return NULL ;
    
    int val = arr[index++] ;
    // store the current value, and then increment the index

    Node *root = new Node(val) ;

    root->left = deserialize(arr,index) ;
    root->right = deserialize(arr,index) ;

    return root ;
}

void printList ( Node *root )   // Preorder Traversal
{
    if ( root == NULL )
        return ;
    
    cout << root->key << " " ;
    printList(root->left) ;
    printList(root->right) ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    // Constructing the Binary Tree
    Node *root = new Node(10) ;
    root->left=new Node(20),root->left->left=new Node(30),root->left->left->right=new Node(40) ;

    // Serialization
    vector <int> arr ;

    serialize(root,arr) ;

    for ( auto &x : arr )
        cout << x << " " ;
    cout << endl ;


    // Deserialization
    int index = 0 ;
    Node *head = deserialize(arr,index) ;

    printList(head) ;
    cout << endl ;

    return 0 ;
}