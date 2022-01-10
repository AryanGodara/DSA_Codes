// We are given a BST, and a sum. We have to find whether a pair with given sum exists in the BST
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

// Inorder Traversal
//* 1. Do an inorder traversal of the given BST, and store it in an array
//* 2. Use the two pointer method to find the pair with given sum

void inorder_push ( Node *root , vector <int> &arr )
{
    if ( root == NULL )
        return ;
    
    inorder_push(root->left,arr);   // First check for left
    arr.push_back(root->key);    // Then push the cur value
    inorder_push(root->right,arr);  // Then check for right
}
bool find_pair ( Node *root , int sum )
{
    if ( root == NULL )
        return false ;

    vector <int> arr ;

    inorder_push(root,arr);

    // Now, we've filled the array
    int s = 0 , e = arr.size()-1 ;  // The two pointers

    while ( s <= e )
    {
        if ( arr[s] + arr[e] == sum )
            return true ;
        else if ( arr[s] + arr[e] < sum )
            s++ ;
        else
            e-- ;
    }

    return false ;
}

// OR, we can do the same thing, and instead of pushing inside an array, we push it into a set.
unordered_set <int> s ;
bool is_pair_sum ( Node *root , unordered_set<int> &s , int sum )
{
    if ( root == NULL )
        return false ;
    
    // Check for the left subtree
    if ( is_pair_sum(root->left,s,sum) )
        return true ;
    // Else, check for the sum of elements of left subtree + cur element, if possible
    if ( s.find(sum-root->key) != s.end() )
        return true ;
    
    s.insert(root->key);    // If no solution is found yet, insert the current node into the set

    return is_pair_sum(root->right,s,sum);    // Then check for right subtree, and return
}

int main ()
{
    // Make a tree, and run the two functions above to check
}