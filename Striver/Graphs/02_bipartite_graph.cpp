# include <bits/stdc++.h>
using namespace std ;

// A bipartite graph is a graph that can be coloured with just two colours such that no two adjacent nodes have
// the same colour.
// In short, Each adjacent node must have opposite sign, for a graph to be bipartite.

// BFS Algo: Just brute force, whenever conflict arises, return false.
// DFS Algo, Also a brute force approach

const int N = 10 ;
vector <int> g[N] ;

bool bfs ( int i , vector<int> g[] , int vis[] )
{
    

    queue <int> q ;
    q.push(1) ;
    vis[i] = 1 ;

    while ( !q.empty() )
    {
        int cur = q.front() ;
        q.pop() ;

        for ( auto &child: g[cur] )
        {
            if (!vis[child])
            {
                q.push(child) ;
                vis[child] = !vis[cur] ;
            }

            else if ( vis[child] == vis[cur] )  // Conflict occuring here
                return false ;
        }
    }

    return true ;   // No conflict arised / arose ?? I really don't know xD
}

bool dfs ( int i , int col , vector<int> g[] , int vis[] )
{
    vis[i] = 1 ;

    for ( auto &child: g[i] )
    {
        if ( vis[child] == -1 )
            if ( dfs(child, !col, g, vis) == false )
                return false ;
        
        if ( vis[child] == col )
            return false ;
    }

    return true ;
}

bool isBipartitieDFS ( int N , vector<int> adj[] ) 
{
    int vis[N] ;
    for ( int i = 0 ; i < N ; i++ )
        vis[i] = -1 ;   // Initially, all are marked as unvisited.
    // Now, we just need to make sure we can mark adjacent graphs as +1 , -1

    for ( int i = 1 ; i <= N ; i++ ) 
        if (vis[i] == -1)
            if ( dfs(i,1,g,vis) == false )
                return false ;

    return true ;   // No conflict in any of the connected components.
}
bool isBipartitieBFS ( int N , vector<int> adj[] ) 
{
    int vis[N] ;
    for ( int i = 0 ; i < N ; i++ )
        vis[i] = -1 ;   // Initially, all are marked as unvisited.
    // Now, we just need to make sure we can mark adjacent graphs as +1 , -1

    for ( int i = 1 ; i <= N ; i++ ) 
        if (vis[i] == -1)
            if ( bfs(i,g,vis) == false )
                return false ;

    return true ;   // No conflict in any of the connected components.
}