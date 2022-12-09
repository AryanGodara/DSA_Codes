# include <bits/stdc++.h>
using namespace std ;

const int N = 10 ;  // No. of nodes
vector<int> g[N] ;  // An array of type vector<int> of length N
int vis[N] ;
int pathVis[N] ;    // Make sure, that the element being repeated (previously visited) lies on the same path

bool isDirectedGraphCyclic(int cur)
{
    vis[cur] = 1 ;
    pathVis[cur] = 1 ;

    bool cycle = false ;

    for ( auto &child : g[cur] )
    {
        if ( vis[child] && pathVis[child] )
            return true ;   // Cycle found
        else if ( !vis[child] )
            cycle |= isDirectedGraphCyclic(child) ; // If any of the children have a cycle, return true
    }

    pathVis[cur] = 0 ;  // Backtracking (But it still remains marked as visited)
    return cycle ;
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

    bool isCyclic = false ;
    
    for ( int i = 1 ; i <= N ; i++ )
    {
        if ( !vis[i] )
            isCyclic |= isDirectedGraphCyclic(i) ;
        if ( isCyclic )
            break ;
    }

    cout << boolalpha << isCyclic << endl ;

    return 0 ;
}