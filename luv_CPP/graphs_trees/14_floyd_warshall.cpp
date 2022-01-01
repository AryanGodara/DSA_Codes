# include <bits/stdc++.h>
using namespace std ;

const int N = 510 ;
const int INF = 1e9 + 10 ;

vector < vector <int> > dist ( N , vector <int> (N,INF) ) ;
// At first, the distance between each pair of nodes 'i' and 'j' is taken to be infinite


// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    for ( int i = 0 ; i < N ; i++ )
            dist[i][i] = 0 ;    // Distance of each node from itself is 0

    int n , e ;     // No of nodes, No of edges
    cin >> n >> e ;

    for  (int i = 0 ; i < e ; i++ )
    {
        int x , y , wt ;
        cin >> x >> y >> wt ;

        dist[x][y] = wt ;
    }

    // Now, we have to go through all the levels (k) allowed
    // Then, for all the levels, we have to find the min possible distance between i and j
    for ( int k = 1 ; k <= N ; k++ )
        for ( int i = 1 ; i <= N ; i++ )
            for ( int j = 1 ; j <= N ; j++ )
            if ( dist[i][k] != INF && dist[k][j] != INF )   // Only if a valid path exists
                dist[i][j] = min ( dist[i][j] , dist[i][k] + dist[k][j] ) ;

        // For each pair, if possible, we check if going from i to j through k, gives a smaller
        // route than the direct route

        // If no path exists b/w i and j, then their dist will remain INF

        // This algo handles -ve weights(unlike dijkstra), but doesn't handle -ve cycles
}