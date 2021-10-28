// Using DFS in a Tree, to Find the Height of the Tree

# include <bits/stdc++.h>
using namespace std ;

const int N = 1e5+1 ;   // Max no. of elements in a tree.

vector <bool> visited (N) ;

vector <vector<int>> tree (N) ;

vector <int> height (N) , depth(N) ;
// Depth = Distance from root node, Height = Distance from respective root node


// The following code for dfs, will also work for trees. But since trees are much more 
// simpler data structures, compared to graphs, as they don't have any possibilities of loops,
// and generally go in one direction only. 
// So, we don't actually need the 'visited array', and we can further optimize dfs function.
void dfs_vanilla ( int vertex )
{
    // Take action on vertex after entering the vertex

    visited[vertex] = true ;

    for ( int child : tree[vertex] )
    {
        // Take action on child before entering the child node

        if( visited[child] )
            continue ;  // Or break, cuz in tree, vis[child] is only true for leaf nodes
        
        dfs_vanilla ( child ) ; // If we haven't visited this child yet

        // Take action on child after exiting child node
    }

    // Take action on vertex before exiting the vertex
}


// New dfs for Trees
void dfs ( int vertex , int parent = 0 )    // A default value for the parent
{


    for ( int child : tree[vertex] )
    {
        if ( child == parent )
            continue ;

        depth[child] = depth[vertex] + 1 ;  // Depth increases as we go down    

        dfs ( child , vertex ) ;    // Parent is the immediate parent node

        height[vertex] = max ( height[vertex] , height[child] + 1 ) ; 
        // Height is 1 + max height of all the immediate children
    }

}

int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n , e ;     // n : Nodes are from 1 to n ; e : Number of specified nodes (bidirectional)
    cin >> n >> e;  
    // For trees , e = no. of edges = n-1 = no. of components-1

    for ( int i = 0 ; i < e ; i++ )
    {
        int x , y ;
        cin >> x >> y ;

        tree[x].push_back(y) ;
        tree[y].push_back(x) ;
    }

    dfs (1) ;   // Parent is automatically passed as '0'.

    for ( int i = 1 ; i <= n ; i++ )
        cout << i << " :- Ht : " << height[i] << " , Dt : " << depth[i] << endl ;

    return 0 ;
}