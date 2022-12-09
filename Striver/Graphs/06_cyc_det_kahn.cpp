// Detect a cycle in a directed graph, using topological sort BFS -> Kahn's algorithm

# include <bits/stdc++.h>
using namespace std ;

const int N = 6 ;  // No. of nodes

vector<int> g[N] ;  // An array of type vector<int> of length N
int vis[N] ;

// If the toposort array, contains less than N elements, only then we can say that it's an acyclic graph.
// Otherwise, the cycle will cause an issue, and we'll not be able to get a complete topoSort array

bool isCyclic ()
{
    int topoSortSize = 0 ;

    int indegree[N] = {0};

    for ( int i = 0 ; i < N ; i++ )
        for ( auto &child : g[i] )
            indegree[child]++ ;
    
    queue <int> q ;

    for ( int i = 0 ; i < N ; i++ )
        if ( indegree[i] == 0 )
            q.push(i) ;


    while ( !q.empty() )
    {
        int cur = q.front() ;
        q.pop() ;

        topoSortSize++ ;

        // cur is in your topo sort, so please remove it from the indegree
        for ( auto &child : g[cur] )
        {
            indegree[child]-- ;
            if ( indegree[child] == 0 )
                q.push(child) ;
        }
    }

    return topoSortSize < N ;
}

int main()
{
    int n ; // No. of directed edges
    cin >> n ;

    for ( int i = 0 ; i < n ; i++ )
    {
        int x , y ;
        cin >> x >> y ;
        g[x].push_back(y) ;
    }

    cout << boolalpha << isCyclic() << endl ;

    return 0 ;
}