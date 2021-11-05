# include <bits/stdc++.h>
using namespace std ;

// Max value of no. of edges between any to vertices is called the diameter of the tree.

/*
Steps :-                        Time Complexity = O(N) ;
1. With any root find max depth node
    // This is one end of a tree in the diameter of the tree (Check proof online)
2. Use this max depth node as the new node, and use it as the new root, and find the max
   depth. So, this new value of depth = value of the diameter of the tree.
*/

const int N = 1e5 + 10 ;

vector<int> g[N] ;  // A vector of 'arrays of size N'
int depth[N] ;

void dfs ( int v , int parent = -1 )
{
    for ( int child : g[v] )
    {
        if ( child == parent )
            continue ;
        
        depth[child] = depth[v] + 1 ;   // Depth of root note = 0, and then increases 

        dfs(child,v) ;
    }
}

// Driver Function
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

    dfs(1) ;

    int mx_depth = -1 , mx_depth_node ;

    for ( int i = 1 ; i <= n ; i++ )
        if ( mx_depth < depth[i] )
            mx_depth = depth[i] , mx_depth_node = i , depth[i] = 0 ;
            // depth[i] = 0, resets the depth array, for the second dfs run
    
    dfs(mx_depth_node) ;

    // Now, the max_depth that we find is the answer
    for ( int i = 1 ; i <= n ; i++ )
        if ( mx_depth < depth[i] )
            mx_depth = depth[i] ;   
            // No need to reset mxdepth to 0, as we have to find the max value anyway
    
    cout << mx_depth << endl ;

    return 0 ;
}