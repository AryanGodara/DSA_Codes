// 0-1 bfs : The weight of each path is either 0 or 1

# include <bits/stdc++.h>
using namespace std ;

/*
    Q. Given a number n (No. of Nodes from 1 to n), and m ( m directed edges), which together
    represent a directed graph. Followed by m pairs of numbers, representing directed bonds.
    Find the minimum no. of bonds that must be flipped (Change directinality) to reach from
    Node 'a' to Node 'b'.
    For this example, tak : a = 1 , b = N
*/

const int N = 1e5 + 5 ; // Max possible value of N, and e <= N-1 (directed graph)
const int INF = 1e9+10 ;

vector <pair<int,int>> g[N] ;   // Graph to store the pair <attached_node_name,weight_of_edge>

vector <int> level (N,INF) ;    // Distance from the root node

// The main utility function
int zero_one_bfs ( int vertex , int target )
{
    deque <int> q ;

    q.push_back(vertex) ;
    level[vertex] = 0 ;

    while ( !q.empty() )
    {
        int cur_v = q.front() ;
        q.pop_front() ;

        for ( auto &child : g[cur_v] )
        {
            int child_v = child.first , wt = child.second ;
            
            // If new path to child_v is shorter than the previous path, or we're visiting
            // child_v for the first time
            if ( level[cur_v] + wt < level[child_v] )  // Check works as visited array
            {
                level[child_v] = level[cur_v] + wt ;  // If wt == 0, then no change in level
                // Then, push this node into the queue
                if ( !wt )   // No need to reverse the direction of this edge
                    q.push_front(child_v) ;
                else
                    q.push_back(child_v) ;  // Add level by 1, in order to flip the reversed
            }
        }
    }

    return ( (level[target] == INF) ? -1 : level[target] ) ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;

    int n , e ;
    cin >> n >> e ;

    while ( e-- )
    {
        int x , y ;
        cin >> x >> y ;

        if ( x == y )   // There can be self loops, so ignore them
            continue ;

        g[x].push_back({y,0}) ; // Let the weight of directed edge be zero
        g[y].push_back({x,1}) ; // Let the weight of the edge in opp direction be 1.
        // Now, we have a cost of 1, for flipping the direction
    }

    cout << zero_one_bfs(1,n) << endl ;

    return 0 ;
}