/*
    We are given n items. We are given an array that tells us about the price of those items and
    we are also given an array that tells us about the weight of those items.
    We have to return the maximum value of items that we can obtain, without surpassing the limit
    of maximum weight of the knapsack
*/

# include <bits/stdc++.h>
using namespace std ;

/*
In the DP solution
If we traverse the matrix with the row major approach :-
If the matrix is : d[W+1][n+1]
    Then, for each value of weight, we are going through the entire knapsack again and again
    This implies that we have an infinite supply of each item.

But, if the matrix is : dp[n+1][W+1]
    The, for each value of n, we are going through all the values of max_wt : 1 to W. But we aren't
    repeating the elements of the knapsack (value of n). 
    This implies that each unique item is present only once in the knapsack
*/

int knapsack_1 ( vector <int> &val , vector <int> &wt , int max_wt , int n )    // Infinite Supply
{
    int dp[max_wt+1][n+1] ;

    // When n = 0 , for all values of max_wt, max val = 0
    for ( int i = 0 ; i <= n ; i++ )
        dp[0][i] = 0 ;
    
    // When max_wt = 0, then for each n, the max val = 0
    for ( int i = 0 ; i <= max_wt ; i++ )
        dp[i][0] = 0 ;
    
    for ( int i = 1 ; i <= max_wt ; i++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
            // The max weight is the maximum weight when we include this, or we don't 
            if ( wt[j-1] > i )
                dp[i][j] = dp[i][j-1] ;
            else
                dp[i][j] = max ( val[j-1] + dp[i-wt[j-1]][i-1] , dp[i][j-1] ) ;
        }
    }

    return dp[max_wt][n] ;
}

int knapsack_2 ( vector <int> &val , vector <int> &wt , int W , int n )    // Limited Supply
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

int solve ( vector <int> &val , vector <int> &wt , int max_wt , int n )     // Backtracking Solution
{
    if ( n == 0 || max_wt == 0 )
        return 0 ;  // We have exhausted all the elements in the array

    if ( wt[n-1] > max_wt )     // We can't include this item
        return solve(val,wt,max_wt,n-1) ;
    
    return max ( val[n-1] + solve(val,wt,max_wt-wt[n-1],n-1) , solve(val,wt,max_wt,n-1) ) ;
}

int main ()
{
    vector <int> val1 = {15,14,10,5,30} , wt1 = {2,5,1,3,4} ;
    vector <int> val2 = {10,40,30,50} , wt2 = {5,4,6,3} ;

    cout << knapsack_1(val1,wt1,6,5) << endl ;
    cout << knapsack_1(val2,wt2,10,4) << endl ;

    cout << knapsack_2(val1,wt1,6,5) << endl ;
    cout << knapsack_2(val2,wt2,10,4) << endl ;

    cout << solve(val1,wt1,6,5) << endl ;
    cout << solve(val2,wt2,10,4) << endl ;

    return 0 ;
}