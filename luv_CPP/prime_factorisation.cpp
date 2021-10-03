# include <bits/stdc++.h>
using namespace std ;

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL)  ;

    int n ;
    cin >> n ;

    if ( n == 1 )
    {
        cout << "Neither Prime nor Composite" ;
        exit(0) ;
        // OR, simply write : return
    }

    vector <int> prime_factors ;

    for ( int i = 2 ; i*i <= n ; i++ )    // O(N) loop , 
    {
        while ( n%i == 0 )
        {
            prime_factors.push_back(i) ;
            n /= i ;
        }
    }

    if ( prime_factors.size() == 0 || n != 1 ) // This is a prime no., or the last prime factor is left
    {
            prime_factors.push_back(n) ;
    }

    for ( auto &x : prime_factors )
        cout << x << " " ;
    cout << endl ;

    return 0 ;
}