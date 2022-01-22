//? Given an Unweighted Graph and a source point, the task is to find the shortest path between 
//? the source point and every other point in the graph.

# include <bits/stdc++.h>
using namespace std ;

//? The primary DFS function

void BFS ( vector <int> adj[] , int V , int s , int dist[] )
{
    bool visited[V] ;
    for ( int i = 0 ; i < V ; i++ )
        visited[i] = false ;

    visited[s] = true ;
    
    queue <int> q ;
    q.push(s) ;

    while ( !q.empty() )
    {
        int cur = q.front () ;
        q.pop () ;

        for ( int child: adj[cur] )
        {
            if ( !visited[child] )
            {
                visited[child] = true ;
                dist[child] = dist[cur] + 1 ;
                q.push(child) ;
            }
        }
    }
}

//? Function to connect two edges
void add_edge ( vector <int> adj[] , int u , int v )
{
    adj[u].push_back(v) ;
    adj[v].push_back(u) ;
}


//? Driven Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int V = 4 ;
    vector <int> adj[V] ;
    int dist[V] ;       // dist[i] = distance of node 'i' from the root/source node '0' in this case

    add_edge(adj,0,1) ;
    add_edge(adj,1,2) ;
    add_edge(adj,2,3) ;
    add_edge(adj,0,2) ;
    add_edge(adj,1,3) ;

    dist[0] = 0 ;
    for ( int i = 1 ; i < V ; i++ )
        dist[i] = INT_MAX ;
    
    BFS(adj,V,0,dist) ;

    for ( int i = 0 ; i < V ; i++ )
        cout << dist[i] << " " ;

    return 0 ;
}