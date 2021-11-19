#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5 ;

vector <bool> isPrime (N,true) ;

void sieve ()
{
    isPrime[1] = isPrime[0] = false ;

    for ( int i = 2 ; i < N ; i++ )
    {
        if ( isPrime[i] )
            for ( int j = i+i ; j < N ; j += i )
                isPrime[j] = false ;
    }
}

int main() 
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    sieve() ;

    int T ;
    cin >> T ;
    
    while ( T-- )
    {
        // cout << "Test\n" ;
        int n , k ;
        cin >> n >> k ;

        vector <int> a = {1} , b = {2} ;

        for ( int i = 3 ; i <= n ; i ++ )
        {
            if ( isPrime[i] && i*2>n )    // These prime nos. don't have any multiples here
                a.push_back(i) ;
            else
                b.push_back(i) ;
        }

        // for ( auto &x : a )
        //     cout << x << " " ;
        // cout << endl ;

        // for ( auto &x : b )
        //     cout << x << " " ;
        // cout << endl ;

        if ( a.size()>=k || b.size() <= k )
        {
            cout << "Yes\n" ;
            if ( a.size()  >= k )   // In this ase, we can just print k of these
            {
                // cout << "Case 1 \n" ;
                for ( int i = 0 ; i < k ; i++ )
                    cout << a[i] << " " ;
                cout << endl ;
            }
            else if (  b.size() <= k )
            {
                // cout << "Case 2 \n" ;
                for ( int i = 0 ; i < b.size() ; i++ )
                    cout << b[i] << " " ;
                for ( int i = 0 ; i < k-b.size() ; i++ )
                    cout << a[i] << " " ;
                cout << endl ;
            }
        }
        else
            cout << "No\n" ;
    }

	return 0;
}