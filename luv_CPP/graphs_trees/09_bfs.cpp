# include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 10 ;

vector <int> g[N] ;

vector <bool> visited(N) ;
vector <int> level(N) ;

void bfs ( int vertex )
{
    queue <int> q ;
    q.push(vertex) ;
    visited[vertex] = 1 ;

    while ( !q.empty() )
    {
        int cur_v = q.front() ;
        q.pop() ;

        cout << cur_v << " " ;

        for ( int child : g[cur_v] )
        {
            if ( !visited[child] )
            {
                q.push(child) ;
                visited[child] = 1 ;
                level[child] = level[cur_v] + 1 ;
            }
        }
    }

    cout << endl ;
}

int main ()
{
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

    for ( int i = 1 ; i <= n ; i++ )
    {
        cout << i << " : " << level[i] << endl ;
    }

    return 0 ;
}