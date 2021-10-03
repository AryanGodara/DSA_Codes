// Given a text and a pattern, the task is to find if there is anagram of pattern present in text.
// I/P : txt = "geeksforgeeks" , pat = "frog"
// We have to check whether any permutation of the pattern is present inside the string

# include <bits/stdc++.h>
using namespace std ;

const int CHAR = 256 ;

// Naive Code :-

/*
bool areAnagram ( string &pat , string &txt , int i )
{
    int count[CHAR] = {0} ;

    for ( int j = 0 ; j < pat.length() ; j++ )
    {
        count[pat[j]]++ ;
        count[txt[i+j]]-- ;
        // Now the array will remaing the same, only if a permutation of the characters is present
    }
    for ( int j = 0 ; j < CHAR ; j++ )
    {
        if ( count[j] != 0 )
            return false ;
    }
    return true ;
}

bool isPresent ( string &txt , string &pat )
{
    int n = txt.length() , m = pat.length() ;

    for ( int i = 0 ; i <= n-m ; i++ )
    {
        if ( areAnagram(pat,txt,i) )
            return true ;
    }
    return false ;
}

int main ()
{
    string txt = "geeksforgeeks" ;
    string pat = "frog" ;

    cout << boolalpha << isPresent(txt,pat) << endl ;
    return 0 ;
}

*/

// Efficient Solution :-

bool areSame ( int CT[] , int CP[] )
{
    for ( int i = 0 ; i < CHAR ; i++ )
    {
        if ( CT[i] != CP[i] )
            return false ;
    }
    return true ;
}

bool isPresent ( string &txt , string &pat )
{
    int CT[CHAR] = {0} , CP[CHAR] = {0} ;

    for ( int i = 0 ; i < pat.length() ; i++ )
    {
        CT[txt[i]]++ ;
        CP[txt[i]]++ ;
    }

    for ( int i = pat.length() ; i < txt.length() ; i++ )
    {
        if ( areSame(CP,CT) )
            return true ;
        CT[txt[i]]++ ;              // Window Sliding, add the new element, and
        CT[txt[i-pat.length()]]-- ; // Remove the previous beginning element.
    }

    return false ;
}

int main ()
{
    string txt = "geeksforgeeks" ;
    string pat = "frog" ;

    cout << boolalpha << isPresent(txt,pat) << endl ;
 
    return 0 ;
}