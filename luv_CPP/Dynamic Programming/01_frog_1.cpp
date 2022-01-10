# include <bits/stdc++.h>
using namespace std ;

int min_cost ( vector <int> arr , int n , int k )
{
    vector <int> dp(n,INT_MAX); // dp[i] = min cost to reach i'th stone
    dp[0] = 0 ;
    dp[1] = abs(arr[1]-arr[0]);


    // for ( int i = 2 ; i <= k ; i++ )
    //     for ( int j = 1 ; j <= i ; j++ )
    //         dp[i] = min ( dp[i] , dp[i-j] + abs(arr[i]-arr[i-j]) ) ;

    for ( int i = 2 ; i < n ; i++ )
        for ( int j = 1 ; (j <= k) && (i-j >= 0) ; j++ )
            dp[i] = min ( dp[i] , dp[i-j] + abs(arr[i]-arr[i-j]) );
    
    return dp[n-1] ;
}

int main ()
{
    int n , k ;
    cin >> n >> k ;


    vector <int> arr(n) ;
    for ( int i = 0 ; i < n ; i++ )
        cin >> arr[i] ;
    
    cout << min_cost(arr,n,k) << endl ;

    return 0 ;
}