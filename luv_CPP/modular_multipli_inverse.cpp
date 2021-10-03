// MODULAR MULTIPLICATIVE INVERSE : MODULAR ARITHMETIC FOR DIVISION
# include <bits/stdc++.h>
using namespace std ;

const int M = 1e9 + 7 ;

int binexp ( int a , int b , int m )
{
    int res = 1 ;

    while ( b > 0 )
    {
        if ( b & 1 )
            res = ( res * 1LL * a ) %m ;

        a = ( a * 1LL * a ) % m ;
        b >>= 1 ;   // b = b >> 1
    }
    return res ;
}

/*
MMI of A wrt M is B, if (A*B)%M == 1
Condition for MMI to exist for a pair of A,M is : A and M are co-prime. OR, __GCD(A,M) == 1 ;
*/

/*
Fermet Theorem :-
( A^(m-1) ) % M = 1     OR      A^(m-1) = 1 mod(M) // This expression is called congruency of numbers
CONDITIONS :- 1. M is prime      2. A is not a multiple of M

Multiplipying with A^-1 on both sides :-
(A^m-1)/A = A^-1 mod(M) OR      ( A^(m-2) ) %M = A^(-1)

Now, using Bin Exponentiation, A^(m-2) can be calculated in log(m) time. And so, we find A inverse
in log(n) time complexity.
*/

/*
Now, if M is not prime. But still, A and M are co-prime. Then in order to calculate A inverse,
we'll have to use Extended Euclid Algorithm, which is too advanced for us, so we'll skip it.
(I tried to learn this from HackerEarch, it is very difficult lol)
*/

/*
int main ()
{
    int a = 3 , m = 7 ;
    int a_inv ;
    a_inv = binexp(a,m-2,m) ;

    cout << a_inv << endl ;
}
*/

// Now, let's try to solve this problem

/*
    There are N children and K toffees. K<N.
    Count the number of ways to distribute toffee among N students.
    1 <= N <= 1e6
    There are Q queries.
    1 <= Q <= 1e5
*/


// Now, we know that the formula is : nCr == N(C)K in this case
// nCr = n! / (n-r)! . r!

// First let's pre compute all the factorials using DP tabulation
const int N = 1e6 + 10 ;

int fact[N] ;


void fac_store()
{
    fact[0] = 1 ;
    fact[1] = 1 ;

    for ( int i = 2 ; i < N ; i++ )
        fact[i] = ( fact[i-1] * 1LL * i ) %M ;
}

int main ()
{
    fac_store() ;   // Stores all the factorial values ( Pre computation )

    int q ;
    cin >> q ;

    while ( q-- )
    {
        int n , k ;
        cin >> n >> k ;

        int ans = fact[n] ;

        // Now, we have to calculate fact[n] / (fact[n-r].fact[r])
        // Instead of dividing and doing modulo M, we use the formula
        // (A/B)%M = (A%M * (B^-1)%M ) %M ;
        // So, we calculate 
        int den = ( fact[n-k] * 1LL * fact[k] ) %M ;

        ans = ans * binexp(den,M-2,M) ; // Using the fermet's method.

        cout << ans << endl ;
    }

}