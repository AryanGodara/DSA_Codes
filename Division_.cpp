# include <bits/stdc++.h>
using namespace std ;

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL); 
    cout.tie(NULL) ;

    int T ;
    cin >> T ;
    
    while (T--)
    {
        int n , a , b ;
        cin >> n >> a >> b ;

        int even = 0 , odd = 0 ;

        long long int res = 0 ;

        for ( int i = 2 ; i <= n ; i++ )
        {
            if ( n%i != 0 )
                continue ;
            if ( i & 1 )
            {
                while ( n%i == 0 )
                {
                    n /= i ;
                    odd++ ;
                }
            }
            else
            {
                while ( n%i == 0 )
                {
                    n /= i ;
                    even++ ;
                }
            }
        }

        if ( a >= 0 && b >= 0 )
            res = even*a + odd*b ;
        else if ( a >= 0 && b < 0)
            res = ( even > 0 ? even*a : b ) ;
        else if ( a < 0 && b >= 0 )
            res = odd*b + ( even > 0 ? a : 0 ) ;
        else if ( a < 0 && b < 0 )
            res = ( even ? a : b ) ;

        cout << res << endl ;
    }
    return 0 ;
}