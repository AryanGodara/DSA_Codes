/*
    You are given an array of n numbers which represent n different tyeps of denominations of coins.
    You are given a target 'amt', you need to count the number of permutatinos of the coins possible
    that sum up to the given target amount, i.e., in how many ways you can pay 'amt' using the 
    available denominations.

    Note 1 : You can consider having an infinite supply of each coin denominations i.e., the same
    coin denominations can be used for many installments in payment of 'amt'.

    Note 2 : You are required to find the count of 'distinct permutations'. 
           : Remember, each coin of the same denomination is identical
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    Approach :-
    
    Let us define our dp state on a 1D array. We'll create an array of size (amount+1) all filled 
    with 0 initially.
    
    Value at index 'i' in the dp array represents the count of ways to have permutations of coins
    such that their sum of values is 'i'

    Trivial Case : What is the no. of ways  to select the coins so that their sum = 0. -> 1

    Q. But how did we stop coin permutations in the previous solution?
    A. We ran the loop for the first coin for the entire array at once and then ran the loop for
       the second coin for the entire array, and so on.
    Summary is that : outer loop i went from 0 to n and inner loop from 1 to amt.
    By doing so, we stopped the occurrence of the first coin after the second coin.

    Q. How can we bring back those permutations? Try to modify the code a little bit, so that first
       all denominations of coins are analyzed for smaller amount, then for larger amounts.

    So, in this case, what we all need to do is first find ways of permuting coins for amount 1 
    using all coitns, the for amount 2, and so on.
    Hence we need the amount loop to be the outer one and the loop over coins to become the inner one.

    Voila! Only thing we need to change is interchange the loops. That's all
*/

int solve ( vector <int> &coins , int n , int amt )
{
    vector <int> dp(amt+1,0) ;
    dp[0] = 1 ; // Only 1 way to add coins upto amt '0'

    for ( int i = 1 ; i < dp.size() ; i++ )
    {
        for ( int coin : coins )
        {
            if ( i >= coin )
                dp[i] += dp[i-coin] ;
        }
    }

    return dp[amt] ;
}

int main ()
{
    vector <int> coins = { 2 , 3 , 5 } ;
   
    int amt = 8 ;

    cout << solve ( coins , coins.size() , amt ) << endl ;

    return 0 ;
}