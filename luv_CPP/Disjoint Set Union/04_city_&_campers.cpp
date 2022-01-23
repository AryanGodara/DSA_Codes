/*
Problem
"Money money MONEY, I want money" thought Alex. "Now how do I get money? Well... I'll open up a camp!"

Well, unfortunately things didn't go so well for Alex's campers, and now there are N campers wandering around the city aimlessly. You have to handle Q queries; which consist of two groups finding each other and becoming one larger group. After each query, output the difference between the group of largest size and group of smallest size. If there is only one group, output 0. At first, everyone is in their own group.

Also note, if the two campers in the query are already in the same group, print the current answer, and skip merging the groups together.

Input:

The first line consists of two space separated integers, N and Q

The next Q line consists of two integers, A and B, meaning that the groups involving camper A and camper B find each other.

Output:

Output Q lines, the answer after each query.

Constraints:

1 <= N <= 105

1 <= Q <= 105
*/

# include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 10 ;

int parent[N] ;     // parent[i] = parent of node 'i'
int size[N] ;       // size[i] = no. of elements whose parent is 'i'

multiset <int> sizes ;

void make ( int v ) // Create a new set/tree
{
    parent[v] = v ; 
    // When creating a new group, the single element is also the root of the group
    size[v] = 1 ;
    sizes.insert(1) ;
}

int find ( int v )   // Return the parent/root of the group that contains node 'v'
{
    if ( v == parent[v] )   // This is the parent itself
        return v ;
    
    return parent[v] = find(parent[v]) ;    // Path Compression and Recursion

    // If this is not the parent, then we return the parent of the current node, and we also then
    // change the parent of the current node with the its parent, which goes on until, by the end
    // each node in this group, will have a common parent
}

void merge ( int a , int b )    // Merge these two function
{
    auto x = sizes.find(size[a]) ;  // Iterator
    auto y = sizes.find(size[b]) ;  // Iterator

    //? When we pass 'values' to multiset.erase, it'll erase all the matches. 
    //TODO: But, we want to only delete a single element from the set
    //* So, instead, we pass in 'iterators'

    sizes.erase(x) ;
    sizes.erase(y) ;
    sizes.insert(size[a] + size[b]) ;

    // Removed two previously independent sizes, and inserted a new size
}

void Union ( int a , int b )    // Join the groups containing node 'a' and node 'b'
                                // Root of one of the groups, gets connected to root of another
                                // This happens irrespective of the parameters of the function
                                // 'union' is a reserved keyword, so we use 'Union' instead
{
    a = find(a) ;
    b = find(b) ;

    if ( a != b )   // We can't join them, if they already belong to the same group
    {
        // We join the smaller tree to the bigger tree.
        if ( size[a] >= size[b] )
        {
            parent[b] = a ;
            
            merge(a,b) ;

            size[a] += size[b] ;    // All nodes of 'a' joined to 'b'
        }
        else
        {
            parent[a] = b ;

            merge(b,a) ;

            size[b] += size[a] ;    // All nodes of 'b' joined to 'a'.
        }
    }
}


int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;

    int n , k ;         // n nodes , k edges
    cin >> n >> k ;

    // We have to find the number of distinct connected componenets

    for ( int i = 1 ; i <= n ; i++ )
        make(i) ;
    
    while ( k-- )
    {
        int u , v ;
        cin >> u >> v ;

        // Now, print the difference between the largest and the smallest group

        Union(u,v) ;

        //? Now, to find the value fast ( O(1) ), we'll use multisets, instead of maintaining
        //? two variables for min and max, and using O(n) algos to find the max an min. :P

        if ( sizes.size() == 1 )    // Only a single group remains
            cout << 1 << endl ;
        else
        {
            int x = *(sizes.begin());
            int y = *(--sizes.end());

            cout << (y-x) << endl ;
        }
    }

    return 0 ;
}