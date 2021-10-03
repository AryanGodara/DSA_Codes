# include <bits/stdc++.h>
using namespace std ;

int leftnonrep ( const string &str , int n )
{
    vector <int> fi(256,-1) ;

    for ( int i = 0 ; i < n ; i++ )
    {
        if ( fi[str[i]] == -1 ) // First occurence
            fi[str[i]] = i ;    // Store its location

        else    // Repeated value
            fi[str[i]] = -2 ;   // Brand it as an invalid
    }

    int res = INT_MAX ;

    for ( int i = 0 ; i < n ; i++ )
    {
        if ( fi[str[i]] != -1 && fi[str[i]] != -2 )
            res = min(res,fi[str[i]]) ;
    }

    return (res == INT_MAX) ? -1 : res ;
}

int main ()
{
    string str = "abachebsensebc" ;
    cout << leftnonrep(str,15) << endl ;

    return 0 ;
}