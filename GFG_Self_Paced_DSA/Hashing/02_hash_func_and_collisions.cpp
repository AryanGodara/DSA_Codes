/*
    How Hash Functions Work ?

    1. Should always amp a large key to a small key

    2. Should generate values from 0 to m-1

    3. Should be fast, O(1) for integers, and O(len) for strings of length 'len'

    4. Should uniformly distribute large keys into Hash Table Slots


    Examples of some Hash Functions :-

    1. h(large_key) = large_key % m

    2. For strings, weighted sum : str[] = "abcd"
       h("abcd") = str[0] * x^0   +   str[1] * x^1   +   str[2] * x^2   +   str[3] * x^3
    
    3. Universal Hashing
*/

/*
    If we know keys in advanced, then we can perfect the hashing. But if we don't know the 
    keys in advance, then we use on of the following :-

    1. Chaining

    2. Open Addressing
        a. Linear Probing
        b. Quadratic Probing
        c. Double Hashing
*/

/*
    Data Structures for Storing Chains :-
    
    1. Linked List

    2. Dynamic Sized Arrays (Vector:C++ , Arraylist:Java , List Python)

    3. Self Balancing BST ( AVL Tree , Red Black Tree )
*/

//? Program to Demonstrate implementatble of our hown hash table with CHAINING for 
//? collision detection

# include <bits/stdc++.h>
using namespace std ;

struct MyHash
{
    int BUCKET ;

    list <int> *table ;     //* Array of type : 'linked list'

    MyHash ( int b )    // Constructor
    {
        BUCKET = b ;

        table = new list<int>[BUCKET] ;
    }

    bool insert ( int k )
    {
        int i = k%BUCKET ;
        table[i].push_back(k) ;
    }

    bool search ( int k )
    {
        int i = k % BUCKET ;

        for ( auto &x : table[i] )
            if (  x == k )
                return true ;
        
        return false ;
    }

    void remove ( int k )
    {
        int i = k%BUCKET ;
        table[i].remove(k) ;
    }
};

//? Driver Function
int main ()
{
    MyHash mh(7) ;

    mh.insert(10) ;
    mh.insert(20) ;
    mh.insert(15) ;
    mh.insert(7) ;

    cout << mh.search(10) << endl ;

    mh.remove(15) ;

    cout << mh.search(10) << endl ;

    return 0 ;
}