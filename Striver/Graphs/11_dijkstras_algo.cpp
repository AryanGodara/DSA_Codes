// Shortest path for weighted graph. Priority queue, or set in STL.
// Remember, shorter paths go to the front, longer ones go to the back

# include <bits/stdc++.h>
using namespace std ;

//? Node -> {node-connected-to , weight of the edge}

/*
* 0 -> {1,4} , {2,4}
* 1 -> {0,4} , {2,2}
* 2 -> {0,4} , {1,2} , {3,3} , {4,1} , {5,6}
* 3 -> {2,1} , {5,3}
* 4 -> {2,1} , {5,3}
* 5 -> {2,6} , {3,2} , {4,3}
*/

vector <vector<pair<int,int>>> edges = {
    {{1,4} , {2,4}} ,
    {{0,4} , {2,2}} ,
    {{0,4} , {1,2} , {3,3} , {4,1} , {5,6}} ,
    {{2,1} , {5,3}} ,
    {{2,1} , {5,3}} ,
    {{2,6} , {3,2} , {4,3}}
} ;

const int N = 6 ;
vector<pair<int,int>> g[N] ;    // weight , node-number
int vis[N] ;
int dist[N] ;   // dist of node 'i' from the starting node (which can be 0, or any specific node


class Point
{
   int x;
   int y;
public:
   Point(int x, int y)
   {
      this->x = x;
      this->y = y;
   }
   int getX() const { return x; }
   int getY() const { return y; }
};
 
// To compare two points
class myComparator
{
public:
    int operator() (const Point& p1, const Point& p2)
    {
        if ( p1.getX() != p2.getX() )
            return p1.getX() < p2.getX();
        return p1.getY() <= p2.getY();
    }
};


void dijkstra (int src)
{
    // set <pair<int,int>> s ;     // Pair<dist,node>
    priority_queue<Point , vector<Point>,myComparator> pq ;   // Min heap
    
    for ( int i = 0 ; i < N ; i++ )
        dist[i] = INT_MAX ;
    dist[src] = 0 ;

    // s.insert({0,src}) ;
    pq.push(Point(0,src)) ;

    while ( !pq.empty() )
    {
        Point pcur = pq.top() ;
        int dst = pcur.getX() ;
        int cur = pcur.getY() ;
        pq.pop() ;  // Removes the first element, ie, the top element.

        for ( auto &edge : g[cur] )
        {
            int wt = edge.first ;
            int child = edge.second ;

            if ( dst + wt < dist[child] )  // We can reduce this child nodes distance
            {
                dist[child] = wt + dst ;
                pq.push(Point(dist[child],child)) ;
            }
        }
    }
}

int main()
{
    for ( int i = 0 ; i < N ; i++ )
        for ( auto &pair : edges[i] )
            g[i].push_back({pair.first , pair.second}) ;

    dijkstra(0) ;

    for ( int i = 0 ; i < N ; i++ )
        cout << i << " : " << dist[i] << endl ;
}