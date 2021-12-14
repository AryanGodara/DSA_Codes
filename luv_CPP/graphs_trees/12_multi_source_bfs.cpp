# include <bits/stdc++.h>
using namespace std ;

/*
Q. After a long duration fo the painful, torturous and tumultous periods of capitalism in 
Snakelalnd, now the snakes have decided to adopt capitalism. The houses in Snakeland are
arranged in a rectangular fashion of dimension n*m. The wealth of the snake in the house at
cell (i,j) is given by a[i][j] rupees.

At the end of each hour, the wealth of a snake will grow and will become equal to the
highest wealth that its neighbour had (at the start of the hour). Note that this increase in
health will happen simultaneously for each snake. Two houses are said to be neighbours is
they share a side or corner with each other.
Find out the minimum number of hours required for this transition.

INPUT:-
The first liine of the input contains an integer T, denoting the number of test cases.
The description of T test cases follows.

The first line of each test case contains two space separated integers: n,m.

Each of the next n lines contain m space separated integers. 

OUTPUT:-
For each test case output a single integer consisting of the minimum number of hours
required for the transition
*/

const int N = 500 ;
const int inf = 1e7 + 10 ;

int val[N][N] ;
int vis[N][N] ;
int lev[N][N] ;
int n , m ;

void reset ()
{
    for ( int i = 0 ; i < n ; i++ )
        for ( int j = 0 ; j < m ; j++ )
        {
            vis[i][j] = 0 , lev[i][j] = inf ;
        }
}

vector < pair<int,int> > movements = { {0,1} , {0,-1} , {1,0} , {-1,0} ,
    {1,1} , {-1,-1} , {-1,1} , {1,-1}
} ;

bool isValid ( int i , int j )
{
    return ( i>=0 && j>=0 && i<n && j<m && vis[i][j]==0 ) ;
}

int bfs ()      // Returns the minimum no. of hours
{
    // Find the max value, and all of its coordinates
    int mx = 0 ;
    for ( int i = 0 ; i < n ; i++ )
        for ( int j = 0 ; j < m ; j++ )
            mx = max ( mx , val[i][j] ) ;

    queue<pair<int,int>> q ;

    for ( int i = 0 ; i < n ; i++ )
        for ( int j = 0 ; j < m ; j++ )
            if ( val[i][j] == mx )
            {
                q.push({i,j}) ;
                lev[i][j] = 0 ;
                vis[i][j] = 1 ;
            }

    int ans = 0 ;   // Return this

    while ( !q.empty() )
    {
        auto v = q.front() ;
        int vx = v.first , vy = v.second ;
        q.pop() ;

        for ( auto &movement : movements )
        {
            int child_x = movement.first + vx ;
            int child_y = movement.second + vy ;

            if ( !isValid(child_x,child_y) )
                continue ;

            q.push({child_x,child_y}) ;
            lev[child_x][child_y] = lev[vx][vy]+1 ;
            vis[child_x][child_y] = 1 ;

            ans = max ( ans , lev[child_x][child_y] ) ;
        }
    }
    
    return ans ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int T ;
    cin >> T ;

    while ( T-- )
    {
        cin >> n >> m ;
        
        reset() ;

        for ( int i = 0 ; i < m ; i++ )
            for ( int j = 0 ; j < n ; j++ )
                cin >> val[i][j] ;

        cout << bfs() << endl ;
    }
}