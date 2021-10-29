# include <bits/stdc++.h>
using namespace std ;

// Print all the permutations of the paths, to reach the end of the array
// We can only move right or down in the maze, and we start from the top-left block

vector <string> ret1 , ret2 , ret3 , ret4 ;

void solve1 ( int m , int n , string cur = "" )
{
    // Base Cases
    if ( m == 1 && n == 1 )
    {
        ret1.push_back(cur) ;
        cout << cur << endl ;   // Also, print the path
        return ;
    }

    // Recursion
    if ( m > 1 )
        solve1 ( m-1 , n , 'D' + cur ) ;
    if ( n > 1 )
        solve1 ( m , n-1 , 'R' + cur ) ;
}

void solve2 ( int m , int n , string cur = "" ) // We can also move down-right diagonally
{
    // Base Cases
    if ( m == 1 && n == 1 )
    {
        ret2.push_back(cur) ;
        cout << cur << endl ;   // Also, print the path
        return ;
    }

    // Recursion
    if ( m>1 && n>1 )
        solve2 ( m-1 , n-1 , 'S' + cur ) ;  // S = slide down
    if ( m > 1 )
        solve2 ( m-1 , n , 'D' + cur ) ;
    if ( n > 1 )
        solve2 ( m , n-1 , 'R' + cur ) ;
}

// Maze with obstacles
void solve3 ( vector<vector<int>> maze , int m , int n , string cur = "" )
{
    // Base Cases
    // We encountered an obstacle, before reaching the end
    if ( maze[m-1][n-1] )   // Maze is 0-based index
    {
        return ;  // Stopping the recursion, avoid the term, backtracking
    }
    if ( m == 1 && n == 1 )
    {
        ret3.push_back(cur) ;
        cout << cur << endl ;   // Also, print the path
        return ;
    }

    // Recursion
    if ( m>1 && n>1 )
        solve3 ( maze , m-1 , n-1 , 'S' + cur ) ;  // S = slide down
    if ( m > 1 )
        solve3 ( maze , m-1 , n , 'D' + cur ) ;
    if ( n > 1 )
        solve3 ( maze , m , n-1 , 'R' + cur ) ;
}

// All paths are allowed, UP DOWN LEFT RIGHT
void solve4 ( vector<vector<int>> &maze , int i , int j , string cur , vector<vector<int>> &visited )
{
    // Primary Base Case
    if ( visited[i][j] )
        return ;
    
    visited[i][j] = true ;  // Mark this cell as Visited

    int m = maze.size() , n = maze[1].size() ;

    // Base Cases
    // We encountered an obstacle, before reaching the end
    if ( maze[i][j] )   // Maze is 0-based index
    {

        return ;  // Stopping the recursion, "Not Backtracking"
    }
    if ( i == m-1 && j == n-1 ) // Reach the bottom-right block
    {
        visited[i][j] = false ;
        ret4.push_back(cur) ;
        cout << cur << endl ;   // Also, print the path
        return ;
    }

    // Recursion
    // Climbing Up the ladder , opposite of sliding down
    if ( i > 0 && j > 0 )   // Climb Up
        solve4 ( maze , i-1 , j-1 , cur + 'C' , visited ) ;
    if ( i < m-1 && j < n-1 )   // Slide Down
        solve4 ( maze , i+1 , j+1 , cur + 'S' , visited) ;
    if ( i > 0 )    // Go Up
        solve4 ( maze , i-1 , j , cur + 'U' , visited) ;
    if ( j > 0 )    // Go Left
        solve4 ( maze , i , j-1 , cur + 'L' , visited ) ;
    if ( i < m-1 )  // Go Down
        solve4 ( maze , i+1 , j , cur + 'D' , visited ) ;
    if ( j < n-1 )  // Go Right
        solve4 ( maze , i , j+1 , cur + 'R' , visited ) ;
    
    visited[i][j] = false ; // This is backtracking
    // We've gone through all the possible paths from this cell, so we can mark it 
    // as unvisited again, as we come back
}


// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;

    solve1(3,3) ;
    
    cout << endl ;
    
    solve2(3,3) ;
    
    cout << endl ;
    
    vector <vector<int>> maze = {
        {0,1,1},
        {0,0,0},
        {0,0,0},
    } , visited = { {0,0,0},{0,0,0},{0,0,0} } ;

    solve3(maze,3,3) ;

    cout << endl ;

    // solve4(maze,0,0) ;

    // This case is not possible, as there are infinite no. of infinite loops in the 
    // solution, where we never reach the target element.
    // To prevent this, we have to use another array, one that marks the cells that have
    // been visited earlier.
    // This prevents us from looping indefinitely

    solve4 ( maze , 0 , 0 , "" , visited ) ;

    return 0 ;
}