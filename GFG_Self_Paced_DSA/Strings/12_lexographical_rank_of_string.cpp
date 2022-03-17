# include <bits/stdc++.h>
using namespace std ;

int fact ( int n )
{
    vector <int> ret(n+1,1) ;
    for ( int i = 2 ; i <= n ; i++ )
        ret[i] = i * ret[i-1] ;
    
    return ret[n] ;
}

int lex_rank ( string &str )
{
    int res = 1 , n = str.length() ;
    int mul = fact(n) ;

    vector <int> count(256,0) ; // Count of each character in str

    for ( int i = 0 ; i < n ; i++ )
        count[str[i]]++ ;
    
    for ( int i = 1 ; i < 256 ; i++ )
        count[i] += count[i-1] ;
    // Now, count[i] = no. of elements <= i

    for ( int i = 0 ; i < n-1 ; i++ )
    {
        mul /= (n-i) ;
        
        res += count[str[i]-1]*mul ;

        for ( int j = str[i] ; j < 256 ; j++ )
            count[j]-- ;
    }

    return res ;
}

int main ()
{
    string str = "STRING" ;

    cout << lex_rank(str) << endl ;
}