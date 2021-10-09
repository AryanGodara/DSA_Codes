// Find the no. of subsets of a given array, with the given 'sum'

# include <bits/stdc++.h>
using namespace std ;

// Vanilla Recursion Solution
int solve ( vector <int> &arr , int i , int sum )   // Current Index , Current Sum
{
    // Base Case
    if ( i == 0 )   // We have traversed the entire array
        return ( (sum == 0) ? 1 : 0 ) ;
    
    // Recursion
    // We either select the current element in which case, the value of sub is decreased by the
    // value of the current element.
    // And if we don't select this element, then the value of sum remains the same.

    return solve(arr,i-1,sum) + solve(arr,i-1,sum-arr[i-1]) ;
}


// Dynamic Programming Solution (Tabulation)
int solve_dp ( vector <int> &arr , int sum )
{
    int n = arr.size() ;

    int dp[n+1][sum+1] ; // dp[i][j] = count of subsets in 'arr[0,...,i-1]' with sum 'j'

    // When the sum is zero, then the empty subset always satisfies the condition.
    // And for each value of n, the array will have an empty subset.
    for ( int i = 0 ; i <= n ; i++ )
        dp[i][0] = 1 ;
    
    // When the size of the array is 0, then the no of subsets will be zero (undefined anyways)
    for ( int i = 0 ; i <= sum ; i++ )
        dp[0][i] = 0 ;

    // For the rest of the array, we can only use each element once, for any subset.
    // So, we'll fill the dp matrix in the row major style

    for ( int i = 1 ; i <= n ; i++ )    // No of elements in the array
    {
        for ( int j = 1 ; j <= sum ; j++ )  // Required subset sum
        {
            if ( arr[i-1] > j )
                dp[i][j] = dp[i-1][j] ;    // Ignoring this element

            else
                dp[i][j] = dp[i-1][j] +  dp[i][j-arr[i-1]] ;    // Using this element
        }
    }

    return dp[n][sum] ;
}

// Driver Function
int main ()
{
    vector <int> arr1 = {10,20,15} ;

    cout << solve(arr1,arr1.size(),25) << endl ;
    cout << solve_dp(arr1,25) << endl ;

    return 0 ;
}