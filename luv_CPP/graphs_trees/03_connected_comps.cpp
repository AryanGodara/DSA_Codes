// How to find Connected Components and Cycle in a Graph using DFS

# include <bits/stdc++.h>
using namespace std ;

/*
    Problem :-
    Given n, i.e., total no. of nodes in an undirected graph numbered from 1 to n and an integer e,
    i.e., total no. of edges in the graph. Calculate the total number of connected componenets in 
    the graph. A connected component is a set of vertices in a graph that are linked to each other
    by paths.

    Input Format :-
    First line of input contains two integers n and e. Next e line will contain two integers u and v
    meaning htat node u and node v are connected to each other in undirected fashion.

    Output Format : -
    For each input graph print an integer x denoting total number of connected components.

    Constraints : -
    All the input values are well within the integer range.
*/

/*
    Approach :-
    We try and run DFS from each node of the graph. If a node has already been visited previously,
    i.e., it's a part of another connected component, then the DFS will simply not run for that 
    node.
    So we increment the count by 1 for each time we are able to run DFS from a node, and for that
    run, we mark all its connected nodes as 'visited'.
    Then, we return the 'count' which is the final solution
*/

const int N = 1e5 ;

vector <bool> visited (N) ;

vector <vector<int>> grid(N) ;

vector <vector<int>> components ;
vector <int> current_comps ;

void dfs ( int vertex ) // The node that we start from
{
    // Take action on vertex after entering the vertex
    if ( visited[vertex] )
        return ;    // Already searched
    else
        visited[vertex] = true ;

    current_comps.push_back(vertex) ;   // Add this to the list of currently connected components

    for ( int child : grid[vertex] )   // Going through all the children of the current node
    {
        // Take action on child before entering the child node
        dfs(child) ;    // 
        // Take action on child after entering the child node
    }
    // Take action on vertex before exiting the vertex
}


// Driver Function
int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    // Creating a graph usnig Adjacency List
    int n , e ;     // No. of vertices , No. of edges
    cin >> n >> e ;

    for ( int i = 0 ; i < e ; i++ )
    {
        int v1 , v2 ;
        cin >> v1 >> v2 ;
        grid[v1].push_back(v2) ;
        grid[v2].push_back(v1) ;
    }

    int count = 0 ; // The no. of times we call a fresh DFS

    for ( int i = 1 ; i <= n ; i++ ) // Checking for all the nodes
    {
        if ( visited[i] )
            continue ;

        count++ ;   // First time we reached this component 'not connected w/ prev ones'

        dfs(i) ;

        // Now, we have all the connected components, push them into the 'components' vector
        components.push_back(current_comps) ;
        // Now, empty the 'current' vector, to make it available for the next component
        current_comps.clear() ;
    }

    cout << "No. of connected Components = " << components.size() << endl ;
    cout << "All the distinct connected components are :- " << endl ;
    
    for ( auto &x : components )
    {
        for ( auto &y : x )
            cout << y << " " ;
        cout << endl ;
    }

    return 0 ;
}