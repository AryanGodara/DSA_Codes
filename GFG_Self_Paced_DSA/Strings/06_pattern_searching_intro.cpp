# include <bits/stdc++.h>
using namespace std ;

/*
* 
* Overview of Pattern Searching :-
* 
? m = Pattern Length, n = Text Length, 1 <= m <= n
* 
* 1. Naive : O ( (n-m+1)*m )
*    No preprocessing
* 
* 1.a Naive when all characters are distinct : O(n)
* 
* 
* 2. Rabin Karp : O ( (n-m+1)*m )
*                 But better than Naive ( on average )
*    Preprocesses PATTERN
* 
* 
* 3. KMP : O(N)
*    Preprocesses PATTERN
* 
* 
* 4. Suffix Tree : O(N)
*    Preprocesses TEXT
* 
*/

void naive_pattern_searching ( string &txt , string &pat )
{
    int m = pat.length() , n = txt.length() ;

    for ( int i =  0 ; i <= (n-m) ; i++ )
    {
        int j ;
        for ( j = 0 ; j < m ; j++ )
            if ( pat[j] != txt[i+j] )
                break ;
        
        if ( j == m )   // Match Found
            cout << i << " " ;
    }
}

void naive_for_distinct_pattern ( string &txt , string &pat )
{
    int m = pat.length() , n = txt.length() ;

    for ( int i = 0 ; i <= (n-m) ; )
    {
        int j ;

        for ( j = 0 ; j < m ; j++ )
            if ( pat[j] != txt[i+j] )
                break ;
        
        if ( j == m ) // Match found
            cout << i << " " ;

        if ( !j)    // Doesn't match even at the first character
            i++ ;
        else
            i += j ;    // These will not match as the pattern is 'distinct'
    }
}

// Driver Function
int main ()
{
    string txt = "ABBDCABBDABCDABCD" ;
    string p1 = "ABBD" , p2 = "ABCD" ;

    naive_pattern_searching(txt,p1) ;
    cout << endl ;
    naive_for_distinct_pattern(txt,p2) ;
    cout << endl ;

    return 0 ;
}