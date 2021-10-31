# include <bits/stdc++.h>
using namespace std ;

/*
DYNAMIC PROGRAMMING

Dynamic Programming is the technique that combines the correctness of complete search and the
efficiency of greedy algorithms. DP can be applied if a problem can be divided into
overlapping subproblems that can be solved independently.
There are two uses of DP :-
1. Finding an optimal solution.     2. Counting the number of solutions.

COIN PROBLEM
Givena  set of coin values coins = {c1,c2,...,ck} and a target sum of money n, our task
is to form the sum n using as few coins as possible.
*/

void solve1 ( vector <int>&coins , int sum )    // Minimum no. of coins
{
    int n = coins.size() ;
    vector <int> dp (sum+1,INT_MAX) ;
    dp[0] = 0 ; // 0 coins are required to make the sum 0

    for ( int i = 1 ; i <= sum ; i++ )
    {
        for ( auto &coin : coins )
        {
            if ( coin <= i )
                dp[i] = min ( dp[i] , 1 + dp[i-coin] ) ;
        }
    }
    for ( int i = 0 ; i <= sum ; i++ )
        cout << "solve(" << i << ") = " << dp[i] << endl ;
    cout << endl ;
}

void solve2 ( vector <int>&coins , int sum )    // No. of possible ways
{
    int n = coins.size() ;
    vector <int> dp (sum+1,0) ;
    dp[0] = 1 ; // Only 1 way to have sum 0

    for ( int i = 1 ; i <= sum ; i++ )
    {
        for ( auto &coin : coins )
        {
            if ( coin <= i )
                dp[i] += dp[i-coin] ;
        }
    }
    for ( int i = 0 ; i <= sum ; i++ )
        cout << "solve(" << i << ") = " << dp[i] << endl ;
    cout << endl ;
}

void lis ( vector <int> &arr )
{
    int n = arr.size() ;
    vector <int> dp (n,1) ;

    for ( int i = 1 ; i < n ; i++ )
    {
        for ( int j = 0 ; j < i ; j++ )
            if ( arr[j] < arr[i] )
                dp[i] = max ( dp[i] , dp[j]+1 ) ;
    }

    for ( int i = 0 ; i < n ; i++ )
        cout << arr[i] << " " ;
    cout << endl ;
    for ( int i = 0 ; i < n ; i++ )
        cout << dp[i] << " " ;
    cout << endl << endl ;
}

void paths_in_a_grid ( vector <vector<int>> &grid )
{
    int n = grid.size() ;
    vector < vector<int> > dp ( n , vector<int> (n,0) ) ;

    dp[0][0] = grid[0][0] ;

    for ( int k = 1 ; k < n ; k++ )
        dp[k][0] = grid[k][0] + dp[k-1][0] , dp[0][k] = grid[0][k] + dp[0][k-1] ;

    for ( int i = 1 ; i < n ; i++ )
        for ( int j = 1 ; j < n ; j++ )
            dp[i][j] = grid[i][j] + max ( dp[i-1][j] , dp[i][j-1] ) ;
    
    // Print the path

    for ( int i = 0 ; i < n ; i++ )
    {
        for ( int j = 0 ; j < n ; j++ )
            cout << dp[i][j] << " " ;
        cout << endl ;
    }
}

int edit_distance ( string a , string b )
{
    int l1 = a.length() , l2 = b.length() ;

    vector <vector<int>> dp ( l1+1 , vector<int> (l2+1,0) ) ;   // dp[0][0] = 0

    for ( int i = 1 ; i <= l1 ; i++ )
        dp[i][0] = i ;
    for ( int j = 1 ; j <= l2 ; j++ )
        dp[0][j] = j ;

    for ( int i = 1 ; i <= l1 ; i++ )
    {
        for ( int j = 1 ; j <= l2 ; j++ )
        {
            if ( a[i-1] == b[j-1] )
                dp[i][j] = dp[i-1][j-1] ;
            else
                dp[i][j] = 1 +  min ( dp[i-1][j] , min ( dp[i][j-1] , dp[i-1][j-1] ) ) ;
        }
    }

    return dp[l1][l2] ;
}



// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;

    vector <int> coins = {1,3,4} ;
    int target = 10 ;
    solve1(coins,target) ;
    solve2(coins,target) ;

    vector <int> arr = {6,2,5,1,7,4,8,3} ;
    lis(arr) ;

    vector <vector <int> > grid = {
        {3,7,9,2,7},
        {9,8,3,5,5},
        {1,7,9,8,5},
        {3,8,6,4,10},
        {6,3,9,7,8},
    } ;

    paths_in_a_grid(grid) ;

    string a = "LOVE" , b = "MOVIE" ;
    cout << endl << edit_distance(a,b) << endl ;

    return 0 ;
}