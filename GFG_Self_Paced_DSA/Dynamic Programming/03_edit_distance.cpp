# include <bits/stdc++.h>
using namespace std ;


/*
We are given two strings s1 and s2. We need to convert s1 into s2.
We can perform 3 unique operations : 1.insert 2.delete 3.replace

We need to do this conversion using minimum no. of operations.
*/


// My Solution
int solve ( string &s1 , string &s2 , int m , int n )   // We have to change s1 to s2
{
    // Base Case
    if ( m == 0 )   // First string is empty
        return n ;  // We need to insert these n characters (of second string)
    if ( n == 0 )
        return m ;  // We need to remove these m characters (of first string)
    
    // Recursion
    if ( s1[m-1] == s2[n-1] )
        return solve(s1,s2,m-1,n-1) ;
    
    // Find the first matching character // may take O(n^2 time)
    int x = -1 , y = -1 ;
    for ( int i = 0 ; i < m ; i++ )
        for ( int j = 0 ; j < n ; j++ )
            if ( s1[i] == s2[j] )
            {
                x = i ; y = j ; // Value keeps updating, until we find the last such value
            }

    if ( x == m-1 || y == n-1 ) // 1 of these is the last character, so we just need to add/remove
    {
        return abs(m-x-n+y) + solve(s1,s2,x,y) ;
    }

    if ( x == -1 && y == -1 )   // No matching character found
    {
        // We'll find the difference in their lengths, remove/add the extra characters, and replace
        // the remaining ones
        // we can take abs(m-n) as both add and replace take the same no. of operations
        return abs(m-n) + n ;   // no. to add/remove + no. to modify
    }

    // We reach here, if we found a match. Now find the position of the match
    if ( m-x == n-y )   // Both are at same relative positions
        return (m-x-1) + solve(s1,s2,x,y) ;
    
    // If they are at different positions
    return abs(m-x-n+y) + abs(m-x-1) + solve(s1,s2,x+1,y+1) ;
}


// GFG Vanilla Recursion Solution
int ed ( string &s1 , string &s2 , int m , int n )
{
    // Base Case
    if ( m == 0 )   // First string is empty
        return n ;  // We need to insert these n characters (of second string)
    if ( n == 0 )
        return m ;  // We need to remove these m characters (of first string)

    // Recursion
    if ( s1[m-1] == s2[n-1] )
        return ed(s1,s2,m-1,n-1) ;
    
    // If it's not same, we can do three possible operations here, insert, delete and replace.
    // In replace, we change s1[m-1] to s2[n-1], and then check for m-1,n-1 strings.
    // The minimum of these three operations is the answer.
    
    // And we have to add 1 because, we have performed any 1 of these 3 operations here.

    // 1. When we insert s2[m-1] to s1, both have the same last characters, so we reduce m-1,n by 1 
    // 2. When we delete s1[m-1], then, we have to check again fro m-1,n as n remains unchanged
    // 3. When we modify s1[m-1] to s2[n-1], both have same last character, so we check for m-1,n-1

    return ( 1 + min( ed(s1,s2,m,n-1) , min(ed(s1,s2,m-1,n) , ed(s1,s2,m-1,n-1)) ) ) ;
}

// If we look at the tree of this function, we see a lot of overlapping calls. So, we can use DP here

// Tabulation Solution // Bottom-Up
int edDP ( string &s1 , string &s2 , int m , int n )
{
    vector <vector<int>> dp(m+1) ;   // dp[m+1][n+1] from 0-m 0-n

    // dp[i][j] is the min amt of changes if s1 is of length i and s2 is of length j

    // Initialize the dp array
    for ( int i = 0 ; i <= m ; i++ )
        dp[i] = vector<int> (n+1,0) ;

    // Base Cases : When m == 0 , return n. When n == 0 , return m

    for ( int i = 0 ; i <= m ; i++ )
        dp[i][0] = i ;
    for ( int j = 0 ; j <= n ; j++ )
        dp[0][j] = j ;

    for ( int i = 1 ; i <= m ; i++ )
    {
        for ( int j =1 ; j <= n ; j++ )
        {
            if ( s1[i-1] == s2[j-1] )
                dp[i][j] = dp[i-1][j-1] ;
            else
                dp[i][j] = 1 + min( dp[i-1][j] , min( dp[i][j-1],dp[i-1][j-1] ) ) ;
        }
    }

    return dp[m][n] ;
}

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    string s1 = "sunday" , s2 = "saturday" ;

    cout << solve ( s1 , s2 , s1.length() , s2.length() ) << endl ;
    cout << ed ( s1 , s2 , s1.length() , s2.length() ) << endl ;
    cout << edDP ( s1 , s2 , s1.length() , s2.length() ) << endl ;
    
    return 0 ;
}