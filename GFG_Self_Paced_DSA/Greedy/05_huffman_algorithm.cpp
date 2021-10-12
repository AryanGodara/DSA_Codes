/*
    Huffman Algorithm :-
        1. Variable Length Encoding (The max occurring character gets the smallest code)
        2. No prefix rule   (Code of 1 character can't be the prefix of another character)
    (High Level Idea)

    I/P : [ 'a' , 'd' , 'b' , 'e' , 'f' ]       // Total chars = 5
          [ 10  , 50  , 20  , 40  , 80  ]       // Total length = 200

    1. Build a Binary Tree
        a. Every input character is a leaf
        b. Every left edge is labelled as 0 and right edge as 1.
        c. Every root to leaf path represents Huffman code of the leaf

            __ 200
            /  \
        0 /     \   1                   // f = 0
        /        \
    f 80      ___ 120
                /  \
            0 /     \   1               // d = 10
            /        \  
        d 50        ___ 70
                    /  \
                0 /     \   1           // e = 111
                /        \     
            ___ 30      e 40
            /  \
        0 /     \   1                   // a = 1100     // b = 1101
        /        \ 
    a 10        b 20

    2. Traverse the Binary tree and print the ecodes

    f 0     a 1100
    d 10    b 1101
    a 1100  c 111

    Instead of empty space,ie.,__, we can use any symbol, like a '$' to reprsent a dummy node
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    Detailed Algorithm :-

    CREATING THE BINARY TREE

    1. Create leaf nodes and build a Min Heap h of all the leaves initially.

    2. While h.size() > 1 :
        a. left = h.extractMin()    b. right = h.extractMin()
    
    3. Create a new tree node with :
        a. Character '$'
        b. frequency as left.freq + right.freq
        c. Left and right children as left and right, respectively
        d. Insert a new node into h
    
    4. The only nod left in h is our required binary tree

    PRINTING THE BINARY TREE

    void printCodes ( root , str = "" )
        if ( root == NULL )
            return 
        if ( root.data != '$' ) // We have reached a leaf node
            print( root.ch + " " + str )
            return      // Nowhere else to go from here
        
        printCodes ( root.left , str + '0' )    // Recursive call to the left child
        printCodes ( root.right , str + '1' )   // Recursive call to the right child
*/


// CODE :-


// A Huffman Tree Node
struct Node
{
    // One of the input characters
    char data ;

    // Frequency of the character
    unsigned freq ;

    // Left and right child
    Node *left , *right ;

    Node ( char data , unsigned freq , Node *l = NULL , Node *r = NULL )    // Constructor
    {
        this -> left = l ;
        this -> right = r ;
        this -> data = data ;
        this -> freq = freq ;
    }
} ;

// For comparison of two heap nodes ( needed in min heaps )
struct compare
{
    bool operator() ( Node *l , Node *r )
    {
        return ( l->freq > r->freq ) ;
    }
} ;

// Print huffman codes from the root of the binary tree
void printCodes ( struct Node *root , string str )
{
    if ( !root )
        return ;
    
    if ( root -> data != '$' )  // Leaf node
        cout << root -> data << " : " << str << endl ;
    
    printCodes ( root -> left , str + '0' ) ;
    printCodes ( root -> right , str + '1' ) ;
}

// The main Function that build a Huffman tree and print codes by traversing that Huffman tree
void printHcodes ( vector <char> arr , vector <int> freq , int size )
{
    // Creating a min heap and inserting all characters of data[]
    priority_queue < Node* , vector<Node*> , compare > h ;

    for ( int i = 0 ; i < size ; i++ )  // Inserting the elements in the heap
        h.push ( new Node(arr[i],freq[i]) ) ;

    // Iterate while the size of the heap doesn't become 1

    while ( h.size() > 1 )
    {
        // Extract the two minimum freq items from min heap
        Node *l = h.top() ;     h.pop() ;     // Now, remove this item
        Node *r = h.top() ;     h.pop() ;     // Remove this one too

        // Create a new internal node with frequency equal to the sum of the two nodes' freqs.
        // Make the two extracted nodes as left and right children of this new node. Add this node
        // to the min heap '$' is a special value for internal nodes, not used

        Node *top = new Node ( '$' , l->freq + r->freq , l , r ) ;

        h.push(top) ;   // Insert this new node into the heap
    }

    // Print the Huffman codes using the Huffman tree built above
    printCodes( h.top() , "" ) ;
}


// Driver Code
int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL); 

    vector <char> arr1 = {  'a' ,  'd' ,  'e' ,  'f' } ;
    vector <int> freq1 = {   30  ,  40  ,  80  , 60  } ;

    vector <char> arr2 = {  'a' , 'd' , 'b' , 'e' , 'f' } ;
    vector <int> freq2 = {  10  , 50  , 20  , 40  , 80  } ;

    int size1 = arr1.size() ;
    int size2 = arr2.size() ;

    printHcodes ( arr1 , freq1 , size1 ) ;
    cout << endl << endl ;
    printHcodes ( arr2 , freq2 , size2 ) ;

    return 0 ;
}