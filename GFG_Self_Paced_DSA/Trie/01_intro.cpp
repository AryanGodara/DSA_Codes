/*
! TRIE DATA STRUCTURE :-
? Efficient for the followign operations on words in a dictionary :-
* 1. Search
* 2. Insert
* 3. Delete
* 4. Prefix Search
* 5. Lexicographical ordering of words

TODO Examples :-
! Input : insert('geek'), insert('geeks'), insert('bad'),
!         search('bad'), insert('bad'), search('eek'), delete('geek'), serach('geek'), print()

* Output : Yes No No Bad Bat geeks
*/

/*
! Trie (Representation, Serach, and Insert)

*/

# include <bits/stdc++.h>
using namespace std ;

const int ALPHABET_SIZE = 26 ;

struct TrieNode
{
    TrieNode *children[ALPHABET_SIZE];

    bool isEnd ;        // Is the end of the word, or the 'key' (From the key-value pair)
};

struct TrieNode *getNode (void) // Create a new node, and return it
{
    TrieNode *pNode = new TrieNode ;    // Create a new TrieNode, then initialize it below

    pNode -> isEnd = false ;    // This is not the last letter (When created)

    for ( int i = 0 ; i < ALPHABET_SIZE ; i++ ) // Set all the 'next' letters as false
        pNode -> children[i] = NULL ;
    
    return pNode ;
}

void insert ( TrieNode *root, string key )
{
    TrieNode *pCrawl = root ;

    for ( int i = 0 ; i < key.length() ; i++ )
    {
        int index = key[i] - 'a' ;

        if ( ! pCrawl->children[index] )    // If this prefix, did not already exist, create it
            pCrawl -> children[index] = getNode() ; // Assign a new TrieNode to this child

        pCrawl = pCrawl -> children[index]; // Move to the next one
    }

    pCrawl -> isEnd = true;
    // At this point, pCrawl, points to the last letter, of the word 'key'.
}

bool search ( TrieNode *root, string key )
{
    TrieNode *pCrawl = root ;

    for ( int i = 0 ; i < key.length() ; i++ )
    {
        if ( ! pCrawl -> children[ key[i]-'a' ] )   //? This word doesn't exist
            return false ;  //! NOT FOUND
    
    //* If it exists, then go to the child node, and check further
        pCrawl = pCrawl -> children[key[i]-'a'] ;
    }

    //TODO: Now, we've reached the 'last' letter of the 'key' string

    return ( pCrawl && pCrawl->isEnd );
    //* Check, if this one exists, and then, check if this is also the last character of the key
}

bool isEmpty ( TrieNode *root )
{
    for ( int i = 0 ; i < ALPHABET_SIZE ; i++ )
        if ( root->children[i] != NULL )
            return false ;
        
    return true ;
}

TrieNode *remove ( TrieNode *root, string key, int i )
{
    // Corner Case
    if ( !root )        // Trie doesn't exist lol
        return NULL ;
    
    // Base Case
    if ( i == key.size() )  // We've checked the whole string 'key'
    {
        if ( root->isEnd )
            root->isEnd = false ;
        //? This is no longer the end of a word (as we are removing this word now)

        if ( isEmpty(root) )    //* This root contains no children (all are NULL, this was the last)
        {
            delete (root) ; // Delete this root (root is a node of the Trie)
            root = NULL ;   // The pointer previously storing this 'root' is set to NULL
        }

        return root ;
        //! If this root was empty, then, we can simply delete this root, and set the variable as NULL
        //! But, if this wasn't NULL, then we can't delete this, as it has children nodes.
    }

    // Recursion
    int index = key[i] - 'a' ;

    // Call to Subproblem
    root->children[index] = remove(root->children[index] , key , i+1 ) ;
    //? If this root->child was NULL, this will remain NULL
    //? If this root->child was the 'last or isEnd', then it will be removed from isEnd
    //? If this root->child, did not have any further children, then this will be deleted, and set to NULL

    // If this root did not have any further children, and was also, not the end of any word. So,
    // we will not loose any word, if we delete this. So, it's safe to delete this.
    if ( isEmpty(root) && root->isEnd == false )
    {
        delete(root);
        root = NULL ;
    }

    return root ;
}

// Driver Function
int main ()
{
    string keys[] = { "bad", "bat", "geeks", "geeks", "cat", "cut" } ;
    int n = sizeof(keys)/sizeof(keys[0]) ;

    TrieNode *root = getNode() ;    //! We could've also used a contructor, intead of a separate function.

    for ( int i = 0 ; i < n ; i++ ) //? Insert All of the keys into the trie
        insert(root, keys[i]) ;

    cout << ( search(root,"bat") ? "Yes\n" : "No\n" ) ;          //* OP: True
    cout << ( search(root,"geeks") ? "Yes\n" : "No\n" ) ;        //* OP: True
    cout << ( search(root,"geek") ? "Yes\n" : "No\n" ) ;         //* OP: False

    TrieNode *deletethis = remove(root, "geeks", 0) ;
    cout << ( search(root,"geeks") ? "Yes\n" : "No\n" ) ;        //* OP: False

    return 0 ;
}