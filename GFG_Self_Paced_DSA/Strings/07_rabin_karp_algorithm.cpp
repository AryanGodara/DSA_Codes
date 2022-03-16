# include <bits/stdc++.h>
using namespace std ;

// 1. Like the naive algorith, we slide the pattern one by one
// 2. Then we comparet the hash values of the pattern with the current text windoe.
// 2.1 If the hash values match, then only we compare the individual characters

//? This is useful in the case when, we want to match multiple patterns for a single text.

# define d 256

const int q = 101 ;

void rabin_karp ( string &pat , string &txt , int m , int n )
{
    //TODO Compute (d^(m-1))%q
    int h = 1 ;
    for ( int i = 1 ; i < m ; i++ )
        h = (h*d)%q ;
    
    //TODO Compute p and to
    int p = 0 , t = 0 ;
    for ( int i = 0 ; i < m ; i++ )
    {
        p = (p*d + pat[i]) % q ;
        t = (t*d + txt[i]) % q ;
    }

    //TODO Check for hit
    for ( int i = 0 ; i <= (n-m) ; i++ )
    {
        if ( p == t )   // Hash matches, so now, we check the order too (in linear time)
        {
            bool flag = true ;

            for ( int j = 0 ; j < m ; j++ )
            {
                if ( txt[i+j] != pat[j] )
                {
                    flag = false ;
                    break ;
                }
            }

            if ( flag )             //* Pattern Found
                cout << i << " " ;
        }

        //TODO Compute ti+1 using ti

        if ( i < n-m )
        {
            t = ( (d*(t - txt[i]*h)) + txt[i+m] ) % q ;

            if ( t<0 )
                t += q ;
        }
    }
}

// Driver Function
int main() 
{ 
    string txt = "GEEKS FOR GEEKS" ;
    string pat = "GEEK" ;
    
    cout<<"All index numbers where pattern found:" << " ";
    rabin_karp(pat,txt,4,15) ;
    cout << endl ;

    return 0; 
}