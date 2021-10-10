// Pallidrome Partitioning
/*
    We're given a string, and we need to return the minimum no. of cuts that we have to make in
    this string in order to make each substring a pallindrome.
*/

# include <bits/stdc++.h>
using namespace std ;

bool isPallindrome ( string &str , int i , int j )
{
    if ( j-i < 1 )
        return true ;
    
    while ( i < j )
        if ( str[i++] != str[j--] )
            return false ;

    return true ;
}

int solve ( string &str , int i , int j )   // Begin and end        // My solution
{
    // Base Case, this string is already a pallindrome
    if ( isPallindrome(str,i,j) )   // Also covers the corner case of empty array
        return 0 ;  // We need to make 0 cuts

    if ( j-i == 1 ) // Length is two, and it's not a pallindrome
        return 1 ;
    
    // Recursion
    // Now, since we have to make the min no. of cuts, this solution behaves a lot like the
    // solution for the previous problem. We partition the string into two parts, in all the
    // possible ways, and return the solution, which is the minimum of all.

    int res = INT_MAX ;

    for ( int k = i ; k < j ; k++ )   // K is the point after which we partition the array
        res = min ( res , 1 + solve(str,i,k) + solve(str,k+1,j)  ) ;
    // We add 1 at each step, because, we're making at least one cut at this position

    return res ;
}

// Dynamic Programming Tabulation Solution

int solve_DP ( string &str )    // Beginning and end
{
    int n = str.length() ;
    // Base Cases
    if ( isPallindrome(str,0,n-1) )   // Also covers the corner case of empty array
        return 0 ;  // We need to make 0 cuts

    if ( n == 2 ) // Length is two, and it's not a pallindrome
        return 1 ;
    
    int dp[n][n] ;  // dp[i][j] = no. of cuts to make the string from [i,j] pallindromic

    // Empty strings need 0 cuts
    for ( int i = 0 ; i < n ; i++ )
        dp[i][i] = 0 ;
    
    // Now, we fill the rest of the matrix, diagonal to diagonal, moving up and right

    for ( int gap = 1 ; gap < n ; gap++ )   // Max gap is b/w i=0 and j=n-1 -> gap = n-1
    {
        for ( int i = 0 ; i+gap < n ; i++ )
        {
            int j = i + gap ;
            dp[i][j] = INT_MAX ;

            if (isPallindrome(str,i,j) )
            {
                dp[i][j] = 0 ;
                break ;
            }

            for ( int k = i ; k < j ; k++ )
                dp[i][j] = min ( dp[i][j] , 1 + dp[i][k] + dp[k+1][j] ) ;
        }
    }

    return dp[0][n-1] ;
}

int main ()
{
    string str1 = "geek" , str2 = "abbac" , str3 = "abcde" , str4 = "aaaa" , str5 = "abbabbc";

    cout << solve(str1,0,str1.length()-1) << endl ;
    cout << solve(str2,0,str2.length()-1) << endl ;
    cout << solve(str3,0,str3.length()-1) << endl ;
    cout << solve(str4,0,str4.length()-1) << endl ;
    cout << solve(str5,0,str5.length()-1) << endl ;
    cout << endl ;
    cout << solve_DP(str1) << endl ;
    cout << solve_DP(str2) << endl ;
    cout << solve_DP(str3) << endl ;
    cout << solve_DP(str4) << endl ;
    cout << solve_DP(str5) << endl ;

    return 0 ;
}