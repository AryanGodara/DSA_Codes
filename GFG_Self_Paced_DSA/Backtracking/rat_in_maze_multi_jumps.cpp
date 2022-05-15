# include <bits/stdc++.h>
using namespace std ;

// Naive Algorithm
/*
    while ( there are untried paths ) abcdef
    {
        generate_the_next_path()
            if ( this path has all blocks as non-zero )
                print (this path)
    }
*/

// Backtracking Algorithm
/*
    If (destination is reached)
        print (the solution matrix)
    ELSE
        a. Make the current cell in the solution matrix as 1.
        b. Move forward/jump (for each valid steps) in horizontal direction
           and recursively check if this move leads to a solution
        c. If the move chosen above doesn't lead to a solution then move down and check if
           this move leads to a solution
        d. If none of the above solutions work then unmarks this cell as 0(backtrack) and return false
*/

// Size of the matrix
# define N 4


// Function Declaration
bool solveMazeUtil ( int maze[N][N] , int x , int y , int sol[N][N] ) ;


// A utility function to print the solution matrix sol[N][N]
void printSolution ( int sol[][N] )
{
    for ( int i = 0 ; i < N ; i++ )
    {
        for ( int j = 0 ; j < N ; j++ )
            cout << sol[i][j] << " " ;
        cout << endl ;
    }
}

// A utility functino to check if x,y is valid index for N*N matrix
bool isSafe ( int x , int y , int maze[N][N] )
{
    return ( x < N && y < N && maze[x][y] != 0 ) ;
}


// This function solves the maze problem using backtracking. It mainly uses solveMazeUtil() to solve
// the problem. It returns false if no path is possible, otherwise returns true and prints the path
// in the form of 1s. 
// Please note that there may be more than one solution, this function prints one of the feasible
// solutions.
bool solveMaze ( int maze[N][N] )
{
    int sol[N][N] = { {0,0,0,0} ,{0,0,0,0} ,{0,0,0,0} ,{0,0,0,0} } ;

    if ( solveMazeUtil(maze,0,0,sol) == false )
    {
        cout << "Solution doesn't exist\n" ;
        return false ;
    }

    printSolution(sol) ;
    return true ;
}


// A recursive utility function to solve Maze problem
bool solveMazeUtil ( int maze[N][N] , int x , int y , int sol[N][N] )
{
    // Base Case
    if ( x == N-1 && y == N-1 )
    {
        sol[x][y] = 1 ;
        return true ;
    }

    // Recursive Steps
    if ( isSafe(x,y,maze) == true )
    {
        sol[x][y] = 1 ;

        // Move forward in the x direction
        for ( int i = 1 ; i <= maze[x][y] && i < N ; i++ )
        {
            if ( solveMazeUtil(maze,x+i,y,sol) == true )
                return true ;
        }
        for ( int j = 1 ; j <= maze[x][y] && j < N ; j++ )
        {
            if ( solveMazeUtil(maze,x,y+j,sol) == true )
                return true ;
        }

        // Backtrack if you reach here
        sol[x][y] = 0 ;
    }

    return false ;
}


// Driver Code
int main ()
{
    int maze[N][N] ;
    for ( int i = 0 ; i < N ; i++ )
    {
        for ( int j = 0 ; j < N ; j++ )
            cin >> maze[i][j] ;
    }

    solveMaze(maze) ;

    vector <int> soln[N] ;
    for ( int i = 0 ; i < N ; i++ )
    {
        soln[i].assign(N,0) ;
    }
    cout << endl << endl ;
    for ( auto &x : soln )
    {
        for ( int i = 0 ; i < N ; i++ )
            cout << x[i] << " " ;
        cout << endl ;
    }

    return 0 ;
}