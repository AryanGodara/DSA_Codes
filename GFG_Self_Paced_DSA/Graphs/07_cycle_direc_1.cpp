//? Detection of cycle in an undirected graph

# include <bits/stdc++.h>
using namespace std ;


bool DFSRec ( vector <int> adj[] , int s , bool visited[] , bool recSt[] )
{
    visited[s] = true ;
    recSt[s] = true ;

    for ( auto &child: adj[s] )
    {
        if ( !visited[child] && DFSRec(adj,child,visited,recSt) )
            return true ;
        else if ( visited[child] && recSt[child] == true )
            return true ;
    }

    recSt[s] = false ;  // Backtrack
    
    return false ;
}

bool DFS ( vector <int> adj[] , int V )
{
    bool visited[V] , recST[V] ;
    for ( int i = 0 ; i < V ; i++ )
        visited[i] = recST[i] = false ;
    
    for ( int i = 0 ; i < V ; i++ )
        if ( !visited[i] )
            if ( DFSRec(adj,i,visited,recST) )
                return true ;
    
    return false ;
}

void add_edge ( vector <int> adj[] , int u , int v )
{
    adj[u].push_back(v) ;
}

int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int V = 6 ;
    vector <int> adj[V] ;

    add_edge(adj,0,1) ;
    add_edge(adj,2,1) ;
    add_edge(adj,2,3) ;
    add_edge(adj,3,4) ;
    add_edge(adj,4,5) ;
    add_edge(adj,5,3) ;

    cout << ( DFS(adj,V) ? "Cycle Found" : "No Cycle Found" ) << endl ;

    return 0 ;
}