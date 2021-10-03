# include <bits/stdc++.h>
using namespace std ;

# define N 4

int board[N][N] ;

void printSolution ( int arr[N][N] )
{
    for ( int i = 0 ; i < 4*N - 1 + 2 ; i++ )
        cout << "_" ;
    cout << endl ;

    for ( int i = 0 ; i < N ; i++ )
    {
        cout << "| " ;
        for ( int j = 0 ; j < N ; j++ )
            cout << (arr[i][j] ? "#" : "~") << " | " ;

        for ( int i = 0 ; i < 4*N - 1 + 2 ; i++ )
            cout << "_" ;

        cout << endl ; 
    }        
}

bool isSafe ( int row , int col )
{
    for ( int i = 0 ; i < col ; i++ )
        if ( board[row][i] )
            return false ;
    
    for ( int i = row , j = col ; i >= 0 && j >= 0 ; i-- , j-- )
        if ( board[i][j] )
            return false ;
        
    for ( int i = row , j = col ; i < N && j >= 0 ; i++ , j-- )
        if ( board[i][j] )
            return false ;
    
    return true ;
}

bool solveRec ( int col )
{
    if ( col == N )
        return true ;
    
    for ( int i = 0 ; i < N ; i++ )
    {
        if ( isSafe(i,col) )
        {
            board[i][col] = 1 ;

            if ( solveRec(col+1) )
                return true ;
            
            board[i][col] = 0 ;
        }
    }
    return false ;
}

bool solve()
{
    if ( !solveRec(0) )
    {
        cout << "The solution doesn't exist" << endl ;
        return false ;
    }

    printSolution(board) ;
    return true ;
}

int main ()
{
    solve() ;
    return 0 ;
}