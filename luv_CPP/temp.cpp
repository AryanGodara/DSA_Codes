# include <bits/stdc++.h>
using namespace std ;

// A 1 , B 2 , ... , Z 26 , AA 27 , AB 28 , ...

string solve ( int n ) 
{
    string str = "" ;

    while ( n >= 1 )
    {
        if ( n == 26 )
        {
            str += 'Z' ;
            break ;
        }

        int last_digit = n%26 ;

        if ( last_digit == 0 )
        {
            str += 'Z' ;
            n /= 26 ;
            n-- ;
            continue ;
        }
        
        str += (char)('A'-1 + last_digit) ;

        n /= 26 ;
    }

    reverse( str.begin() , str.end() ) ;

    return str ;
}

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int T ;
    cin >> T ;
    
    while ( T-- ) 
    {
        int n ;
        cin >> n ;
        cout << solve(n) << endl ;
    }

    return 0 ;
}