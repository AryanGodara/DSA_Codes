# include <bits/stdc++.h>
using namespace std ;

int getCount ( vector <int> coins , int n , int sum )   // Vannila_recursion
{
    if ( sum == 0 ) // We have reached a successful combination
        return 1 ;
    
    if ( n == 0 )   // We have emptied the array without reaching any solution
        return 0 ;
    
    // Recursion
    int res = getCount ( coins , n-1 , sum ) ;  // Check if it's possible w/o including the last coin

    if ( coins[n-1] <= sum )    // We can use the last coin in the combination
        res += getCount(coins,n,sum-coins[n-1]) ;   // Then add this to the result
    
    return res ;
}

// DP-Solution Iteration
// Two parameters are changing, sum and n. So, we create a 2D array of sum and n as row and col
// dp[sum+1][n+1] : as sum and dp both range from 0 to max value, therefore, max+1 elements

int getCount_dp ( vector <int> coins , int n , int sum )
{
    int dp[sum+1][n+1] ;
    // dp[i][j] = no. of combinations when sum = i, and the no. of coins to be considered is j

    for ( int i = 1 ; i <= sum ; i++ )  // If n == 0, the result will be zero
        dp[i][0] = 0 ;  // Begins with 1 because, when sum,n = 0,-

    for ( int j = 0 ; j <= n ; j++ )  // When sum == 0, ans = 1
        dp[0][j] = 1 ;

    // Now, we come to the iterative part

    for ( int i = 1 ; i <= sum ; i++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
            dp[i][j] = dp[i][j-1] ;  // Ignore the last coin (j'th coin)

            if ( coins[j-1] <= i )   // i is the current sum
                dp[i][j] += dp[i-coins[j-1]][j] ;
        }
    }
    return dp[sum][n] ;
}

int main ()
{
    vector <int> coins = {2,3,5,6} ;
    int sum = 10 ;

    cout << getCount(coins,coins.size(),sum) << endl ;
    cout << getCount_dp(coins,coins.size(),sum) << endl ;

    return 0 ;
}