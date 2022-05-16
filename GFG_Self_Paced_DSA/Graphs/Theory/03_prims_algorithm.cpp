///////////////////////////////////////////////////////////////////////////////////////////////
/*
* 

? Algorithm

* 1. Create a set mstSet that keeps track of vertices already included in MST.
* 
* 2. Assign a keyvalue to all vertices in the input graph. Initialize all key values as INF.
*    Assign key value as 0 for the first vertex so that it's picked first
* 
* 3. While smtSet doesn't include all vertices :
*   a) Pick a vertex u which is not there in mstSet and has minimum key value.
*   b) Include u to mstSet.
*   c) Update key value of all adjacent vertices to u. To update the key values, iterate through
*      all adjacent vertices. For every adjacent vertex v, if weight of edge u-v is less than the
*      previous key value of v, update the key value as weight of u-v
* 

TODO: The idea of using key value is to pick the minimum weight edge from cut. The key values are
TODO: used only for vertices which aren't yet included in MST, the key value for these vertices
TODO: indicate the minimum weight edges connecting thme which aren't yet included in the MST, the
TODO: key value for these vertices indicate the minimum weight edges connecting them to the set of
TODO: vertices included in MST.

! How to implement the algorithm?

TODO: We use a boolean array mstSet[] to represent the set of vertices included in MST. If a value
TODO: mstSet[v] is true, then vertex v is included in MST, otherwise not. Array key[] is used to store
TODO: key values of all vertices. Another array parent[] to store indexes of parent nodes in mST. The
TODO: parent array is the output array which is used to show the contstructred MST.

* 
*/

//? A C++ program for Prim's Minimum Spanning Tree (MST) algorithm. The program is 
//? for adjacency matrix representation of the graph

# include <bits/stdc++.h>
using namespace std ;

# define V 5    // Number of vertices in the graph

//? A utility function to find the vertex with minimum key value, from the set of 
//? vertices not yet included in MST
int minKey ( int key[] , bool mstSet[] )
{
    // Initialize min value
    int min = INT_MAX , min_index ;

    for ( int v = 0 ; v < V ; v++ )
        if ( mstSet[v] == false && key[v] < min )
            min = key[v] , min_index = v ;
        
    return min_index ;
}

//? A utility function to print the constructed MST stored in parent[]
int printMST ( int parent[] , int graph[V][V] )
{
    cout << "Edge \tWeight\n" ;

    for ( int i = 1 ; i < V ; i++ )
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n" ;
}

//? Function to construct and print MST for a graph represented using adjacency matrix
void printMST ( int graph[V][V] )
{
    // Array to store constructed MST
    int parent[V] ;

    // Key values used to pick minimum weight edge in cut
    int key[V] ;

    // To represent set of vertices not yet included in MST
    bool mstSet[V] ;

    // Initialize all keys as INFINITE
    for ( int i = 0 ; i < V ; i++ )
        key[i] = INT_MAX , mstSet[i] = false ;
    
    // Always include 1st vertex in MST, make key 0 so that this vertex is picked as first
    key[0] = 0 ;
    parent[0] = -1 ;    // First node is always root of MST

    // The MST will have V vertices

    for ( int count = 0 ; count < V-1 ; count++  )
    {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey( key , mstSet ) ;

        // Add the picked vertex to MST Set
        mstSet[u] = true ;

        // Update key value and parent index of teh adjancent vertices of the picker vertex
        // Consider only those vertices that aren't yet included in the MST
        for ( int v = 0 ; v < V ; v++ )
        {
            // graph[u][v] is non-zero only for adjacent vertices of m. mstSet[v] is false for
            // vertices not yet included in MST.
            // Update the key only if graph[u][v] is smaller than key[v]
            if ( graph[u][v] && !mstSet[v] && graph[u][v] < key[v] )
                parent[v] = u , key[v] = graph[u][v] ;
        }
    }

    // Print the constructed MST
    printMST ( parent , graph ) ;
}


//? Driver code
int main () 
{ 
    /* 

    TODO: Let us create the following graph :-

        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | / \ | 
    (3)-------(4) 
            9     
    */
            
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 

    // Print the solution 
    printMST(graph); 

    return 0; 
}