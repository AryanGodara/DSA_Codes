# include <bits/stdc++.h>
using namespace std ;

vector <string> ret ;

void permutations ( string &str , int n , int i ) // All the permutations of a string
{
    // Base Case
    if ( i == n-1 )   // We've traversed the entire string, so we add it to the result
    ret.push_back ( str ) ;

    // Recursion

    for ( int j = i ; j < n ; j++ )
    {
        swap ( str[i] , str[j] ) ;
        permutations ( str , n , i+1 ) ;
        swap ( str[i] , str[j] ) ;
    }
}


// Driver Function
int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    string str = "abc" ;

    permutations(str , str.length() , 0) ;

    for ( auto &x : ret )
        cout << x << " " ;

    return 0 ;
}