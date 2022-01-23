# include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 10 ;

int parent[N] ;     // parent[i] = parent of node 'i'
int size[N] ;       // size[i] = no. of elements whose parent is 'i'


void make ( int v ) // Create a new set/tree
{
    parent[v] = v ; 
    // When creating a new group, the single element is also the root of the group
    size[v] = 1 ;
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
            size[a] += size[b] ;    // All nodes of 'a' joined to 'b'
        }
        else
        {
            parent[a] = b ;
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

        Union(u,v) ;
    }

    // Now that we've constructed the groups, we need to find the number of connected components
    int count = 0 ;

    for ( int i = 1 ; i <= n ; i++ )
        if ( find(i) == i )     // Find the number of roots
            count++ ;

    cout << count << endl ;

    return 0 ;
}