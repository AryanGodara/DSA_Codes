// Given an undirected Graph having unit weight, find the shortest distance from source to all the points.
// If path is not possible, put -1

// Let source be 2 in this case, and the adjacency list matrix is ->
/*
* 0 -> 1,3
* 1 -> 0,2,3
* 2 -> 1,6
* 3 -> 0,4
* 4 -> 3,5
* 5 -> 4,6
* 6 -> 2,5,7,8
* 7 -> 6,8
* 8 -> 6,7
*/

// In this case, we just use a simple DFS algo.

# include <bits/stdc++.h>
using namespace std ;

const int N = 9 ;
vector<int> g[N] ;
int vis[N] ;
int dist[N] ;   // dist of node 'i' from the starting node (which can be 0, or any specific node)

queue <int> q ;

void bfs ( int src )
{
    vis[src] = 1 ;

    q.push(src) ;

    while (! q.empty() )
    {
        int cur = q.front() ;
        q.pop() ;
        vis[cur] = 1; 

        for ( auto &child : g[src] )
        {
            if ( dist[child] > 1 + dist[cur] )
            {
                dist[child] = 1 + dist[cur] ;
                q.push(child) ;
            }
        }
    }
}

int main()
{
    for ( int i = 0 ; i < N ; i++ )
        dist[i] = INT_MAX ;
    dist[0] = 0 ;

    bfs(0) ;
    
    for ( int i = 0 ; i < N ; i++ )
        cout << dist[i] << endl ;

    return 0 ;
}