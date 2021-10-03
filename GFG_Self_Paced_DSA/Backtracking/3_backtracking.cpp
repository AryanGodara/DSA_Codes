# include <bits/stdc++.h>
using namespace std ;

/*
Place N queens on a NxN chessboard, such that no two queens attack each other. (Only for N >= 4)
Write a program that uses backtracking, to return true and a solved chessboard if N queens are
possible, else it returns false.
For each placement, we check the new solution board, to check if the present queen is clashing
with the pre-existing queens. If it does, it will return false. If all N columns return false
after a certain placement, we backtrack from the placement. (Write sol[i][j]=0)
*/

const int N = 8 ;

void printMatrix ( bool arr[][N] )  // Prints the 2D Matrix
{
    cout << "______________________________" << endl ;
    for ( int i = 0 ; i < N ; i++ )
    {
        cout << "| " ;
        for ( int j = 0 ; j < N ; j++ )
            cout << (arr[i][j] ? "@" : "^") << " | " ;
        cout << "______________________________" << endl ;
    }
}

bool board[N][N] ;   // Boolean array for the solution chess-board

bool isSafe ( int row , int col )   // Checks if a queen placed here attacks the pre-existing queens
{
    for ( int i = 0 ; i < col ; i++ )   // Left to right
        if ( board[row][i] )    // Any of the tiles in this row already have qeens placed
            return false ;
    
    for ( int i = row , j = col ; i >=0 && j >= 0 ; i-- , j--)  // Primary Diagonal Check
        if ( board[i][j] )  // Keep going left and up (right side is empty as of now)
            return false ;
    
    for ( int i = row , j = col ; j >= 0 && i < N ; i++ , j-- ) // Secondary Diagonal Check
        if ( board[i][j] )  // Keep going left and down (right side is empty)
            return false ;
    
    // No need to go up or down to check column, as only 1 queen is placed in each column

    return true ;   // We reach here, if the queen is safe to be placed at this spot
}

// The main recursive function, where the backtracking algorithm is applied
bool solveRec ( int col )   // col goes from 0 to N-1
{
    // Base Case
    if ( col == N ) // The board has been comletely filled
        return true ;
    
    // Recursive Calls
    for ( int i = 0 ; i < N ; i++ ) // Trying to place and check the queen at each row in this col
    {
        if ( isSafe(i,col) )
        {
            board[i][col] = 1 ;   // Place the queen here
            
            // Now check the next row
            if ( solveRec(col+1) == true )  // Recursive call to a sub-problem
                return true ;
            
            // Else, we'll have to backtrack
            board[i][col] = 0 ;
            // And now we check for another value of i. 
        }
    }
    // The control reaches here, if we couldn't find any place to place the queen. So return false
    return false ;
}

// Function called by the user, this function invokes the first recursive call
bool solve()
{
    if ( solveRec(0) == false )
        return false ;
    // Now we only call solveRec(0) once, because it not only returns true or false, it also
    // modifies the NxN solution matrix "board". So calling it again will destroy the solution
    // we got on the first run

    printMatrix(board) ;
    
    return true ;
}

// The Driver Function
int main ()
{
    solve() ;

    return 0 ;
}