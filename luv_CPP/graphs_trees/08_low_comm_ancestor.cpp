# include <bits/stdc++.h>
using namespace std ;

// Find the lowest common ancestor between the two given nodes

const int N = 1e5 + 10 ;

vector<int> g[N] ;  // Vector of arrays
int par[N] ;    // par[i] stores the parent of i

void dfs ( int v , int p = -1 )
{
    par[v] = p ;    // Storing the parent of this node

    for ( int child : g[v] )
    {
        if ( child == p )
            continue ;
        dfs ( child , v ) ;
    }
}

vector <int> path ( int v )     // Returns the path of this node from the root
{
    vector <int> ans ;  // We'll store the path in this vector

    while ( v != -1 )
    {
        ans.push_back(v) ;
        v = par[v] ;    // Recursion // Kinda
    }

    reverse ( ans.begin() , ans.end() ) ;   // To start the path, from the root node.

    return ans ;
}

int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;

    int n ;
    cin >> n ;

    for ( int i = 0 ; i < n-1 ; i++ )
    {
        int x , y ;
        cin >> x >> y ;

        g[x].push_back(y) ;
        g[y].push_back(x) ;
    }

    int x , y ; // We need to find the LCA of these two nodes
    cin >> x >> y ;

    dfs(1) ;    // Calling the dfs from the root node, to initialize all the parent values

    vector <int> path_x = path(x) , path_y = path(y) ;

    // Now, we need to find the last common element in path_x and path_y

    int lca = -1 ;  // To store the ans

    for ( int i = 0 ; i < min ( path_x.size() , path_y.size() ) ; i++ )
        if ( path_x[i] == path_y[i] )
            lca = path_x[i] ;
        else
            break ;
    
    cout << lca << endl ;

    return 0 ;
}