# include <bits/stdc++.h>
using namespace std ;

/*
N * N Sudoku board is to be filled. When we are given an integer matrix, which is partially 
filled with numbers.
For an NxN grid, the numbers should range from 1 to N
There can be multiple possible answers, but you just have to find a single answer
*/

const int N = 4 ;

int grid[][N] = {
        { 1 , 2 , 3 , 0 } ,
        { 0 , 0 , 2 , 1 } ,
        { 0 , 1 , 0 , 2 } ,
        { 2 , 4 , 0 , 0 }
    } ;                     // Global arrays are automatically initialized to 0s.

void printMatrix( int arr[][N] )
{
    cout << "______________________________" << endl ;
    for ( int i = 0 ; i < N ; i++ )
    {
        cout << "| " ;
        for ( int j = 0 ; j < N ; j++ )
            cout << arr[i][j] << " | " ;
        cout << "______________________________" << endl ;
    }
}

bool isSafe( int row , int col , int x)    // Checks if it's safe to place the number here
{
    // First check the row
    for ( int i = 0 ; i < N && i != col ; i++ )
        if ( grid[row][i] == x )    // The number already exists
            return false ;

    // Now check the column
    for ( int j = 0 ; j < N && j != row ; j++ )
        if ( grid[row][col] == x )    // The number already exists
            return false ;
    
    // If the control reaches here, that means it is safe to place 'x' at this spot
    return true ;
}

// We first fill the entire columns, and then move to the next row
bool solve()
{
    // Instead of carrying the row and col number as parameters to the function
    // We simple run an N^2 loop in each recursive call to find the first empty cell
    // Empty cells are denoted by 0.

    int i , j ;

    for ( int i = 0 ; i < N ; i++ )
    {
        for ( int j = 0 ; j < N ; j++ )
            if ( grid[i][j] == 0 )
                break ;
    }
    
    if ( i == N && j == N ) // The board is completely filleed
        return true ;
    
    for ( int n = 1 ; n <= N ; n++ )    // n is the possible value of the number to be entered
    {
        if ( isSafe(i,j,n) )
        {
            grid[i][j] = n ;

            if (solve() == true )   // If after entering this number here, we still get a solution
                return true ;   // Return true
            
            grid[i][j] = 0 ;    // Else we backtrack, and check for another n
        }
    }
    // The control reaches here, if we have exhausted all our options
    // It seems that this sudoku is impossible lol
    return false ;
}

// The Driver Function
int main ()
{
    if ( solve() == true )
    {
        printMatrix(grid) ;
        cout << endl << "True" << endl ;
    }
    else
        cout << "False" << endl ;
    return 0 ;
}