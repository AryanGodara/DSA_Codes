# include <bits/stdc++.h>
using namespace std ;

// Adjacency List Representation of Graph

/*
The 
std::vector <char> vechar[2] 
declares an array consisting of two vectors of char 
(it's the same syntax as used in, For example, int arr[2]).

Thus, vechar[0] is one vector of char, and vechar[1] is another vector of char.

Both vectors start off empty, but can be resized.
*/

void addEdge ( vector <int> adj[] , int u , int v )
{
    adj[u].push_back(v) ;
    adj[v].push_back(u) ;
}

void printGraph ( vector <int> adj[] , int V )  // A array of 'vector<int>' type.
{
    for ( int i = 0 ; i < V ; i++ )
    {
        cout << endl << "Adjacency list of vertex " << i << endl << "head " ;
        for ( int x : adj[i] )
            cout << " -> " << x << " " ;
        cout << endl ;
    }
}

// Driver Code
int main ()
{
    int V = 4 ;
    vector <int> adj[V] ;   // An array of 'vector<int> type', of size V.

    addEdge(adj,0,1) ;
    addEdge(adj,0,2) ;
    addEdge(adj,1,2) ;
    addEdge(adj,1,3) ;

    printGraph(adj,V) ;

    return 0 ;
}