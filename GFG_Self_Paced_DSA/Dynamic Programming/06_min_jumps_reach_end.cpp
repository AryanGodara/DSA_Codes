// Minimum jumps to reach the end
# include <bits/stdc++.h>
using namespace std ;

int min_jumps ( vector <int> arr , int n )  // Vanilla Recursive Solution
{
    // Base Cases
    if ( n == 1 )   // Size is 1, we are at the first element
        return 0 ;  // 0 jumps are required to reach the first index

    int res = INT_MAX ; // We initially assume that it's impossible to reach this point in the array

    // Recursively check all the cells, from where we can reach the current cell
    for ( int i = 0 ; i < n-1 ; i++ ) // Here, n-1 is the current last cell, and i <= n-1
    {
        if ( i + arr[i] >= n-1 )    // It's possible to reach n-1, from this val of 'i'
        {
            int sub_res = min_jumps(arr,i+1) ;
            // We pass  i+1, instead of i, as the parameter is the size of the array, not last index
            if ( sub_res != INT_MAX )   // i.e., it's possible to reach the i'th element
            {
                res = min ( res , sub_res + 1 ) ;
                // We add 1 to sub_res because we added '1' jump to reach from 'i to the current 'n'
            }
            // Else, we just ignore and 'continue'
        }
    }

    return res ;    // This is the minimum no. of jumps required
}

int min_jumps_DP ( vector <int> arr , int n )
{
    // For the whole array, only one parameter is changing, ie, min_jumps for the i'th index
    // Therefore, we just need a 1D array, to store the min_Jumps, let's call this array 'dp;
    
    vector <int> dp(n,INT_MAX) ; // dp[i] = min jumps to reach the "index" 'i', (NOT array of size i)
    dp[0] = 0 ;     // 0 jumps required to reach the 0'th index lol

    for ( int i = 1 ; i < n ; i++ ) // For the dp array
    {
        for ( int j = 0 ; j < i ; j++ ) // For the input array 'arr', to check the possiible sub-probs
        {
            if ( arr[j] + j >= i )  // Check if we can reach i from j
            {
                if ( dp[j] != INT_MAX ) // Check if this sub-problem has a solution
                {
                    dp[i] = min ( dp[i] , dp[j] + 1 ) ;
                }
                // We add 1 to dp[j] because we added '1' jump to reach from j to i
                // Else, just ignore this one, and 'continue'
            }
        }
    }

    return dp[n-1] ;    // Minimum jumps to reach the index 'n-1' , or, the last index
}

int main ()
{
    vector <int> arr1 = {3,4,2,1,2,1} , arr2 = {4,1,2,3,1,2,1,8} ;
    // arr[i] = max distance you can jump from the i'th index in order to reach n-1

    cout << min_jumps(arr1,6) << endl ;
    cout << min_jumps(arr2,8) << endl ;
    cout << min_jumps_DP(arr1,6) << endl ;
    cout << min_jumps_DP(arr2,8) << endl ;

    return 0 ;
}