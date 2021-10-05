# include <bits/stdc++.h>
using namespace std ;

int knapsack ( vector <int> &val , vector <int> &wt , int W , int n )    // Vanilla Recursion
{
    if ( n == 0 || W == 0 )     // Base Case
        return 0 ;

    if ( wt[n-1] > W )
        return knapsack(val,wt,W,n-1) ;

    else
        return max ( val[n-1] + knapsack(val,wt,W-wt[n-1],n-1) , knapsack(val,wt,W,n-1) ) ;
}

int knapsack_DP ( vector <int> &val , vector <int> &wt , int W , int n )    // Tabulation Solution
{
    int dp[n+1][W+1] ;

    for ( int i = 0 ; i <= W ; i++ )
        dp[0][i] = 0 ;
    for ( int i = 0 ; i <= n ; i++ )
        dp[i][0] = 0 ;

    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= W ; j++ )
        {
            if ( wt[i-1] > j )
                dp[i][j] = dp[i-1][j] ;
            else
                dp[i][j] = max ( val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j] ) ;
        }
    }

    return dp[n][W] ;
}

int main ()
{
    vector <int> val = { 10 , 40 , 30 , 50 }  , wt = { 5 , 4 , 6 , 3 } ;
    int W = 10 , n = 4 ;

    cout << knapsack(val,wt,W,n) << endl ;
    cout << knapsack_DP(val,wt,W,n) << endl ;

    return 0 ;
}