/*
    1. You are given a number n, representing the number of stairs in a staircase
    2. You are on the 0'th step and are required to climb to the top
    3. You are given n numbers, where i'th element represents - till how far from the step you can
       jump in a single move
    4. You are required to print the number of different paths via which you can climb to the top
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    Approach (Tabulation) :-
    1. Storage and Meaning :-
        We'll make an array of size 'n' and call it 'dp'. Now, dp[i] will store the no. of paths
        to reach to 'n' from 'i'.
    2. Direction :-
        To get the direction we ask the following questions :
            1. What is the no. of paths to reach from 6 to 6?
            2. What is the no. of paths to reach from 0 to 6?
        Out of these, the 1st questions is much easier to answer, and its answer is '1'.
        So, our direction will be from 6 -> 0.

*/

// no of ways to reach the top of the stairs
int count_steps ( vector <int> arr , int n )    // Time Complexity = O(n^2)
{
    vector <int> dp(n+1) ;
    dp[n] = 1 ; // There is only 1 way to go from the top to the top (You're already at the top)

    for ( int i = n-1 ; i >= 0 ; i-- )  // Count the possible steps from each step
    {
        int count = 0 ;
        for ( int j = 1 ; j <= arr[i] ; j++ )   // Value of jumps possiible from arr[i]
        {
            if ( i + j <= n )
            {
                count += dp[i+j] ;
            }
        }
        dp[i] = count ;
    }
    
    return dp[0] ;  // No of ways to reach the top from the bottom stair
}

int solve ( vector <int> &arr , int index , int n )     // Vanilla Recursion Solution
{
    if ( index == n )   // We have reached the end of a succesful path
        return 1 ;
    
    int count = 0 ;

    for ( int jump = 1 ; jump <= arr[index] ; jump++ ) // Size of jumps, we can take from this index
    {
        if ( jump + index <= n )    // We can perform this jump
        {
            count += solve(arr,jump+index,n) ;
        }
        else
            break ; // All jumps from this point on are invalid, as they cross the top.
    }

    return count ;
}

int main ()
{
    vector <int> arr1 = { 3 , 3 , 0 , 2 , 2 , 3 } , arr2 = { 2 , 3 , 0 , 1 , 2 , 3 } ;

    cout << count_steps(arr1,6) << endl ;
    cout << count_steps(arr2,6) << endl ;

    return 0 ;
}