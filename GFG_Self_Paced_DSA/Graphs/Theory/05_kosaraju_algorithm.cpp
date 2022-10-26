//! blablablsdflskajffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff

# include <bits/stdc++.h>
using namespace std ;

/*

* 

? KOSARAJU'S ALGORITHM :-
* 
* 1. Create an empty stack 'S' and do DFS traversal of a graph. In DFS traversal, after calling
*    a recursive DFS for adjacent vertices of a vertex, push the vertex to stack. In the above
*    graph, if we start DFS from vertex 0, we get vertices in stack as 1, 2, 4, 3, 0.
* 
* 2. Reverse directions of all arcs to obtain the transpose graph.
* 
* 3. One by one pop a vertex from S, while S is not empty. Let the popped vertex be 'v'. Take v
*    as source and do DFS ( cal DFSUtil(v) ). The DFS starting from v prints strongly connected
*    component of v. In the above example, we process vertices in order 0, 3, 4, 2, 1 (One by 
*    one popped from the stack).
* 

*/

# include <bits/stdc++.h>
using namespace std ;

class Graph
{
    int V ; // No. of vertices
    list <int> *adj ;   // An array of adjacency lists

    // Fills Stack with vertices ( in increasing order of finishing times ). The top element of
    // stack has the maximum finishing time.
    void fillOrder ( int v, bool visited[], stack <int> &Stack ) ;

    // A recursive function to print DFS starting from v
    void DFSUtil ( int v, bool visited[] ) ;

    public:

        Graph ( int V ) ;
        void addEdge ( int v , int w ) ;

        // The main function that finds and prints strongly connected components
        void printSCCs () ;
    
        // Function that returns reverse ( or transpose ) of this graph
        Graph getTranspose () ;
};

//? Constructor
Graph :: Graph ( int V )
{
    this -> V = V ;
    adj = new list<int>[V] ;
}

//? A recursive function to print DFS starting from v
void Graph :: DFSUtil ( int v , bool visited[] )
{
    // Mark the current node as visited and print it
    visited[v] = true ;
    cout << v << " " ;

    // Recur for all the vertices adjacent to this vertex
    list <int> :: iterator i ;

    for ( i = adj[v].begin() ; i != adj[v].end() ; i++ )
        if ( !visited[*i] )
            DFSUtil(*i,visited) ;
}

Graph Graph::getTranspose ()
{
    Graph g(V) ;    // Make a graph with contructor

    for ( int v = 0 ; v < V ; v++ )
    {
        // Recur for all the vertices adjacent to this vertex
        list <int> :: iterator i ;

        for ( i = adj[v].begin() ; i != adj[v].end() ; i++ )
            g.adj[*i].push_back(v) ;
    }

    return g ;
}

void Graph :: addEdge ( int v , int w )
{
    adj[v].push_back(w) ;   // Add w to v's list
}

void Graph :: fillOrder ( int v , bool visited[] , stack <int> &Stack )
{
    // Mark the current node as visited and print it
    visited[v] = true ;

    // Recur for all the vertices adjacent to this vertex
    list <int> :: iterator i ;

    for ( i = adj[v].begin() ; i != adj[v].end() ; i++ )
        if ( !visited[*i] )
            fillOrder(*i, visited, Stack) ;

    // All vertices reachable from v are processed by now, push v
    Stack.push(v) ;
}

//? The main function that finds and prints all strongly connected components
void Graph :: printSCCs ()
{
    stack <int> Stack ;

    // Mark all the vertices as not visited ( For first DFS )
    bool *visited = new bool[V] ;

    for ( int i = 0 ; i < V ; i++ )
        visited[i] = false ;

    // Fill vertices in stack according to their finish times
    for ( int i = 0 ; i < V ; i++ )
        if ( !visited[i] )
            fillOrder(i, visited, Stack) ;

    // Create a reverse graph
    Graph gr = getTranspose() ;

    // Mark all the vertices as not visited (For second DFS)
    for ( int i = 0 ; i < V ; i++ )
        visited[i] = false ;
    
    // Now process all vertices in order defined by Stack
    while ( !Stack.empty() )
    {
        // Pop a vertex from stack
        int v = Stack.top() ;
        Stack.pop() ;

        // Print strongly connected component of the popped vertex
        if ( !visited[v] )
        {
            gr.DFSUtil(v, visited) ;
            cout << "\n" ;
        }
    }
}

//? Driver program to test above function
int main ()
{
    Graph g(5) ;
    g.addEdge(1, 0) ;
    g.addEdge(0, 2) ;
    g.addEdge(2, 1) ;
    g.addEdge(0, 3) ;
    g.addEdge(3, 4) ;

    cout << "Following are strongly connected components in the given graph :- \n" ;
    g.printSCCs();

    return 0;
}