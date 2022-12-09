# include <bits/stdc++.h>
using namespace std ;

// Detect cycle in undirected graph
/*
    1. BFS Method :- Start at some place, and keep  going down level by level. If something is already visited,
                     it means that there is a cycle.
    2. DFS Method :- Normal DFS, but keep parent node in parameter, if child != par && child==vis, cycle found.
*/
const int N = 10;
vector<int> g[N];
bool vis[N] = {0} ;

bool dfs (int node , int parent)
{
    vis[node] = true ;

    for ( auto &child: g[node] )
    {
        if (!vis[child] && dfs(child,node))
            return true ;
        else if (child != parent)
            return true ;
    }

    return false ;
}

int main()
{
    int n ;
    cin >> n ;

    for ( int i = 0 ; i < n ; i++ )
    {
        int x , y ;
        cin >> x >> y ;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bool cycle = false ;
    for ( int i = 1 ; i <= N ; i++ )
    {
        if (!vis[i])
        {
            cycle |= dfs(i,-1);
        }
        if (cycle)
            break ;
    }

    cout << boolalpha << cycle << endl ;
}