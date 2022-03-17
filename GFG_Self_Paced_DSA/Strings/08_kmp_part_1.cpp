# include <bits/stdc++.h>
using namespace std ;

//? Constructing the longest proper prefix suffix array
//* ie., the longest proper prefix that is also a suffix of the array

/*
* 
* Proper Prefixes of "abc" : "" , "a" , "ab" (length of proper suffix < length of string)
* Proper Suffixes of "abc" : "" , "c" , "bc" , "abc"
* 
*/

//! Naive O(N^3)

// helper function O(N^2)
int long_prop_pre_suff_naive ( string str , int n )
{
    for ( int len = n-1 ; len > 0 ; len-- )
    {
        bool flag = true ;

        for ( int i = 0 ; i < len ; i++ )
            if ( str[i] != str[n-len+i] )
                flag = false ;
        if ( flag )
            return len ;
    }

    return 0 ;
}

// main solver function O(N)
void fill_lps_naive ( string str , int *lps )
{
    for ( int i = 0 ; i < str.length() ; i++ )
        lps[i] = long_prop_pre_suff_naive(str,i+1) ;
}

//* Efficient O(N)
/*
* 
* Basic Ideas for O(N) approach :-
* 
* 1. If str[i] == str[len], lps[i] = len+1 , len++
* 
* 
* 2. If str[i] != str[len] :
* 
* 2.a If len == 0 , lps[i] = 0
* 
* 2.b Else, len = lps[len-1]
*   We nwo copmare str[i] and str[len]
* 
*/

void fill_lps_efficient ( string str , int *lps )
{
    lps[0] = 0 ;
    int len = 0 ;

    int i = 1 , n = str.length() ;

    while ( i < n )
    {
        if ( str[i] == str[len] )
        {
            len++ , i++ ;
            lps[i] = len ;
        }
        else if ( len == 0 )
            lps[i] = 0 , i++ ;
        else
            len = lps[len-1] ;
    }
}

//? Driver Function
int main ()
{
    string txt = "abacabad" ;
    int lps[txt.length()] = {0};

    fill_lps_efficient(txt,lps) ;

    for ( int i = 0 ; i < txt.length() ; i++ )
        cout << lps[i] << " " ;
    
    return 0 ;
}