//? This Problem discusses the Topological Sorting using a DFS Based Algorithm

# include <bits/stdc++.h>
using namespace std ;

/*
    1. Create an empty stack, st
    2. For every vertex u, do the following :
        if ( u is not visited )
            DFS(u,st)
    3. while ( st is not empty )
        pop an item from st and print it

    DFS(u,st)
        1. Mark u as visited
        2. For every adjancent v of u
            if v is not visited
                DFS(v,st)
        3. Push u to st
*/

//TODO: Brief- A vertex goes into the stack, only after each of its dependencies has been pushed.

void add_edge ( vector<int> adj[] , int u , int v )
{
    adj[u].push_back(v) ;
}

void DFS(vector<int> adj[] , int u , vector<bool> &visited , stack <int> &st )
{
    visited[u] = true ;

    // Take care of all of its dependencies first (recursion)
    for ( auto &child: adj[u] )
        if ( !visited[child] )
            DFS(adj,child,visited,st) ;
    
    st.push(u);
}

void topological_sort ( vector<int> adj[] , int V )
{
    vector <bool> visited(V,false) ;
    stack <int> st ;

    for ( int i = 0 ; i < V ; i++ )
        if ( !visited[i] )
            DFS(adj,i,visited,st);
    
    while ( !st.empty() )
    {
        cout << st.top() << " " ;
        st.pop() ;
    }
}

int main () 
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL);
    cout.tie(NULL);

    int V = 5 ;
    vector <int> adj[V] ;
    add_edge(adj,0,1);
    add_edge(adj,1,3);
    add_edge(adj,2,3);
    add_edge(adj,3,4);
    add_edge(adj,2,4);

    topological_sort(adj,V);

    return 0 ;
}