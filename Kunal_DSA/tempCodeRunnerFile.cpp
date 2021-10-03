nt arr[n+1][n+1] = {0} ;

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