/*

? Algorithm

* 1. Initialize all vertices as not visited.
* 2. Do the following for each vertex 'v'
*   (a) If 'v' hasn't been visited before, call DFSUtil(v)
*   (b) Print new line character
* 
TODO: This Function performs DFS Traversal
* DFSUtil(v):
* 1. Mark 'v' as visited.
* 2. Print 'v'
* 3. Do following for every adjacent 'u' of 'v'.
*   If 'u' is not visited, then recursively call DSFSUtil(u)

*/

//? A C++ Program to print connected components in an undirected graph.
# include <bits/stdc++.h>
using namespace std ;

//? Graph class represents an undirected graph using adjacency list representation
class Graph {
    int V ; // No. of vertices

    // Pointer to an array containing adjacency lists
    list <int> *adj ;
    
    // A function used by DFS
    void DFSUtil ( int v , bool visited[] ) ;

    public:
        Graph ( int V ) ;   // Constructor
        void addEdge ( int v , int w ) ;
        void connectedComponents () ;
};

//? Method to print connected components in an undirected graph
void Graph::connectedComponents ()
{
    // Marks all the vertices as not visited
    bool *visited = new bool[V] ;

    for ( int v = 0 ; v < V ; v++ )
        visited[v] = false ;

    for ( int v = 0 ; v < V ; v++ )
    {
        if ( !visited[v] )
        {
            DFSUtil(v,visited) ;
            cout << "\n" ;
        }
    }
}

void Graph::DFSUtil ( int v , bool visited[] )
{
    //? Mark the current node as visited and print it
    visited[v] = true ;
    cout << v << " " ;

    // Recur for all the vertices adjacent to this vertex

    list <int> :: iterator i ;

    for ( i = adj[v].begin() ; i != adj[v].end() ; i++ )
        if ( !visited[*i] )
            DFSUtil(*i,visited) ;
}

Graph::Graph ( int V )
{
    this -> V = V ;
    adj = new list<int> [V] ;
}

//? Method to add an undirected edge
void Graph::addEdge ( int v , int w )
{
    adj[v].push_back(w) ;
    adj[w].push_back(v) ;
}

//? Driver Program to test above
int main ()
{
    //? Create a graph given in the above diagram
    Graph g(5) ;    // 5 verties numbered 0-4

    g.addEdge(1,0) ;
    g.addEdge(1,2) ;
    g.addEdge(3,4) ;

    cout << "Following are connected components \n";
    g.connectedComponents();

    return 0;
}