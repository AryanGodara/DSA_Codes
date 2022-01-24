//? Shortest Path in Directed Acyclic Graph

/*
    Shortest_path(adj,source/s)
        1. Initialize dist[V] = {inf,intf,...,inf}
        2. dist[s] = 0
        3. Find a topological sort of the graph
        4. For every vertex u in the topological sort
            a. For every adjacent 'v' of 'u'
                if ( dist[v] > dist[u] + weight(u,v) ) : dist[v] = dist[u] + weight(u,v);
*/

# include <bits/stdc++.h>
using namespace std;

# define INF 1e9

class AdjListNode{
    int v , wt ;

    public:
        AdjListNode ( int v , int wt )  // Constructor
        {
            this->v = v ;
            this->wt = wt ;
        }
        
        int getV () { return this->v ; }

        int getWt () { return this->wt ; }
};

class Graph{
    int V;
    list<AdjListNode> *adj ;    // list to store 'adj_list_node' elements, named 'adj'

    void topological_sort_util ( int v , bool visited[] , stack<int> &st );

    public:
        Graph ( int V); // Constructor

        void add_edge ( int u , int v , int wt );   // Add edge from u to v, of weight w
        void shortest_path(int s);  // Print the shortest distance of each node from node 's'
};

Graph::Graph(int V)
{
    this->V = V ;
    adj = new list<AdjListNode> [V] ;
}

void Graph::add_edge( int u , int v , int wt )
{
    AdjListNode node(v,wt);     // Create an isntance of class adjlistnode
    adj[u].push_back(node);     // connect this node to u
}

void Graph::topological_sort_util( int v , bool visited[] , stack <int> &st )
{
    visited[v] = true ;

    for ( auto i = adj[v].begin() ; i != adj[v].end() ; i++ )
    {
        AdjListNode node = *i;  // Value stored at iterator i if of type 'instance of addlistnode'
        if ( !visited[node.getV()] )
            topological_sort_util(node.getV(),visited,st);
    }

    st.push(v) ;
}

void Graph::shortest_path(int s)
{
    stack <int> st ;

    int dist[V] ;
    for ( int i = 0 ; i < V ; i++ )
        dist[i] = INF ;
    dist[s] = 0 ;

    bool *visited = new bool[V] ;
    for ( int i = 0 ; i < V ; i++ )
        visited[i] = false ;
    
    for ( int i = 0 ; i < V ; i++ )
        if ( visited[i] == false )
            topological_sort_util(i,visited,st) ;

    while ( !st.empty() )
    {
        int u = st.top() ;
        st.pop() ;

        if ( dist[u] != INF )   // Acyclic graph, so we only reach each node one way
            for ( auto i = adj[u].begin() ; i != adj[u].end() ; i++ )
                if ( dist[i->getV()] > dist[u] + i->getWt() )
                    dist[i->getV()] = dist[u] + i->getWt() ;
    }

    for ( int i = 0 ; i < V ; i++ )
        ( dist[i]==INF ? (cout << "INF") : (cout << dist[i]) ) << " " ;
}


int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Graph g(6) ;
    g.add_edge(0,1,2);
    g.add_edge(0,4,1);
    g.add_edge(1,2,3);
    g.add_edge(4,2,2);
    g.add_edge(4,5,4);
    g.add_edge(2,3,6);
    g.add_edge(5,3,1);
    
    int s = 0 ;
    cout << "Following are the shortest distances from source " << s << ": " << endl ;
    g.shortest_path(s) ;        // OP: 0 3 4 6 1 5

    return 0 ;
}