/*
    1. You are given a number n, representing the count of coins
    2. You are given n numbers, representing the denominations of n coins
    3. You are given a number "amount" OR "amt"
    4. You are required to calculate and print the number of combinations of the n coins using 
       which the amount 'amt' can be paid.

    Note 1 : You have an infinite supply of each coin denomination
    Note 2 : You are required to find the count of the combinations, not permutation
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    Approach :-
    This problem is a slight variation of the "Target Sum Subsets" problem.
    Similarity : We have to find a subset of the array (coins in this case) whose sum is equal
                 to the target (amount in this case).
    Difference : In the target sum subset, we can take each element at most one time. But in this
                 problem, we can take each coin any no. of times (infinte supply).
                
    Let us define our dp state on a 1d array. We'll create an array of size (amount+1) all filled
    with 0 initially.

    Value at index i in the dp array represents the count of ways to have combination of coins
    such that their sum of valus is i.

    Trivial Case : What is the no. of ways to select coins so that their sum is 0. -> 1 way.
    So, we will initialize dp[0] as 1.
*/

/*
    Algorithm :-
    
    We will run a loop one by one for picking a coin denominations, i.e., the outer loop i will
    iterate from 0 to n-1.

    After picking a coin, we'll run a nested loop through the dp array, i.e., the inner loop 'j' 
    will iterate from 1 to amount.

    If we pick the coin arr[i], then the remaining sum becomes j - arr[i]. Hence, the amount of
    ways to form sum = j with the last coin as arr[i] is the same as the number of ways of to form
    sum = j - arr[i].

    Thus, we'll add the number of ways of combination of coins to form sum = j - arr[i] to the 
    current dp state, i.e., dp[i].

    At last, when all the coins are considered and the entire dp array is filled, we'll return the
    value of dp[amt] as it contains the number of ways of coin change combinations.
*/


int solve ( vector <int> &coins , int n , int amt )
{
    vector <int> dp(amt+1,0) ;
    
    dp[0] = 1 ;     // Only 1 way of choosin '0' coins, in order to form the amount '0'.

    for ( int coin : coins )    // Traversing the coins array
    {
        for ( int i = 1 ; i <= amt ; i++ )  // Checking for each amount
        {
            if ( i >= coin )    // The current amt is > coin, so we can use this 'coin
            {
                dp[i] += dp[i-coin] ;
            }
        }
    }

    return dp[amt] ;
}


/*
    Analysis :-
    Time complexity = O(n*amount)       Space complexity = O(amount)

    Q. We have counted all the combinations in this problem. How can we print all these combinations?
       How will the space complexity of the solution change?
    A. Yes, it's very simple to print all the ways also. We can create an array of strings instead
       of 1D arrays and at each index store all the strings (coin combinations) possible instead
       of just the count of such combinations. But be sure to add an empty string.
*/

int main ()
{
    vector <int> coins = { 2 , 3 , 5 } ;
   
    int amt = 8 ;

    cout << solve ( coins , coins.size() , amt ) << endl ;

    return 0 ;
}