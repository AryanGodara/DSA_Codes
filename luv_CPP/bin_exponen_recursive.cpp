// Binary Exponentiation : Recursive method

// a <= 1e9     b <= 1e9    M <= 1e9

# include <bits/stdc++.h>
using namespace std ;

const int M = 1e9 + 7 ;

long long int powerr ( long long int base , long long int power )
{
    if ( power ==0 )  // Base case
        return 1 ;
    
    long long res = powerr(base,power/2) ;

    if ( power&1 )  // odd power
        return base*res ;
    else            // even power
        return res*res ;    // power is half, but base is squared, so the square of res. = a^(b/2)*a^(b/2) = (a^2)^(b/2)
}

int binExpIter ( int a , int b )    // Iterative Function
{
    int ans = 1 ;
    while (b)
    {
        if ( b & 1 )    // Odd power
            ans = (ans * 1LL * a)%M ;     // 1LL typecasts the calculation to long long, but result is still stored in int
        a = (a*a)%M ;
        b >> 1 ;    //    b /= 1
    }
    return ans ;
}

int main ()
{
    // If, we have to calculate 2 ^ 16 ;
    long long int result = 1 , base = 12 , power = 21 ;

    while ( power > 0 )     // This is now in O(log(n))
    {
        if ( ! power%2 )    // power is even
        {
            power /= 2 ;
            base *= 2 ;
        }
        else                // power is odd
        {
            result = (result%M * base%M)%M ;
            power-- ;
        }
    }
    cout << result << endl ;

    long long int ans = 1 ;
    // Now, we try this with recursion
    cout << powerr(base,power) << endl ;

    return 0 ;
}