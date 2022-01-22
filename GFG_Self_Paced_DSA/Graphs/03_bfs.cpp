# include <bits/stdc++.h>
using namespace std ;

//? No. 1

void BFS ( vector <int> adj[] , int V , int s )
{
    vector <bool> visited (V,false) ;

    queue <int> q ;
    visited[s] = true ;
    q.push(s) ;

    while ( !q.empty() )
    {
        int u = q.front() ;
        q.pop() ;

        cout << u << " " ;
        
        for ( auto &child: adj[u] )
        {
            if ( !visited[child] )
            {
                visited[child] = true ;
                q.push(child);
            }
        }
    }
}

//? No. 2

void BFS ( vector <int> adj[] , int s , vector <bool> &visited )
{
    queue <int> q ;
    visited[s] = true ;
    q.push(s) ;

    while ( !q.empty() )
    {
        int u = q.front() ;
        q.pop() ;

        cout << u << " " ;
        
        for ( auto &child: adj[u] )
        {
            if ( !visited[child] )
            {
                visited[child] = true ;
                q.push(child);
            }
        }
    }
}

void BFSDin_1 ( vector <int> adj[] , int V )
{
    vector <bool> visited(V,false) ;

    for ( int i = 0 ; i < V ; i++ )
    {
        if ( !visited[i] )
            BFS(adj,i,visited);
    }
}

//? No. 3

void BFS ( vector <int> adj[] , int s , bool visited[] )
{
    queue <int> q ;

    visited[s] = true ;
    q.push(s) ;

    while ( !q.empty() )
    {
        int u = q.front () ;
        q.pop() ;

        for ( int &v: adj[u] )
        {
            if ( !visited[v] )
            {
                visited[v] = true ;
                q.push(v) ;
            }
        }
    }
}

int BFSDin_2 ( vector <int> adj[] , int V )
{
    bool visited[V] ;
    int count = 0 ;

    for ( int i = 0 ; i < V ; i++ )
        visited[i] = false ;
    
    for ( int i = 0 ; i < V ; i++ )
    {
        if ( !visited[i] )
        {
            BFS(adj,i,visited) ;
            count++ ;
        }
    }

    return count ;
}

//? Common Function

void add_edge ( vector <int> adj[] , int u , int v )
{
    adj[u].push_back(v) ;
    adj[v].push_back(u) ;
}


//? Driver Function
int main ()
{

    ios_base :: sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    //? Given an undirected graph and a source vertex 's', print B.F.S. from given source
/*
    int V = 5 ;
    vector <int> adj[V] ;

    add_edge(adj,0,1) ;
    add_edge(adj,0,2) ;
    add_edge(adj,1,2) ;
    add_edge(adj,2,3) ;
    add_edge(adj,1,3) ;
    add_edge(adj,3,4) ;
    add_edge(adj,2,4) ;

    cout << "Following is the Breadth First Traversal: \n" ;
    BFS(adj,V,0);
*/

    //? B.F.S. on disconnected graphs
/*
    int V = 7 ;
    vector <int> adj[V] ;

    add_edge(adj,0,1) ;
    add_edge(adj,0,2) ;
    add_edge(adj,2,3) ;
    add_edge(adj,1,3) ;
    add_edge(adj,4,5) ;
    add_edge(adj,5,6) ;
    add_edge(adj,4,6) ;

    cout << "Following is Breadth First Traversal: \n" ;
    BFSDin_1(adj,V) ;
*/

    //? Print number of islands in a graph (or number of connected components in a graph)

    int V = 7 ;
    vector <int> adj[V] ;

    add_edge(adj,0,1) ;
    add_edge(adj,0,2) ;
    add_edge(adj,2,3) ;
    add_edge(adj,1,3) ;
    add_edge(adj,4,5) ;
    add_edge(adj,5,6) ;
    add_edge(adj,4,6) ;

    cout << "Number of islands: " << BFSDin_2(adj,V) << endl ;

    return 0 ;
}

/*

? Applications of BFS :-

* 1. Shortest Path in an unweighted Graph
* 2. Crawlers in Search Engine
* 3. Peer to Peer Networks
* 4. Social Networking Search
* 5. In Garbage Collection (Chiney's Algorithm)
* 6. Cycle Detection
* 7. Ford Fulkerson Algorithm
* 8. Broadcasting

*/