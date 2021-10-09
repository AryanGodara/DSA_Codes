// Maximum sum with no consecutives

/*
    Find the max sum of any subsequence of an array, such that it doesn't contain any consecutive
    elements. (8 7 6 10 :-> 18 (8 + 10) )
*/

# include <bits/stdc++.h>
using namespace std ;

// Recursive Solution
int solve ( vector <int> &arr , int n , int i ) // Size of array, and the current index
{
    // Base Case
    // i == 0 -> return arr[0] , i == 1 -> return max ( arr[0] , arr[1] )
    if ( i == 0 )
        return arr[0] ;
    if ( i == 1 )
        return max ( arr[0] , arr[1] ) ;
    
    // Recursion
    // We either select this elemtn
    return max ( arr[i] + solve(arr,n,i-2) , solve(arr,n,i-1) ) ;
}


// Dynamic Programming Solution
/*
    Since, only one element (max_sum) changes with the length of the array taken (or wrt to a 
    subproblem), we only need to create a 1D dp array, of dimension 'n-1'
*/

int solve_dp ( vector <int> &arr , int n )
{
    if ( n == 1 )       // Corner Case
        return arr[0] ;
    vector <int> dp(n) ;
    dp[0] = arr[0] ;
    dp[1] = max ( arr[0] , arr[1] ) ;

    for ( int i = 2 ; i < n ; i++ )
        dp[i] = max ( arr[i] + dp[i-2] , dp[i-1] ) ;

    return dp[n-1] ;
}


// Driver Function
int main ()
{
    ios_base::sync_with_stdio(false) ;
    cout.tie(NULL) ;

    vector <int> arr1 = {1,10,2} , arr2 = {8,7,6,10} , arr3 = {10,5,15,20,2,30} ;

    cout << solve ( arr1 , arr1.size() , arr1.size()-1 ) << endl ;
    cout << solve ( arr2 , arr1.size() , arr2.size()-1 ) << endl ;
    cout << solve ( arr3 , arr1.size() , arr3.size()-1 ) << endl ;
    cout << endl ;
    cout << solve_dp ( arr1 , arr1.size() ) << endl ;
    cout << solve_dp ( arr2 , arr2.size() ) << endl ;
    cout << solve_dp ( arr3 , arr3.size() ) << endl ;

    return 0 ;
}