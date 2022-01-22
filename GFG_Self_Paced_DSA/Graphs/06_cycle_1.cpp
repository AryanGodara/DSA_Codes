// Detection of a Cycle in an Undirected Graph

# include <bits/stdc++.h>
using namespace std ;

void add_edge ( vector <int> adj[] , int u , int v )
{
    adj[u].push_back(v) ;
    adj[v].push_back(u) ;
}

bool DFSRec ( vector <int> adj[] , int s , bool visited[] , int parent )
{
    visited[s] = true ;

    for ( int u: adj[s] )
        if ( !visited[u] )
            if ( ( DFSRec(adj,u,visited,s) == true ) || u != parent )
                return true ;
    
    return false ;
}

bool DFS ( vector <int> adj[] , int V )
{
    bool visited[V] ;
    for ( int i = 0 ; i < V ; i++ )
        visited[i] = false ;
    
    for ( int i = 0 ; i < V ; i++ )
        if ( !visited[i] )
            if ( DFSRec(adj,i,visited,-1) == true )
                return true ;
    
    return false ;
}


//? Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int V = 6 ;
    
    vector <int> adj[V] ;

    add_edge(adj,0,1) ;
    add_edge(adj,1,2) ;
    add_edge(adj,2,4) ;
    add_edge(adj,4,5) ;
    add_edge(adj,1,3) ;
    add_edge(adj,2,3) ;

    cout << ( DFS(adj,V) ? "Cycle Found" : "No Cycle Found" ) << endl ;

    return 0 ;
}