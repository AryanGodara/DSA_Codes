# include <bits/stdc++.h>
using namespace std ;

//? Filling the lps array
void fill_lps ( string &str , vector <int> &lps )
{
    int len = 0 , i = 1 , n = str.length() ;

    lps[0] = 0 ;

    while ( i < n )
    {
        if ( str[i] == str[len] )
            lps[i++] = ++len ;
        else if ( !len )
            lps[i++] = 0 ;
        else
            len = lps[len-1] ;
    }
}

void KMP ( string &pat , string &txt )
{
    int n = txt.length() , m = pat.length() ;

    vector <int> lps(m,0) ;
    fill_lps(pat,lps) ;

    int i = 0 , j = 0 ; // i = txt , j = pat

    while ( i < n ) // Traverse the text
    {
        if ( pat[j] == txt[i] )
            i++ , j++ ;
        
        if ( j == m )   // Reached the end of the string
        {
            cout << "Pattern found at index : " << i-j << endl ;
            // We're at index i, this is the last element of the pat
            // This means that the pat matching started at idnex i-j
            j = lps[j-1] ;
        }
        else if ( i<n && pat[j] != txt[i] )
        {
            if ( j == 0 )
                i++ ;
            else
                j = lps[j-1] ;
        }
    }
}

int main() 
{ 
    string txt = "ababcababaad" , pat = "ababa" ;

    KMP ( pat , txt ) ;

    return 0 ;
} 