# include <bits/stdc++.h>
using namespace std ;

//? Check if s2 is a subsequence of s1 or not
//* eg.: All subsequence of "ABC" are :- 
// A B C AB AC BC ABC

bool is_subseq ( string &s1 , string &s2 , int i , int j , int m , int n )
{
    // Base Cases
    // We've reached the last index of string 2
    if ( j == n )
        return true ;
    else if ( i == m )  // No more characters left to add to the subsequence
        return false ;
    
    // Recursion

    bool res = false ;

    for ( int k = i ; k < m ; k++ )
        if ( s1[k] == s2[j] )   // We found a partial match
            res |= is_subseq(s1,s2,k+1,j+1,m,n) ;   // We may find an answer here

    return res ;
}

bool gfg_iterative ( string s1 , string s2 , int n , int m )
{
    int j = 0 ;

    for ( int i = 0 ; i < n && j < m ; i++ )
        if ( s1[i] == s2[j] )   // Found a match
            j++ ; // Move forward in string s2
    
    return j == m ; // We reached the end of s2
}

bool gfg_recursive ( string s1 , string s2 , int n , int m )
{
    if ( !m )   // Reached the end of s2
        return true ;
    else if ( !n )  // Reached the end of s1 first
        return false ;
    
    if ( s1[n-1] == s2[m-1] )   // Found a match
        return gfg_recursive(s1,s2,n-1,m-1) ;
    else
        return gfg_recursive(s1,s2,n-1,m) ; // No change in index of s2
}

int main ()
{
    string s1 = "ABCDEFCDD" , s2 = "CDD" ;

    cout << boolalpha << is_subseq(s1,s2,0,0,s1.length(),s2.length()) << endl ;

    return 0 ;
}