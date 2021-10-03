// Improved Naive Algorithm for Distinct
# include <bits/stdc++.h>
using namespace std ;

/*
PSEUDOCODE :-

void patsearch ( txt , pat )
{
    int n = txt.length ;    // int m = pat.length ;

    for ( int i = 0 ; i < n-m ; i++ )
    {
        int j ;
        for ( j = 0 ; j < m ; j++ )
        {
            if ( pat[j] != txt[i+1] )
                break ;
        }    

        if ( j == m )
            print (i + " ") ;
        if ( j == 0 )
            i++ ;
        else
            i += j ;
    }
}
*/