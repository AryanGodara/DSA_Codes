/*
    Code Encodings :-
    1. You are given a string of digits (will never start with a 0)
    2. You are required to encode the str as per the following rules
        1 -> a , 2 -> b , ... , 10 -> j , 11 -> k , ... , 24 -> x , 25 -> y , 27 -> z
    3. You are required to calculate and print the count of encodings for the string str

    eg.:
    For 123 -> 3 : abc , aw , lc
    For 993 -> 1 : iic
    For 013 -> This is an invalid string. A string starting with 0 will not be passed
    For 103 -> 1 : jc
    For 303 -> 0 encodings. But such a string may have passed, in this case, print 0.
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    Approach
*/


// DP Solution
int solve ( string &str , int n )    // Length of the string
{
    if ( str[0] == '0' )    // Invalid String
        return 0 ;
    
    for ( int i = 1 ; i < n-1 ; i++ )   // Cases when we'll have invalid 2 digits in between
        if ( (str[i] == '0') && (str[i-1] == '0' || str[i-1] > '2') )
            return 0 ;

    vector <int> dp(n) ;    // For all indices from 0 to n-1
    dp[0] = 1 ; // Always fixed, only one way to write a string of length 1

    if ( str[1] == '0' )    // Either '10' or '20'
        dp[1] = 1 ;
    else if ( str[0] == '1' )
        dp[1] = 2 ;
    else if ( str[0] == '2' && (str[1]-'0' <= 6) )
        dp[1] = 2 ;
    else    // No. is greater than 26
        dp[1] = 1 ;

    for ( int i = 2 ; i < n ; i++ ) // Traversing the dp array
    {
        if ( str[i-1] == '0' && str[i] != '0'  )
        {
            dp[i] = dp[i-1] ;   // No way to form a 2 digit code
        }
        else if ( str[i-1] != '0' && str[i] == '0' )
        {
            dp[i] = dp[i-2] ; // We can only take '10' or '20', but not '0'
        }
        else  // Both are non-zero, as the both are zero condition is already checked
        {
            if ( str[i-1] == '1' )  // Then str[i] can have any value
                dp[i] =  dp[i-1] + dp[i-2] ;
            else if ( str[i-1] == '2' && (str[i]-'0' <= 6) ) // No. can't be greater than 26
                dp[i] = dp[i-1] + dp[i+2] ;
            else    // It's greater than 26, So, we can only assume the single elements
                dp[i] = dp[i-1] ;
        }
    }

    return dp[n-1] ;
}

int main ()
{
    string s1 = "123" , s2 = "993" , s3 = "013" , s4 = "103" , s5 = "303" ;

    cout << solve(s1,s1.length()) << endl ;
    cout << solve(s2,s2.length()) << endl ;
    cout << solve(s3,s3.length()) << endl ;
    cout << solve(s4,s4.length()) << endl ;
    cout << solve(s5,s5.length()) << endl ;

    return 0 ;
}