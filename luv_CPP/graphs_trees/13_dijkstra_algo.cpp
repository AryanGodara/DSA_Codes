# include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 10 ;
const int INF = 1e9+10 ;


// Weighted graph, stored by arrays of vector
vector < pair<int,int> > g[N] ;


void dijkstra ( int source , int n )    // 'source' is the root node
{
    // Vector, to check whether the given vertex has already been visited
    vector <int> vis (N,false) ;
    // Array, to store the 'min' distance of each vertex, from the root
    vector <int> dist(N,INF) ;

    // Now, we use the priority_queue, so that finding the minimum element becomes an
    // O(logN) operation, instead of the normal O(N), if we used a list (vector,array,etc)
    
    // Also, since the function of min_heap(priority_queue) here, can be perfomed by multiset,
    // we'll use that instead, because of its more user friendly syntax

    multiset <pair<int,int>> st ;   // Pair: first = weight , second = node (opp of the graph)
    // This is because, we want the elements to be in the ascending order of their weights inside
    // the set, and so, we make set pair.first, to avoid writing a custom cmp function

    st.insert({0,source}) ; // Source is at distance and wt '0' from itself lol
    dist[source] = 0 ;

    while ( !st.empty() )
    {
        // Find the minimum element (least weight), and then traverse through its children nodes
        // in the directed graph, and see if we can minimise the distance for any of them

        auto node = *st.begin() ;   // node is a pair here So :-
        int v = node.second ;   // pair.first is weight, ans pair.second is node

        st.erase(st.begin()) ;  // Remove this element from the set

        if ( vis[v] )    // Mark this element as visited
            continue ;

        vis[v] = true ;

        for ( auto &child : g[v] )  // Go through all of its child nodes
        {
            int child_v = child.first ; // child_v is the child node
            int wt = child.second ; // wt of path from node v to its child node (child_v)

            // We'll check if the new distance of child (wt + dist) is lower than the previous
            // value of distance of child, then we'll update the value.
            if ( dist[v] + wt < dist[child_v] )
            {
                // We update the distance and put insert this child node into the min heap
                dist[child_v] = dist[v] + wt ;
                st.insert({dist[child_v],child_v}) ;
            }
        }
    }

    // Print the distance for each node now
    for ( int i = 1 ; i <= n ; i++ )
        cout << i << " : " << dist[i] << endl ;
}


// Driver Function
int main ()
{
    int n , m ; // n vertices, m edges
    cin >> n >> m ;

    for ( int i = 0 ; i < m ; i++ ) // Taking the input of the edges
    {
        int x , y , wt ;
        cin >> x >> y >> wt ;

        g[x].push_back({y,wt}) ;    
        // x is connected 'directed edge' with y, and the weight of the edge is 'wt'

        // If the graph was unweighted, we'd also add the line :-
        // g[y].push_back({x,wt}) ; // A directed edge in the opposite direction.
    }

    dijkstra(1,n) ;

    return 0 ;
}