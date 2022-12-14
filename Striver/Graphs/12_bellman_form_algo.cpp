# include <bits/stdc++.h>
using namespace std ;

//! Works ONLY for directed Graph
/*
If given an undirected graph, convert it to directed like this :-

1 ---> 2

  --->
1      2
  <---

*/

// It works for negative weighed edges, and also helps in detecting negative cycles

/*
Relax all the edges, one-by-one sequentially
Relaxation -> dist[u] + wt < dist[v] ==> dist[v] = dist[u] + wt

Therefore, perform this relaxation on each edge -> One complete iteration.
Now, do this V-1 times (to get the final values)

The list of edges is of the form : (u,v,wt) -> edge from node u to node v has weight wt

! If we do another cycle, and the dist[i] of any edge(s) decreases, it means that there's a NEGATIVE CYCLE
*/

vector<int> bellmanFord(int V , vector<vector<int>> &edges, int S)
{
    vector<int> dist(V,INT_MAX) ;   // V = no of nodes
    dist[S] = 0 ;   // S = source node

    for ( int i = 0 ; i < V-1 ; i++ )
    {
        for ( auto &edge : edges )  // Cycle through each edge, V-1 times
        {
            int u = edge[0] , v = edge[1] , wt = edge[2] ;
            if ( dist[u] != INT_MAX )
                if (  dist[u] + wt < dist[v] )
                    dist[v] = dist[u] + wt ;
        }
    }

    // N'th relaxation, to check negative cycle
    for ( auto &edge : edges )
    {
        int u = edge[0] , v = edge[1] , wt = edge[2] ;
        if ( dist[u] != INT_MAX )
            if ( dist[u] +wt < dist[v] )    // A negative cycle exists
                return {-1} ;   // Empty array, signalling, min distance array is NOT possible
    }

    return dist ;
}

int main()
{
    // Create a dummy array, and call bellmanFord
}