# include <bits/stdc++.h>
using namespace std ;

/*
Given Q queries , Q <= 1e5
In each query given V, Print subtree sum of V, Number of even numbers in subtree of V.
*/

const int N = 1e5 ;
vector <vector<int>> g(N) ;

vector <int> subtree_sum (N,0) , event_count(N,0) ;

void dfs ( int vertex , int parent = 0 )
{
    subtree_sum[vertex] = vertex ;  // Subtree sum, also includes the current element

    if ( !(vertex & 1) )
        event_count[vertex] = 1 ;

    for ( int child : g[vertex] )
    {
        if ( child == parent )
            continue ;
        dfs ( child , vertex ) ;

        subtree_sum[vertex] += subtree_sum[child] ;
        event_count[vertex] += event_count[child] ;
    }
}

int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n ;
    cin >> n ;

    for ( int i = 0 ; i < n-1 ; i++ )
    {
        int x , y ;
        cin >> x >> y ;
        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }

    dfs (1) ;   // Pre-computation

    int q ;
    cin >> q ;

    while ( q-- )
    {
        int v ;
        cin >> v ;

        cout << subtree_sum[v] << " " << event_count[v] << endl ;
    }

    return 0 ;
}