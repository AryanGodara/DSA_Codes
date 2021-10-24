// Check if there's a cycle in the given graph
# include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 ; // Max size of the graph

vector <vector<int>> graph (N) ;

vector <bool> visited (N) ;

bool dfs ( int vertex , int parent )
{
    visited[vertex] = true ;

    bool does_loop_exist = false ;

    for ( int child : graph[vertex] )
    {
        if ( visited[child] && child==parent )
            continue ;

        if ( visited[child] )   // We've already visited this child before, and it's not the parent
            return true ;

        does_loop_exist |= dfs (child , vertex) ;
    }
    return does_loop_exist ;
}

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
        graph[v1].push_back(v2) ;
        graph[v2].push_back(v1) ;
    }

    // We have to check loops starting from each node, as there may be multiple connected 
    // components, and some of them may not form closed loops

    bool does_loop_exist = false ;
    
    for ( int i = 1 ; i <= n ; i++ )
        does_loop_exist |= dfs(i,i) ;   // We can also use 'break' once we find a loop

    cout << boolalpha << does_loop_exist << endl ;

    return 0 ;
}