# include <bits/stdc++.h>
using namespace std ;

//? Common for all

void DFSRec ( vector <int> adj[] , int u , bool visited[] )
{
    visited[u] = true ;
    cout << u << " " ;          // Remove cout statment for 3.

    for ( int &child: adj[u] )  // Go through all the children of the current node, and call DFS
        if ( !visited[child] )
            DFSRec(adj,child,visited) ;
}

void add_edge ( vector <int> adj[] , int u , int v )
{
    adj[u].push_back(v) ;
    adj[v].push_back(u) ;
}


//? 1.

void DFS ( vector <int> adj[] , int V , int s )
{
    bool visited[V] ;
    for ( int i = 0 ; i < V ; i++ )
        visited[i] = false ;
    
    DFSRec(adj,s,visited) ; // Call DFS for the source node (root)
}


//? 2.
void DFS ( vector <int> adj[] , int V )
{
    bool visited[V] ;
    for ( int i = 0 ; i < V ; i++ )
        visited[i] = false ;
    
    for ( int i = 0 ; i < V ; i++ )
        if ( !visited[i] )
            DFSRec(adj,i,visited) ;
}


//? 3.

int DFS ( vector <int> adj[] , int V , bool ignore_this_param ) // To ignore overloading value
{
    int count = 0 ;
    bool visited[V] ;
    for ( int i = 0 ; i < V ; i++ )
        visited[i] = false ;
    
    for ( int i = 0 ; i < V ; i++ )
    {
        if ( !visited[i] )
        {
            count++ ;
            DFSRec(adj,i,visited) ;
        }
    }

    return count ;
}


//? Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    //? 1. Vanilla DFS Code
/*
    int V = 5 ;
    vector <int> adj[V] ;

    add_edge(adj,0,1) ;
    add_edge(adj,0,2) ;
    add_edge(adj,2,3) ;
    add_edge(adj,1,3) ;
    add_edge(adj,1,4) ;
    add_edge(adj,3,4) ;

    cout << "Following is Depth First Traversal: " << endl ;
    DFS(adj,V,0) ;
*/

    //? 2. For disconnected graph
/*
    int V = 5 ;
    vector <int> adj[V] ;

    add_edge(adj,0,1) ;
    add_edge(adj,0,2) ;
    add_edge(adj,1,2) ;
    add_edge(adj,3,4) ;

    cout << "Following is Depth First Traversal for Disconnected Graphs: " << endl ;
    DFS(adj,V) ;
*/

    //? 3. For finding connected components
 
    int V = 5 ;
    vector <int> adj[V] ;

    add_edge(adj,0,1) ;
    add_edge(adj,0,2) ;
    add_edge(adj,1,2) ;
    add_edge(adj,3,4) ;

    cout << "Number of connected componenets: " << DFS(adj,V,true)<< "_is_count." << endl ;

    return 0 ;
}

/*
? Applications of DFS :-

* 1. Cycle Detection
* 2. Topological Sorting
* 3. Strongly Connected Components
* 4. Solving Maze and Similar Puzzles
* 5. Path Finding
*/