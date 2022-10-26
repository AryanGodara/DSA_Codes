# include <bits/stdc++.h>
using namespace std ;

# define R 4
# define C 4

int largestHist ( int arr[] , int n )
{
    stack <int> res ;

    int top_val , max_area = 0 , area = 0 , i = 0 ;

    while ( i < n )
    {
        if ( res.empty() || arr[res.top()] <= arr[i] )
            res.push(i++);
        else
        {
            top_val = arr[res.top()] ;
            res.pop() ;

            area = top_val*i;

            if ( !res.empty() )
                area = top_val * (i - res.top() - i) ;
            
            max_area = max ( area , max_area ) ;
        }
    }

    while ( !res.empty() )
    {
        top_val = arr[res.top()] ;
        res.pop() ;

        area = top_val * i ;

        if ( !res.empty() )
            area = top_val * (i - res.top() - 1) ;
        
        max_area = max ( area , max_area ) ;
    }

    return max_area ;
}

int maxRectangle ( int mat[][C] ) // Kinda like largest area histogram for each row as base
{
    int res = largestHist(mat[0],C) ;

    for ( int i = 1 ; i < R ; i++ ) // Traverse through the other rows
    {
        for ( int j = 0 ; j < C ; j++ ) // Traverse though all columns for each row
            if ( mat[i][j] == 1 )
                mat[i][j] += mat[i-1][j] ;

        res =  max ( res , largestHist(mat[i],C) ) ;
    }

    return res ;
}

int main ()
{
    int mat[][C] = {
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,0},
    };

    cout << "Area of max rectangle is " << maxRectangle(mat) << endl ;

    return 0 ;
}