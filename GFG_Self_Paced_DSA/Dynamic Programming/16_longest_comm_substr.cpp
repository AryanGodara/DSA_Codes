# include <bits/stdc++.h>
using namespace std ;

string longest_common_substring ( string a , string b )
{
    int m = a.length() , n = b.length() ;

    // Length of a and b don't make any difference in the final result

    string dp[m+1][n+1] ;  // -1 to m-1 , -1 to n-1 ; -1 == empty string, denoted by 0 in matrix

    for ( int i = 0 ; i <= m ; i++ )
        dp[i][0] = "" ;
    for ( int i = 0 ; i <= n ; i++ )
        dp[0][i] = "" ;

    for ( int i = 1 ; i <= m ; i++ ) // String a (Larger String)
    {
        for ( int j = 1 ; j <= n ; j++ ) // String b (Smaller String)
        {
            if ( a[i-1] == b[j-1] ) // This can be a part of the common substring
                dp[i][j] = dp[i-1][j-1] + a[i-1] ;
            else
            {
                string s1 = dp[i-1][j] , s2 = dp[i][j-1] , s3 = dp[i-1][j-1] ;
                if ( s1.length() == s2.length() && s2.length() == s3.length() )
                    dp[i][j] = dp[i-1][j-1] ;
                else if ( s1.length() >= s2.length() && s1.length() >= s3.length() )
                    dp[i][j] = s1 ;
                else if ( s2.length() >= s1.length() && s2.length() >= s3.length() )
                    dp[i][j] = s2 ;
                else if ( s3.length() >= s2.length() && s3.length() >= s1.length() )
                    dp[i][j] = s1 ;
            }
        }
    }

    // for ( int i = 0 ; i <= m ; i++ )
    // {
    //     for ( int j = 0 ; j <= n ; j++ )
    //         cout << i<<","<<j<<" : " << dp[i][j] << "  " ;
    //     cout << endl ;
    // }

    return dp[m][n] ;
}

int main ()
{
    string s1 = "xdstartlol" , s2 = "starfish" ;

    cout << longest_common_substring(s1,s2) ;
}