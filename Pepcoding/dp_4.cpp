/*
    Given an array of n integers ( non-negative ), and a target value tar, you need to check whether
    a subset of the array whose sum of elements is equal to target tar exists or not.

    Please recall that a subset ( or subsequence ) of an array is taking zero or more elements from
    the array ( in the same order in which they occur in the array ).
    
    Here, you just need to print true or false whether such a target sum exists or not.
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    Approach 1 : Using Recursion and Backtracking
        Time Complexity = O(2^n), as we have two options for each element, whether to include
        it in the subset so far, or not include it.

    Approach 2 : Using Dynamic Programming

*/

bool solve_dp ( vector <int> &arr , int n , int target )
{
    bool dp[n+1][target+1] ; // Rows are value of n, Columns are value of target

    // dp[i][j] tells whether the subset  of all elements upto i-1'th element (0 indexed) can
    // create the target sum 'j'

    // When we have 0 elements, none of the targets except zero are impossible to form
    for ( int i = 1 ; i <= target ; i++ )
        dp[0][i] = false ;
    
    // When we have the target '0', then each subset has the capability of forming this sum
    for ( int i = 0 ; i <= n ; i++ )
        dp[i][0] = true ;
    
    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= target ; j++ )
        {
            if ( arr[i-1] == j )
                dp[i][j] = true ;
            else if ( arr[i-1] > j )
                dp[i][j] = dp[i-1][j] ;
            else
                dp[i][j] = ( dp[i-1][j] || dp[i-1][j-arr[i-1]] ) ;
        }
    }

    return dp[n][target] ;
}

/*
    Analysis (DP) :-

    1. Time Complexity = O(n*target)
    2. Space Complexity = O(n*target) auxiliary space.

    Why are we using this approach ?

    If you will see carefully, we aren't re-computing all the subsets from the prefix array of
    previous elements, i.e., we aren't generating all the subsets first and then choosing whether to
    add the current element or not. Instead, we're just using the rsult of whether any subset of 
    previous elemnets can have a given sum.
    
    Hence, we're reducing the exponential time complexity to somewhat pseudo polynomial complexity.

    Note: We are saying it's pseudo polynomial time taking, as the time complexity will also depend
          on the value of target, which in turn doesn't depened on the no. of elements (n).
*/

bool solve ( vector <int> &arr , int n , int target )   // Recursion Solution
{
    // Here, we take n as the size of the portion of the array, that we are considering
    if ( n == 1 )   // We have reached the last element
        return (target == arr[n-1] ) ;
    
    if ( arr[n-1] == target )
        return true ;
    
    if ( arr[n-1] > target )    // We can't include this in the subset
        return solve(arr,n-1,target) ;  // So, we ignore it and check the rest of the array
    
    // else (We CAN include this element)
    return ( solve(arr,n-1,target) || solve(arr,n-1,target-arr[n-1]) );
}

int main ()
{
    vector <int> arr1 = { 4 , 2 , 7 , 1 , 3 } , arr2 = { 2 , 4 , 6 , 8 };

    cout << boolalpha << solve( arr1 , arr1.size() , 10 ) << endl ;
    cout << boolalpha << solve( arr2 , arr2.size() , 5 ) << endl ;

    cout << boolalpha << solve_dp( arr1 , arr1.size() , 10 ) << endl ;
    cout << boolalpha << solve_dp( arr2 , arr2.size() , 5 ) << endl ;

    return 0 ;
}