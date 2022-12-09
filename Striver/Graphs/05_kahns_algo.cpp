// Topological sorting using a modified DFS algorithm

/*
Indegree = no. of edges coming into a node, is called the indegree of that node.
*/

// 1. Insert of indegree 0
// 2. Take them out of the queue, remove all their outward edges. This reduces the indegree of their adjacent nodes
// 3. Now, with a fresh set of indegrees, repeat steps 1 and 2, until you've gone through all the nodes

# include <bits/stdc++.h>
using namespace std ;

const int N = 6 ;  // No. of nodes

vector<int> g[N] ;  // An array of type vector<int> of length N
int vis[N] ;

vector <int> topoSort ()
{
    vector <int> ret ;
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

        ret.push_back(cur) ;

        // cur is in your topo sort, so please remove it from the indegree
        for ( auto &child : g[cur] )
        {
            indegree[child]-- ;
            if ( indegree[child] == 0 )
                q.push(child) ;
        }
    }

    return ret ;
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

    for ( auto &x : topoSort() )
        cout << x << endl ;

    return 0 ;
}