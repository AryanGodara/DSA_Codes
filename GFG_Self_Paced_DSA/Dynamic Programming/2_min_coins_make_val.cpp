// Minimum coins required to make a value
# include <bits/stdc++.h>
using namespace std ;

int get_min ( vector <int> coins , int n , int val )    // Vanilla Recursion Solution
{
    if ( val == 0 )
        return 0 ;  // We reached the end

    int res = INT_MAX ;

    for ( int i = 0 ; i < n ; i++ ) // Traversing the coins array
    {
        if ( coins[i] <= val )  // Select only the valid coins
        {
            int sub_res = get_min( coins , n , val-coins[i] ) ; // Recursive call to sub-problem
            // sub_res is the value of res, if we already selected coins[i], and now want to find the 
            // minimum no. of ways to find val-coins[i] ,i.e., the remaining sum.

            if ( sub_res != INT_MAX )   // This means, we found a solution
                res = min ( res , sub_res+1 ) ;   // Taking the minimum as the solution
                // sub_res + 1, because, we used 1 coin here, which was coins[i]
        }
    }

    return res ;
}

int get_min_DP ( vector <int> coins , int n , int val ) // Tabulation Solution
{
    vector <int> dp(val+1,INT_MAX) ;  // All are initially set to the impossible values
    dp[0] = 0 ; // Min ways of getting 0 coins is 0 lol

    // dp[i] = minimum coins required to get value i

    for ( int i = 1 ; i <= val ; i++ )
    {
        for ( int j = 0 ; j < n ; j++ ) // Traverse the coins array
        {
            if ( coins[j] <= i )    // 'i' is the current value of 'val'
            {
                if ( dp[i-coins[j]] != INT_MAX )    // There is a possible solution to this
                {
                    dp[i] = min ( dp[i] , dp[i-coins[j]] + 1 ) ;
                }

                /*
                    OR, We can also write the code as :-
                    itn sub_res = dp[i-arr[j]] ;
                    if ( sub_res != INT_MAX && sub_res + 1 < dp[i] )
                        dp[i] = sub_res + 1 ;
                */
            }
        }
    }

    return dp[val] ;
}

int main ()
{
    vector <int> coins1 = { 25 , 10 , 5 } ;  // We have an infinite supply of each coin in the set
    int val1 = 30 ;      // The value that we have to reach

    vector <int> coins2 = { 9 , 6 , 5 , 1 } ;
    int val2 = 11 ;

    cout << get_min(coins1,3,val1) << endl ;
    cout << get_min(coins2,4,val2) << endl ;

    cout << get_min_DP(coins1,3,val1) << endl ;
    cout << get_min_DP(coins2,4,val2) << endl ;

    return 0 ;
}