// There are two methods of finding LPS ( Longest Proper Prefix Suffix ) Array are discussed. One 
// method has time complexity O(n^3) and other method is O(n).
# include <bits/stdc++.h>
using namespace std ;

// Naive Code :-    O(n^3)
/*

int longPropPreSuff ( string str , int n )
{
    for ( int len = n - 1 ; len > 0 ; len-- )
    {
        bool flag = true ;

        for ( int i = 0 ; i < n ; i++ )
        {
            if ( str[i] != str[n-len+i] )
                flag = false ;
        }
        if ( flag == true )
            return len ;
    }
    return 0 ;
}

void fillLPS ( string  str , int *lps )
{
    for ( int i = 0 ; i < str.length() ; i++ )
        lps[i] = longPropPreSuff(str,i+1) ;
}

int main ()
{
    string txt = "abacabad" ;
    int lps[txt.length()] ;

    fillLPS(txt,lps) ;

    for ( int i = 0 ; i < txt.length() ; i++ )
        cout << lps[i] << " " ;
    cout << endl ;

    return 0 ;
}

*/

// Efficient Code :-    O(n)

/* 
    Basic Ideas :
    1. If len = lps[i-1] and str[len] and str[i] are same, then lps[i] = len+1
    2. If str[i] != str[len]
        a. if len == 0
            lps[i] = 0
        b. else, we recursively apply lps[]
            len = lps[len-1]
            then compare str[i] with str[len]
*/

void fillLPS ( string str , int *lps )
{
    int n = str.length() , len = 0 ;
    lps[0] = 0 ;
    
    int i = 1 ;
    while ( i < n )
    {
        if ( str[i] == str[len] )
        {
            len++ ;
            lps[i] = len ;
            i++ ;
        }
        else
        {
            if ( len == 0 )
            {
                lps[i] = 0 ;
                i++ ;
            }
            else
                len = lps[len-1] ;
        }
    }
}

int main ()
{
    string txt = "abacabad" ;
    int lps[txt.length()] ;
    
    fillLPS(txt,lps) ;

    for ( int i = 0 ; i < txt.length() ; i++ )
    {
        cout << lps[i] << " " ;
    }
    return 0 ;
}