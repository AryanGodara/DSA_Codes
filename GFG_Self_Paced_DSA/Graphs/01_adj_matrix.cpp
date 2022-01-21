# include <bits/stdc++.h>
using namespace std ;

/*
The two representations of graphs :-
    1. Adjacency Matrix
    2. Adjancency List
*/

// In this one, we discuss Adjacency Matrix Representation

class Graph
{
    private :
        bool** adjMatrix ; // Double Pointer, Pointer to pointer
        int numVertices ;

    public :
        // Initialize the matrix to zero

        Graph ( int numVertices )   // Constructor
        {
            adjMatrix = new bool*[numVertices] ;

            for ( int i = 0 ; i < numVertices ; i++ )
            {
                adjMatrix[i] = new bool[numVertices] ;
                for ( int j = 0 ; j < numVertices ; j++ )
                    adjMatrix[i][j] = false ;
            }
        }

        // Add edges
        void addEdge ( int i , int j )
        {
            adjMatrix[i][j] = true ;
            adjMatrix[j][i] = true ;
        }

        // Remove Edges
        void removeEdge ( int i , int j )
        {
            adjMatrix[i][j] = false ;
            adjMatrix[j][i] = false ;
        }

        // Print the Matrix
        void toString ()
        {
            cout << numVertices << endl ;               // Why is this happening???
            for ( int i = 0 ; i < numVertices ; i++ )
            {
                cout << i << " : " ;
                for ( int j = 0 ; j < numVertices ; j++ )
                    cout << adjMatrix[i][j] << " " ;
                cout << endl ;
            }
        }
} ;

// Driver Function
int main ()
{
    Graph g(4) ;

    g.addEdge(0,1) ;    
    g.addEdge(0,2) ;    
    g.addEdge(1,2) ;    
    g.addEdge(2,0) ;    
    g.addEdge(2,3) ;    

    g.toString() ;

    return 0 ;
}