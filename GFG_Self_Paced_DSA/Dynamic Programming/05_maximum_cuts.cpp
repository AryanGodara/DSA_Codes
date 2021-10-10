# include <bits/stdc++.h>
using namespace std ;

int max_cuts_rec ( int n , int a , int b , int c )   // Vanilla Recursion Solution
{
    if ( n < 0 )        // This doesn't lead to a solution
        return -1 ;
    if ( !n )           // We have reached the end
        return 0 ;

    int res = max (max_cuts_rec(n-1,a,b,c),max(max_cuts_rec(n-b,a,b,c),max_cuts_rec(n-c,a,b,c))) ;

    if ( res == -1 )    // We didn't find a solutoin
        return res ;
    
    return (res+1) ;    // We found a solution
}

int max_cuts ( int n , int a , int b , int c )  // DP Solution
{
    vector <int> dp(n+1) ;

    dp[0] = 0 ;

    for ( int i = 1 ; i <= n ;i++ )
    {
        dp[i] = -1 ;
        if ( i-a >= 0 )
            dp[i] = max ( dp[i] , dp[i-a] ) ;
        if ( i-b >= 0 )
            dp[i] = max ( dp[i] , dp[i-b] ) ;
        if ( i-c >= 0 )
            dp[i] = max ( dp[i] , dp[i-c] ) ;
        
        if ( dp[i] != -1 )
            dp[i]++ ;
    }

    return dp[n] ;
}

int main ()
{
    int n = 5 , a = 1 , b = 2 , c = 3 ;
    cout << max_cuts(n,a,b,c) << endl ;

    return 0 ;
}