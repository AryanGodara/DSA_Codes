# include <bits/stdc++.h>
using namespace std ;

// Size of the maze and the solution array
# define N 4

bool solveMazeRec ( bool maze[N][N] , int x , int y , bool sol[N][N] ) ;  // Function Declaration


void printSolution ( bool sol[N][N] )
{
    for ( int i = 0 ; i < N ; i++ )
    {
        for ( int j = 0 ; j < N ; j++ )
            printf("%d " , sol[i][j] ) ;
        cout << endl ;
    }
}


bool isSafe ( bool maze[N][N] , int i , int j ) // Is a valid maze element, and isn't blocked
{
    return ( i < N && j < N && maze[i][j] ) ;   // maze[i][j] == true or 1
}


bool solveMaze ( bool maze[N][N] )
{
    bool sol[N][N] = {
        { 0 , 0 , 0 , 0 } ,        
        { 0 , 0 , 0 , 0 } ,        
        { 0 , 0 , 0 , 0 } ,        
        { 0 , 0 , 0 , 0 }        
    } ;

    if ( solveMazeRec(maze,0,0,sol) == false )  // If we don't find any solution
        return false ;  // When we checked, a solution board was created, so no need to call again
    
    printSolution(sol) ;    // Control reaches here, if we have found a solution

    return true ;
}


bool solveMazeRec ( bool maze[N][N] , int i , int j , bool sol[N][N] )  // Recursive Function
{
    // Base Case, when we reach the bottom-right cell of the maze array
    if ( i == N-1 && j == N-1 && maze[i][j] == 1 )
    {
        sol[i][j] = 1 ;

        return true ;
    }

    if ( isSafe(maze,i,j) == true )
    {
        sol[i][j] = 1 ; // First assign 1 at this spot in the solution array

        // Now check whether this solution continues by checking the right and bottom blocks

        if ( solveMazeRec(maze,i+1,j,sol) == true ) // Recursive call to a smaller array
            return true ;

        if ( solveMazeRec(maze,i,j+1,sol) == true ) // Recursive call to a smaller array
            return true ;
        
        // Now if the control reaches here, that means we couldn't find any solution
        // So we have to turn this sol[i][j] back to blocked and return false

        sol[i][j] = 0 ;
    }

    return false ;
}


// Driver Function
int main ()
{
    bool maze[N][N] = {
        { 1 , 0 , 0 , 0 } ,
        { 1 , 1 , 0 , 1 } ,
        { 0 , 1 , 0 , 0 } ,
        { 1 , 1 , 1 , 1 } 
    } ;

    solveMaze(maze) ;

    return 0 ;
}