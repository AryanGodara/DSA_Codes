/*
    1. No. of slots in hash table >= No. of keys to be inserted
    2. Cache Friendly
    3. We use a single linear array, instead of using any iterable for the elements of array

    Linear Probing : Linear Search for next empty slot when there is a collision
        hash(key) = key%7
        hash(key,i) = (h(key)+i)%7
        ? Primary Clusters
    Quadratic Probing :
        hash(key,i) = (h(key) + i*i)%7
        ! For quad probe, load factor < 0.5 , OR size of hash table is atleast double the no.
        ! of elements to be stored in this hash table
        ? Secondary Clusters
    
    Double Hashing :
        hadh(key,i) = ( h(key) + i*h2(key) ) % m
        * If h2(key) is relatively prime to m, then it'll always find a free slot, if it exists
        * Distributes keys more uniformly than linear probing and quadratic probing
        ? No clusters formed
        
        eg.: h1(key) = key%7 ,  h2(key) = 6 - key%6
        * h2(key) ishould relatively prime to m (m is the size of the hash table)
        ! Choose a function such that h2(key) NEVER returns 0, or it'll form an endless loop.
*/

/*
void double_hashing_input(key)
{
    if ( table is full )
        return error
    
    probe = h1(key) , offset = h2(key) ;

    while table[proble] in occupied
        proble = (probe + offset) % m ;
    
    table[probe] = key ; // Place the key in the free spot
}

! In the case of linear probing, offset is simply equal to 1
*/


//? Implementation of Open Addressing and how it can lead to avoiding of collision in Hashing

# include <bits/stdc++.h>
using namespace std ;

struct MyHash
{
    int *arr ;          // Pointer to an array
    int cap , size ;    // Max capacity of hash table, current size of hash table

    MyHash ( int c )    // Constructor
    {
        cap = c ;
        size = 0 ;

        arr = new int[cap] ;

        for ( int i = 0 ; i < cap ; i++ )
            arr[i] = -1 ;
        
        //* -1 = empty cell , -2 = value stored in cell was deleted
    }

    int hash ( int key )    //? Hash Function
    {
        return key%cap ;    // Very simple hash function
    }

    bool insert ( int key )
    {
        if ( size == cap )  // Capacity reached
            return false ;
        
        int i = hash(key) ;

        while ( arr[i] != -1  &&  arr[i] != -2  &&  arr[i] != key )
            i = (i+1)%cap ; //* Linear Probing (offset = 1)
        
        if ( arr[i] == key )    // Key was already present in the hash
            return false ;  // So, we couldn't insert the key
        else
        {
            arr[i] = key ;
            size++ ;

            return true ;
        }
    }

    bool search ( int key )
    {
        int h = hash(key) ;
        int i = h ;

        while ( arr[i] != -1 )  // Until we encounter an empty cell
        {
            if (  arr[i] == key )   // Element found inside the hash
                return true ;
                
            i = (i+1)%cap ;

            if ( i == h )   // Reached the beginning cell again (one entire loop is complete)
                return false ;
        }

        return false ;  // Found an element == -1 (Empty cell was found)
    }

    bool erase ( int key )
    {
        int h = hash(key) ;
        int i = h ;

        while ( arr[i] != -1 )
        {
            if ( arr[i] == key )
            {
                arr[i] = -2 ;
                return true ;
            }

            i = (i+1)%cap ;

            if ( i == h )
                return false ;
        }
        
        return false ;
    }
};

int main ()
{
    MyHash mh(7) ;

    mh.insert(49) ;
    mh.insert(56) ;
    mh.insert(72) ;

    cout << ( mh.search(56) ? "Yes\n" : "No\n" ) ;
    mh.erase(56) ;
    cout << ( mh.search(56) ? "Yes\n" : "No\n" ) ;

    return 0 ;
}

/*
    !Chaining vs Open Addressing :-

    ? Chaining :-
    1. Hash Table never fills
    2. Less sensitite to Hash Functions
    3. Poor cache performance
    4. Extra space for links

    ? Open Addressing :-
    1. Table may become full and resizing becomes mandatory
    2. Extra care required for clustering
    3. Cache friendly
    4. Extra space might be needed to achieve some performance as chaining
*/