// Only applicable for directed acyclic graphs (Doesn't really make sense otherwise :p)
# include <bits/stdc++.h>
using namespace std ;

/*
Linear ordering of verticies such that if there is an edge between u and v, u appears before v in their ordering.
*/

const int N = 6 ;  // No. of nodes

vector<int> g[N] ;  // An array of type vector<int> of length N
int vis[N] ;

stack<int> s ;

void dfs ( int cur )
{
    vis[cur] = 1 ;

    for ( auto &child : g[cur] )
    {
        if (!vis[child])
            dfs(child);
    }

    s.push(cur) ;
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

    for ( int i = 0 ; i < N ; i++ )
        if ( !vis[i] )
            dfs(i) ;

    while (!s.empty())
    {
        cout << s.top() << " " ;
        s.pop() ;
    }

    return 0 ;
}
