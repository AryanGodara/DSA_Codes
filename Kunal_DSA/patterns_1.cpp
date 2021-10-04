# include <bits/stdc++.h>
using namespace std ;

void twenty_three(int n)
{
    if ( n%2==0 || n<3 )
        return ;

    int f_space = n-1 ;
    int mid_space = 2*n - 3 ;

    // Print the first line, rest have two dots

    for ( int i = 0 ; i < f_space ; i++ )
        cout << " " ;
    cout << "*" ;
    for ( int i = 0 ; i < mid_space ; i++ )
        cout << " " ;
    cout << "*" ;
    cout << endl ;

    // Now, print the rest
    f_space-- ;
    mid_space-=2 ;

    for ( int row = 2 ; row < n ; row++ )
    {
        // Print the forward spaces
        for ( int i = 0 ; i < n-row ; i++ )
            cout << " " ;
        cout << "*" ;
        for ( int i = 0 ; i < 2*row - 3 ; i++ )
            cout << " " ;
        cout << "*" ;
        for ( int i = 0 ; i < mid_space ; i++ )
            cout << " " ;
        cout << "*" ;
        for ( int i = 0 ; i < 2*row - 3 ; i++ )
            cout << " " ;
        cout << "*" ;

        mid_space -= 2 ;
        cout << endl ;
    }

    // Print the last row
    cout << "*" ;
    for ( int i = 0 ; i < 2*n - 3 ; i++ )
        cout << " " ;
    cout << "*" ;
    for ( int i = 0 ; i < 2*n - 3 ; i++ )
        cout << " " ;
    cout << "*" ;
    cout << endl ;
}


void eighteen ( int n ) // Double n
{
    int mid_spaces = 0 ;

    for ( int row = n ; row >= 1 ; row-- )
    {
        for ( int i = 0 ; i < row ; i++ )
            cout << "*" ;
        for ( int i = 0 ; i < mid_spaces ; i++ )
            cout << " " ;
        for ( int i = 0 ; i < row ; i++ )
            cout << "*" ;
        cout << endl ;
        mid_spaces+= 2 ;
    }
    mid_spaces -= 2 ;
    for ( int row = 1 ; row <= n ; row++ )
    {
        for ( int i = 0 ; i < row ; i++ )
            cout << "*" ;
        for ( int i = 0 ; i < mid_spaces ; i++ )
            cout << " " ;
        for ( int i = 0 ; i < row ; i++ )
            cout << "*" ;
        cout << endl ;
        mid_spaces -= 2 ;
    }

}

void pascals ( int n )
{
    int arr[n+1][n+1] = {0} ;

    for ( int i = 1 ; i <= n ; i++ ) // For each row
    {
        // The first and last column store 0
        for ( int j = 1 ; j <= i ; j++ )
        {
            if ( j == 1 || j == i )
                arr[i][j] = 1 ;
            else
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1] ;
        }    
    }

    // Print the 2D array now
    int f_space = n-1 ;

    for ( int i = 1 ; i <= n ; i++ )
    {
            // Print the forward spaces
            for ( int k = 0 ; k < f_space ; k++ )
                cout << " " ;
            
            // Print the elements
            for ( int j = 1 ; j <= i ;j++ )
                cout << arr[i][j] << " " ;
            cout << endl ;
            f_space-- ;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n ;
    cin >> n ;

    // pascals(n) ;

    eighteen(n) ;

    // twenty_three(n) ;   // n should be odd

    return 0 ;
}