# include <bits/stdc++.h>
using namespace std ;

# define M LLONG_MAX

/*
    l <= x*pow(10,digits_y) + y <= r

    l-y / pow(1o,dy) <= x <= r-y / pow(10,dy)
*/

long long int mul ( long long x , long long y )
{
    long long int res = x*y ;
    return res%M ;
}

long long int power ( long long int x , long long int y )
{
    long long int res = 1 ;
    x %= M ;

    while ( y )
    {
        if ( y&1 )
            res = mul(res,y) ;
        
        y >>= 1 ;
        x = mul(x,x) ;
    }

    return res ;
}

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int t ;
    cin >> t ;

    while ( t-- )
    {
        long long int n , l , r ;
        cin >> n >> l >> r ;

        vector <int> arr(n) ;

        long long int count = 0 ;

        for ( int i = 0 ; i < n ; i++ )
            cin >> arr[i] ;

        sort ( arr.begin() , arr.end() ) ;

        for ( auto &y : arr )
        {
            long long int digits = log10(y) + 1 ;
            long long int d = pow(10LL , digits) ;
            long long int L = (l-y+d-1LL) / d ; // Taking the ceil of the number
            long long int R = (r-y) / d ;   // Taking the floor, which automatically happens lol

            count += upper_bound(arr.begin(),arr.end(),R) - lower_bound(arr.begin(),arr.end(),L) ;

            // Upper bound find the next greater element, even if that element is present in the array
            // Lower bound find the element, if it's present, or the next greater element

            // So, we get pos of greatest possible elemnt + 1 from upper bound
            // And, then we get pos of lowest element (either exact, or the first possible,next)
            // Subtracting these two, we get the no. of elements.
        }

        cout << count << endl ;
    }
    
    return 0 ;
}