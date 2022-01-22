//? Topological Sorting (Kahn's BFS Based Algorithm)

# include <bits/stdc++.h>
using namespace std ;

/*
    BFS Solution :-
    1. Store indegreee of every vertex.
    2. Create a queue, q
    3. Add all 0 indgree vertices to the queue
    4. While q is not empty
        a. u = q.pop()
        b. Print u
        c. For every adjacent v of u
            (i) Reduce indegree of v by 1
            (ii) if indegree of v becomes 0, add v to the q
*/

void topological_sort ( vector <int> adj[] , int V )
{
    vector <int> in_degree(V,0) ;

    for ( int u = 0 ; u < V ; u++ )
        for ( int x: adj[u] )
            in_degree[x]++ ; // Everytime x is a 'child' of some vertex 'u', increment its degree by 1
    
    queue <int> q ;
    for ( int i = 0 ; i < V ; i++ )
        if ( in_degree[i] == 0 )
            q.push(i) ; // Push all the vertices, who have '0' dependences 'indedgree[i]==0'
    
    while ( !q.empty() )
    {
        int u = q.front () ;
        q.pop () ;
        cout << u << " " ;      // Print the current vertex

        for ( int x: adj[u] )   // Each of its child, has now completed '1' of their dependency
            if ( --in_degree[x] == 0 )  // So now if they have 0 dependencies, we can 'run' them
                q.push(x) ;     // So, we push them into the queue for printing
    }
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

    add_edge(adj,0,2) ;
    add_edge(adj,0,3) ;
    add_edge(adj,1,3) ;
    add_edge(adj,1,4) ;
    add_edge(adj,2,3) ;

    cout << "Following is a Topological Sort of the Graph: \n" ;
    topological_sort(adj,V) ;

    return 0 ;
}