# include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 10 ;

vector <int> g[N] ; // Vector of arrays of size upto N ;

vector<bool> visited(N) ;   // Stores the visited nodes
vector<int> level(N) ;      // Stores the level of each node

// The primary function
void bfs ( int source )
{
    queue <int> q ;
    q.push(source) ;

    visited[source] = 1 ;

    while ( !q.empty() )
    {
        int cur_vertex = q.front() ;
        q.pop() ;

        cout << cur_vertex << " " ;

        for ( int child : g[cur_vertex] )
        {
            if ( !visited[child] )
            {
                q.push(child) ;
                visited[child] = true ;
                level[child] = level[cur_vertex] + 1 ;
            }
        }
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

    bfs(1) ;
    cout << endl ;

    for ( int i = 1 ; i <= n ; i++ ) 
        cout << i << " : " <<level[i] << endl ;
    cout << endl ;

    return 0 ;
}