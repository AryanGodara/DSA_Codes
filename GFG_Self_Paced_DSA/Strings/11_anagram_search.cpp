//? Given a text and a pattern, the task is to find if anagram of pattern is
//? present in the text.

# include <bits/stdc++.h>
using namespace std ;

//! Naive Approach : Using hashing O(N^2)

bool are_anagram_naive ( string &pat , string &txt , int i ) // O(N)
{
    vector <int> count (256,0) ;

    for ( int j = 0 ; j < pat.length() ; j++ )
        count[pat[j]]++ , count[txt[i+j]]-- ;
    
    for ( int k = 0 ; k < 256 ; k++ )
        if ( count[k] != 0 )
            return false ;

    return true ;
}

bool is_present_naive ( string &txt , string &pat ) // O(N)
{
    int n = txt.length() , m = pat.length() ;

    for ( int i = 0 ; i <= n-m ; i++ )
        if ( are_anagram_naive(pat,txt,i) )
            return true ;

    return false ;
}


//* Efficient Approach using Hashing + Sliding Window O(N)
bool are_same ( vector <int> &ct , vector<int> &cp )
{
    // Simply checks the count of all ASCII chars in O(256) time
    for ( int i = 0 ; i < 256 ; i++ )
        if ( ct[i] != cp[i] )
            return false ;
    
    return true ;
}

bool is_present ( string &txt , string &pat )
{
    vector <int> ct(256,0) , cp(256,0) ;

    for ( int i = 0 ; i < pat.length() ; i++ )
        ct[txt[i]]++ , ct[pat[i]]++ ;
    
    for ( int i = pat.length() ; i < txt.length() ; i++ )
        if ( are_same(ct,cp) )
            return true ;
        else
            ct[txt[i]]++ , ct[txt[i-pat.length()]]-- ;

    return false ;
}