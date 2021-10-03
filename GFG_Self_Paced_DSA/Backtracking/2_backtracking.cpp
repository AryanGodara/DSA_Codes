# include <bits/stdc++.h>
using namespace std ;

/*
We are given a binary matrix that represents a maze.
0 values are the blocked cells, and 1 values are the open cells.
Rat is at 0,0, and he has to reach n-1,n-1 cell to obtain the cheese
Only two moves are allowed from i,j -> i+1,j or i,j+1 , provided the latter cells are open
Print the path(s) the rat takes to get to the cheese, and print YES, else simply print NO
*/

const int N = 3 ;
bool maze[N][N] , sol[N][N] ;   // Global arrays are automatically initialized to 0 in all indices

void printMatrix ( bool arr[][N] )
{
    for ( int i = 0 ; i < N ; i++ )
    {
        for ( int j = 0 ; j < N ; j++ )
            cout << ( arr[i][j] ? "1" : "0" ) << " " ;
        cout << endl ;
    }
}

bool isSafe ( int i , int j )   // Checks if this cell is 1,1 and it's a valid array cell
{
    return ( i < N && j < N && maze[i][j] == 1 ) ;
}

bool solveMazeRec ( int i , int j )  // maze is a global variable array
{
    if ( i == N-1 && j == N-1 ) 
    {
        sol[i][j] = 1 ;
        return true ;
    }

    if ( isSafe(i,j) == true )
    {
        sol[i][j] = 1 ; // Turn this into 1 in the solution matrix

        if ( solveMazeRec(i+1,j) == true )  // First we go to the right cell
            return true ;
        if ( solveMazeRec(i,j+1) == true )  // Then we go to the bottom cell
            return true ;
        
        sol[i][j] = 0 ; // Backtrack in case its right and bottom cells are blocked
        
        return false ;      // Redundant line of code, not really required here
    }
    return false ;
}

bool solveMaze()
{
    if ( solveMazeRec(0,0) == false )   // Initial Call to the recursive Function
        return false ;
    
    printMatrix(sol) ;                  // Print the solution matrix
    return true ;
}

int main ()
{
    // Input the Maze array, and then call the solveMaze Function
    for ( int i = 0 ; i < N ; i++ )
    {
        for ( int j = 0 ; j < N ; j++ )
            cin >> maze[i][j] ;
    }

    cout << endl << boolalpha << solveMaze() << endl ;

    return 0 ;
}