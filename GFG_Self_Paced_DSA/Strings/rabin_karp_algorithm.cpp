/*
1. Like Naive Algorithm, slide the pattern one-by-one
2. Compare hash values of pattern and current text window. If hash values match, then only compare individual characters

Rolling Hash :
t'i+1 = t'i + txt[i+m]-txt[i] ; // Add the new element, and delete the previous first element

Improved Hash :
Take a variable, say d, d = 5.
Instead of normal sum, we do a weighted sum, kind of like a polynomial : 1+ 2 + 3 ;-> 1.d^1 + 2.d^2 + 3.d^3

Roll Hash : (For the improved technique)
t'i+1 = h( t'i - txt[i].d^m-1 ) + txt[i+m]  ; m = length of pattern

This significantly reduces the number of cases, where we get the correct sum, but it is not the correct pattern.

Since this hash value tends to become very less, so we use modulo to store the value in less space
*/
# include <bits/stdc++.h>
using namespace std ;

/*
PSEUDOCODE :-

void RBSearch ( pat , txt , M , N )
{
    int h = 1 ;
    for ( int i = 0 ; i < m ; i++ )
        h = (h*d)%q ;                   // To calculate [d^(m-1)]%q
    
    int p = 0 , t = 0 ;
    for ( int i = 0 ; i < n ; i++ )
    {
        p = ( p.d + pat[i] )%q ;        // Calculating p
        t = ( t.d + txt[i] )%q ;        // Calculating to ( t naught )
    }

    for ( int i = 0 ; i < N-M ; i++ )   // The final pattern searching algorithm's main loop
    {                                                                                       // Checl for Spurious Hits
        if ( p == t )
            bool flag = true ;
        for ( int j = 0 ; j < m ; j++ )
            if ( txt[i+j] != pat[j] )
                flag = false ;  break ;
        if ( flag == true )
            print(i) ;
    }

    if ( i < N-M )                      // Compute t'i+1 using t'i
    {
        t = ( (d . (t - txt[i] . h)) + txt[i+m] ) % q ;
        if ( t < 0 )        // Since, we are also subtracting a value, we have to make sure that we don't get a negative hash value
            t += q ;
    }

}
*/

# define d 256          // The weight number
const int q = 101 ;     // The modulo number

void RBSearch ( string pat , string txt , int M , int N )
{
    // Compute ( d^(m-1) )%q
    int h = 1 ;
    for ( int i = 1 ; i <= M-1 ; i++ )
        h = (h*d)%q ;
    
    // Compute p and to
    int p = 0 , t = 0 ;
    for ( int i = 0 ; i < M ; i++ )
    {
        p = ( p*d + pat[i] ) % q ;      // p is the fixed pattern hash, which stores the hash value of the pattern
        t = ( t*d + txt[i] ) % q ;      // to is the test hash, which stores the hash values from the txt file
    }

    for ( int i = 0 ; i < (N-M) ; i++ ) // Performing the pattern search using the Rabin Karp Algorithm
    {
        // Check for hits
        if ( p == t )
        {
            bool flag = true ;
            for ( int j = 0 ; j < M ; j++ )
            {
                if ( txt[i+j] != pat[j] )
                {
                    flag = false ;
                    break ;
                }
            }
            if ( flag )
                cout << i << " " ;
        }

        // Compute t'i+1 using t'i
        if ( i <= N-M )
        {
            t = ( (d*(t - txt[i]*h)) + txt[i+M] ) % q ;
            if ( t < 0 )
                t += q ;
        }
    }
}

int main ()
{
    string txt = "GEEKS FOR GEEKS" ;
    string pat = "GEEK" ;
    
    cout << "All the index numbers where the pattern was found are :- " << endl ;

    RBSearch ( pat , txt , pat.length() , txt.length() ) ;

    return 0 ;
}