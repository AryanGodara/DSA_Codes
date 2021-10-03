# include <bits/stdc++.h>
using namespace std ;
vector <vector<int>> memo ;

int lcs ( string &s1 , string &s2 , int n , int m ) // Top-Down Approach
{
    if ( memo[n][m] != -1 )
        return memo[n][m] ; // Already calculated
    
    if ( n == 0 || m == 0 )
        memo[n][m] = 0 ;    // No common subsequence possible if one string is empty
    
    else
    {
        if ( s1[n-1] == s2[m-1] )   // This can be a part of the subsequence
            memo[n][m] = 1 + lcs(s1,s2,n-1,m-1) ;
        
        else
            memo[n][m] = max( lcs(s1,s2,n-1,m) , lcs(s1,s2,n,m-1) ) ;
    }
    return memo[n][m] ;
}

int lcs( string &s1 , string &s2 )  // Iterative Method // Tabulation // Bottom-Up approach
{
    int m = s1.length() , n = s2.length() ;

    int dp[m+1][n+1] ;

    for ( int i = 0 ; i <= m ; i++ )    // Setting the first col to zero ( when m=0 or s1 is empty)
        dp[i][0] = 0 ;
    for ( int j = 0 ; j <= m ; j++ )    // Setting the first row to zero ( when n=0 or s2 is empty)
        dp[0][j] = 0 ;

    for ( int i = 1 ; i <= m ; i++ )
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
            if ( s1[i-1] == s2[j-1] )   // Beginning of a subsequnece
                dp[i][j] = 1 + dp[i-1][j-1] ;
            else
                dp[i][j] = max( dp[i-1][j] , dp[i][j-1] ) ;
        }
    }
    return dp[m][n] ;
}

int main ()
{
    string s1 = "AXYZ" , s2 = "BAZ" ;
    int n = s1.length() , m = s2.length() ;

    for ( int i = 0 ; i < 1000 ; i++ )
        memo.push_back( vector<int> (1000,-1) ) ;

    cout << lcs(s1,s2,n,m) << endl ;
    cout << lcs(s1,s2) << endl ;

    return 0 ;
}