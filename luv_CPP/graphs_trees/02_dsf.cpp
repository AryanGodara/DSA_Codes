# include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 10 ;

vector <int> g[N] ; // Adjacency List

bool visited[N] = {0} ;   // Stored the visited vertices/nodes. (All initialized to false)

void dfs ( int vertex ) // The node that we start from
{
    // Take action on vertex after entering the vertex
    if ( visited[vertex] )
        return ;    // Already searched
    else
        visited[vertex] = true ;

    cout << vertex << endl ;

    for ( int child : g[vertex] )   // Going through all the children of the current node
    {
        cout << "Par " << vertex << " , child = " << child << endl ;
        // Take action on child before entering the child node
        dfs(child) ;    // 
        // Take action on child after entering the child node
    }
    // Take action on vertex before exiting the vertex
}

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    
    int n , m ; // n = no. of vertices , m = no. of edges (queries)

    cin >> n >> m ;

    for ( int i = 0 ; i < m ; i++ )
    {
        int v1 , v2 ;
        cin >> v1 >> v2 ;
        g[v1].push_back(v2) ;   // Undirected Graph
        g[v2].push_back(v1) ;
    }

    // for ( auto &x : g )
    // {
    //     for ( auto &y : x )
    //         cout << y << " " ;
    //     cout << endl ;
    // }

    // cout << endl << endl ;

    dfs(1) ;

    return 0 ;
}