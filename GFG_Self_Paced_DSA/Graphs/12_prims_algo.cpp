/*
    // Add the Theory here
*/

# include <bits/stdc++.h>
using namespace std ;

# define V 4

int prim_MST ( int graph[V][V] )
{
    int key[V] ; key[0] = 0 ;
    int res = 0 ;
    bool mSet[V] = {0} ;    // Initially, all are false (No nodes in the prim set)

    for ( int count = 0 ; count < V ; count++ )
    {
        int u = -1 ;

        for ( int i = 0 ; i < V ; i++ )     // Traverse the 'key' array
            if ( !mSet[i] && ( u == -1 || key[i] < key[u] ) )   // Look for mset=false nodes
                u = i ;     // If the i'th ones key is less than u, then update u to i

        mSet[u] = true ;    // We're adding this to the prim set
        res += key[u] ;

        for ( int v = 0 ; v < V ; v++ )
            if ( graph[u][v] != 0 && !mSet[v] ) // u and v are connected, and v wasn't in mSet yet
                key[v] = min( key[v] , graph[u][v] ) ; // Then, update key of v
    }

    return res ;
}


int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int graph[V][V] = {
        {0,5,8,0},
        {5,0,10,15},
        {8,10,0,20},
        {0,15,20,0}
    };

    cout << prim_MST(graph) << endl ;

    return 0 ;
}