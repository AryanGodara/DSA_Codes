# include <bits/stdc++.h>
using namespace std ;

// The Floyd Warshall Algorithm is for solving all pair shortest path problems. The problem is to find the
// shortest distance between every pair of vertices in a given edge-weighted directed graph.
//! The graph should be directed (same as bellman ford)

//* This is a DP algorithm :)

/*
1. Initialize the solution matrix same as the input graph matrix as a first step.
2. Then update the solution matrix by considering all vertices an intermediate vertex.
3. The idea is to one be one pick all vertices are updates all shortest paths which 
   include the picked vertex as an intermediate vertex in the shortest path.
4. When we pick vertex number k as an intermediate vertex, we already have considered
   vertices {0,1,2,...,k-1} as intermediate vertices.
5. For every pair (i,j) of the source and destination vertices respectively, there
   are two possible cases
   a. k is not an intermediate vertex in shortest path from i to j.
      We keep the the value of dist[i][j] as it is.
   b. k is an intermediate vertex in shortest path from i to j.
      We update the value of dist[i][j] as dist[i][k]+dist[k][j], if
      dist[i][j] > dist[i][k] + dist[k][j]
*/

//? Time Complexity : O(V^3) , Space Complexity : O(V^2)

# define V 4
# define INF INT_MAX

// A function to print the solution matrix
void printSolution(int dist[][V]);

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshal(int dist[][V])
{
    int i , j , k ;
    /* Add all vertices one by one to
    the set of intermediate vertices.
    ---> Before start of an iteration,
    we have shortest distances between all
    pairs of vertices such that the
    shortest distances consider only the
    vertices in set {0, 1, 2, .. k-1} as
    intermediate vertices.
    ----> After the end of an iteration,
    vertex no. k is added to the set of
    intermediate vertices and the set becomes {0, 1, 2, ..
    k} */
    for ( k = 0 ; k < V ; k++ )
        // Pick all vertices as source one by one
        for ( i = 0 ; i < V ; i++ )
            // Pick all vertices as destination then
            for ( j = 0 ; j < V ; j++ )
                if ( dist[i][j] > dist[i][k]+dist[k][j] && dist[i][k]!=INF && dist[k][j] != INF )
                    dist[i][j] = dist[i][k] + dist[k][j] ;
    
    printSolution(dist);
}

/* A utility function to print solution */
void printSolution(int dist[][V])
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}
 
// Driver's code
int main()
{
    /* Let us create the following weighted graph
            10
    (0)------->(3)
        |     /|\
    5 |     |
        |     | 1
    \|/     |
    (1)------->(2)
            3     */
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
 
    // Function call
    floydWarshal(graph);
    return 0;
}