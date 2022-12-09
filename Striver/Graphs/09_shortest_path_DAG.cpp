// Find the shortest distance between two points in a weighted-directed-acyclic-graph.

# include <bits/stdc++.h>
using namespace std ;

/*
1. Perform a topological sort of the graph (and store the data in a stack)
2. Take each node out of the stack and relax the edges.
*/

const int N = 6 ;
vector<pair<int,int>> g[N] ;
int vis[N] ;
int dist[N] ;   // dist of node 'i' from the starting node (which can be 0, or any specific node)
stack <int> s; 

void topoSort ( int node )
{
    vis[node] = 1 ;

    for ( auto &child : g[node] )
        if ( !vis[child.first] )
            topoSort(child.first) ;

    s.push(node) ;
}

vector <int> shortestPath ( int n , int m )
{
    for ( int i = 0 ; i < n ; i++ )
        if ( !vis[i] )
            topoSort(i) ;
    
    // After obtaining the toposort, inside a stack.
    // Take the top element of the stack, and find the min distance to its adjacent nodes
    
    // Initially, distance of all nodes to source node = inf , and distance of source node to itself is 0

    for ( int i = 0 ; i < N ; i++ )
        dist[i] = INT_MAX ;
    dist[0] = 0 ;

    while ( !s.empty() )
    {
        int cur = s.top() ;
        s.pop() ;

        for ( auto &child : g[cur] )
            if ( dist[child.first] > dist[cur] + child.second ) // child.second = wt
                dist[child.first] = dist[cur] + child.second ;
    }
}

int main()
{

}