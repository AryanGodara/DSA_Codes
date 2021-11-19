// Find the shortest path bewteen two nodes using BFS

# include <bits/stdc++.h>
using namespace std ;


/*
    Q. You are given the starting and ending positions on a chess board, for a knight(horse).
       Find the minimum no. of moves required to reach the ending position for each test case.
*/


const int N = 1e5 + 10 ;    // Max size of the graph


vector <int> g[N] ; // A graph, with max length of each array, set as N

vector <vector<bool>> visited ( 8 , vector <bool> (8) ) ; // Checks whether node was visited
vector <vector<int>> level ( 8 , vector <int> (8) ) ;   // Stores level of the node

vector <pair<int,int>> movement = {
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,-1},{2,1},
    {-2,-1},{-2,1}
};                      // The 8 directions in which a knight can move

bool is_valid ( int x , int y ) // Check if the current block is a valid block on chessboard
{
    return x>=0&&y>=0&&x<8&&y<8 ;
}

void reset ()   // Resets the global matrices
{
    for ( int i = 0 ; i < 8 ; i++ )
        for ( int j = 0 ; j < 8 ; j++ )
            visited[i][j] = level[i][j] = 0 ;
}

// The main Utility Function
int bfs ( string &source , string &dest )
{
    int x1 = source[0]-'a' , x2 = dest[0]-'a' , y1 = source[1]-'1' , y2 = dest[1]-'1' ;

    if ( x1==x2 && y1==y2 ) // Source = Destination
        return 0 ;

    reset() ;   // To reset the global visited and level arrays, back to zero

    queue <pair<int,int>> q ;
   
    q.push({x1,y1}) ;
    visited[x1][y1] = true ;

    while ( !q.empty() )
    {
        pair <int,int> v = q.front() ;
        q.pop() ;           // Extract the first element of the queue
        int x = v.first , y = v.second ;

        for ( auto &child : movement )
        {
            int child_x = child.first + x , child_y = child.second + y ;

            if ( is_valid(child_x,child_y) && !visited[child_x][child_y] ) 
            {
                q.push({child_x,child_y}) ;
                level[child_x][child_y] = level[x][y] + 1 ;
                visited[child_x][child_y] = true; 

                if ( level[x2][y2] != 0 ) // We found the destination
                    break ;
            }
        }
    }

    // Return the level of the destination wrt the source
    return level[x2][y2] ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int T ;
    cin >> T ;

    while ( T-- )
    {
        string a , b ;
        cin >> a >> b ;

        cout << bfs(a,b) << endl ;
    }

    return 0 ;
}