//? This problem is based on the detection of cycle in an directed graph using Kahn's Algorithm
//* We take advantage of the fact that Kahn's algorithm works only for 'acyclic graphs', and
//* it fails for 'cyclic graphs'. So, if it fails, we know that the graph is 'cyclic'.

# include <bits/stdc++.h>
using namespace std ;

/*
    1. Store indegree of every vertex
    2. Create a queue, q
    3. Add all 0 indegree vertices to the q
    4. count = 0
    5. while q is not empty
        a. u = q.pop
        b. For every adjacent v of u
            (i) Reduce indegree of v by 1
            (ii) If indegree of v becomes 0, push v to the queue
        c. count++ ;
    6. Return count != v    // If count == V , there's no cycle, if count != v, there's a cycle
*/

bool topological_sort ( vector <int> adj[] , int V )
{
    int count = 0 ;
    vector <int> indegree(V,0) ;

    for ( int i = 0 ; i < V ; i++ )
        for ( int &x: adj[i] )
            indegree[x]++ ;
        
    queue <int> q ;
    for ( int i = 0 ; i < V ; i++ )
        if ( !indegree[i] )
            q.push(i) ;
    
    while ( !q.empty() )
    {
        int u = q.front () ;
        q.pop () ;
        count++ ;
    
        for ( int &child : adj[u] )
            if ( --indegree[child] == 0 )
                q.push(child) ;
    }

    return count != V ;
}

void add_edge ( vector <int> adj[] , int u , int v )
{
    adj[u].push_back(v) ;
}


int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int V = 5 ;

    vector <int> adj[V] ;

    add_edge(adj,0,1) ;
    add_edge(adj,4,1) ;
    add_edge(adj,1,2) ;
    add_edge(adj,2,3) ;
    add_edge(adj,3,1) ;

    cout << ( topological_sort(adj,V) ? "Cycle Found" : "No Cycle Found" ) << endl ;

    return 0 ;
}