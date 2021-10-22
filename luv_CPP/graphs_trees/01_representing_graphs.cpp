/*
    Adjacency Matrix        Adjacency List
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    In Adjacency Matrix Method, we count the total no. of nodes, say 'n'. And then we create an n*n
    matrix.
    If i and j are connected to each other (undirected graph), then mat[i][j] = 1 = mat[j][i].
    In case, the edges are weighted, then mat[i][j] = WEIGHTij = mat[j][i]

    Benefits :-
    Searching takes O(1) time
    Disadvantages :-
    Very high space complexity, can't use when n is in the range of 10^5
*/

/*
const int N = 1e3 ; // Max no. of edges in the graph
int graph[N][N] ;   // Automatically initialized to 0

int main ()
{
    int n , m ;     // n = no. of vertices , and m = no. of edges(joining two vertices)
    cin >> n >> m ;

    int graph[n+1][n+1] ;

    for ( int i = 0 ; i < m ; i++ )
    {
        int v1 , v2 ;
        cin >> v1 >> v2 ;
        graph[v1][v2] = graph[v2][v1] = 0 ;
    }
}
*/

/*
    In the Adjacency List method, we store a list. No. of lists = no. of vertices.
    List[0] for 1 , list[1] for 2 , list[2] for 3 // 0 indexing
    Then in each list, we store the neighbours of its respective element

    In this method, the space complexity is O(n+m), compared to the O(n^2) in the previous method

    Advantages :-
    Space complexity is much better than matrix representation
    Disadvantages :-
    Searching takes O(logn) time, if sorted, else it takes O(n) time
*/

int main ()
{
    int n , m ;
    cin >> n >> m ;

    vector <  vector< pair<int,int> > > lists(n+1) ;

    for ( int i = 0 ; i < m ; i++ )
    {
        int v1 , v2 , wt ;
        cin >> v1 >> v2 >> wt ;

        lists[v1].push_back({v2,wt}) ;  // Connected to v2 with weight wt
        lists[v2].push_back({v1,wt}) ;  // Connected to v1 with weight wt
    }

    return 0 ;
}