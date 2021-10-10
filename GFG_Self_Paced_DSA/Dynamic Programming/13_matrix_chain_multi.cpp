// Matrix Chain Multiplication
/*
    You are given a matrix of length n, which stores the size of n-1 matrices.
    eg.: arr[] = {2,1,3,4} -> 3 matrices of 2x1 , 1x3 , 3x4.

    You need to find the minimum no. of multiplications that need to be performed in order to 
    multiply all these matrices.

    eg.: to multiply 21 13 and 34, there are two ways
    1. 2x1 * (1x3 * 3x4 ) = 20 ways     ;   2. (2x1 * 1x3) * 3x4 = 30 ways
    Thus, our answer is 20.

    // Two solve two matrices of mxn and nxo, we're required to perform m*n*0 multiplications (check)
*/
# include <bits/stdc++.h>
using namespace std ;

/*
    Base Case :
    When n == 3, return a[0]*a[1]*a[2] ;    // Only one way to multiply two matrices
    When n == 2, return 0 ; // As there's only one matrix, so no multiplication occurs.
*/

int solve ( vector <int> arr )  // n >= 2       // My Solution
{
    int n = arr.size() ;
    // Base Case
    if ( n == 2 )   // Only one matrix
        return 0 ;
    if ( n == 3 )
        return arr[0]*arr[1]*arr[2] ;
    
    // Recursion
    // Starting from the first triplet, return the minimum for each triplet

    vector <int> ret ;  // To be of size n-1
    int res = INT_MAX ;

    for ( int i = 0 ; i < n-2 ; i++ )   // Selecting pairs of three
    {
        // The elements before the triplet
        ret.insert(ret.end(),arr.begin(),arr.begin()+i) ;

        // The three elements, are converted to two : The first and the last ones are taken
        ret.push_back(arr[i]) ;
        ret.push_back(arr[i+2]) ;

        // The elements after the triplet
        ret.insert(ret.end(),arr.begin()+i+3,arr.end()) ;

        // Call the recursive function for the subproblem
        res = min ( res , arr[i]*arr[i+1]*arr[i+2] + solve(ret) ) ;

        // Now, reset the 'ret' array,
        // Also, instead of doing all this, we can simply select all the elements, except
        // the one that is going to be in the middle of the current triplet
        ret.clear() ;
    }

    return res ;
}

// GFG Recursion Solution
int mchain ( vector <int> &arr , int i , int j )
{
    // Base Cases
    if ( i+1 == j ) // Only 2 elements
        return 0 ;
    if ( i+2 == j ) // Only 3 elements
        return arr[i] * arr[i+1] * arr[i+2] ;

    // Recursion
    int ret = INT_MAX ;

    // (m1) (m2 m3 m4) i = 0  ,  k = 1  ,  j = n-1
    // (m1 m2) (m3 m4) i = 0  ,  k = 2  ,  j = n-1
    // (m1 m2 m3) (m4) i = 0  ,  k = 3  ,  j = n-1
    // As we can see, there are multiple ways to oplace the first parenthesis, we go through the 
    // entire array, and collect the minimum for each way of doing the parenthesis.
    // Then, through recursion, we get our solution

    for ( int k = i+1 ; k < j ; k++ )    
        ret = min ( ret , mchain(arr,i,k) + arr[i]*arr[k]*arr[j] +mchain(arr,k,j) ) ;
    
    // ret shows the : No. of steps to solve the first parenthesis + no of steps to solve the
    // second parenthesis + No of steps to solve the product of the final two matrices,
    // which will have the dimensions : i*k and k*j. So, we then add i*k*j, and return the ans
    return ret ;
}

// Dynamic Programming Solution

int solve_DP ( vector <int> &arr ) // Tabulation Solution
{
    int n = arr.size() ;

    // Base cases
    if ( n <= 2 )
        return 0 ;
    if ( n == 3 )
        return arr[0]*arr[1]*arr[2] ;
    
    int dp[n][n] ;  // dp[i][j] = result for subarray from i to j. i : (0,n-1) , j : (0,n-1)

    // When j > i, we'll ignore those cases
    // if j = i+1, then dp[i][j] = 0
    for ( int i = 0 ; i < n-1 ; i++ )
        dp[i][i+1] = 0 ;
    // Here, we've already filled the longest diagonal in the uperr-right triangle of the matrix
    /*
    _ * * * *
    _ _ * * *
    _ _ _ * *
    _ _ _ _ *
    */
    // Now, we fill the rest of the array ( only for the cases where i < j )
    // Then, for each value of i,j : We need to do a run for k = i+1 to j-1
    // Now, Since the answer is the top-right corner, and we only need to fill the right-upper
    // triangle(i>j), we can't just simply start filling the array from (0,0).

    for ( int gap = 2 ; gap < n  ; gap++ )  // There should be a min. gap of 2 b/w i and j
    {   // We're filling the matrix from diagonal to diagonal
        for ( int i = 0 ; i + gap < n ; i++ )   // i+gap is j, which should also be < n
        {
            int j = i+gap ;

            dp[i][j] = INT_MAX ;

            for ( int k = i+1 ; k < j ; k++ )
                dp[i][j] = min ( dp[i][j] , dp[i][k] + arr[i]*arr[k]*arr[j] + dp[k][j] ) ;
        }
    }

    return dp[0][n-1] ; // Return the final result for the entire array
}

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cout.tie(NULL) ;

    vector<int> arr1 = { 2 , 1 , 3 , 4 } , arr2 = {2,1,3} , arr3 = {3,4} , arr = {10,20,30,40,50} ;
    
    cout << solve(arr1) << endl ;
    cout << solve(arr2) << endl ;
    cout << solve(arr3) << endl ;
    cout << solve(arr) << endl ;
    cout << endl ;
    cout << mchain(arr1,0,arr1.size()-1) << endl ;
    cout << mchain(arr2,0,arr2.size()-1) << endl ;
    cout << mchain(arr3,0,arr3.size()-1) << endl ;
    cout << mchain(arr,0,arr.size()-1) << endl ;
    cout << endl ;
    cout << solve_DP(arr1) << endl ;
    cout << solve_DP(arr2) << endl ;
    cout << solve_DP(arr3) << endl ;
    cout << solve_DP(arr) << endl ;

    return 0 ;
}