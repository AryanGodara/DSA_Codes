// Large Exponentiation using Binary Multiplication
# include <bits/stdc++.h>
using namespace std ;
const int M = 1e9 + 7 ;
// a , b , M <= 1e9 ( Or in the order of 10^9 )

// Special Case 1
// a <= 1e18 OR a = 2^1024

// Now if a = 2 ^ 1024 (given), and then we have to calculate a^b. So to calculate a first,  we first
// call a = binExp(2,1024) and then print : binExp(a,b) ;
int binExp ( int a , int b )
{
    a %= M ;    // Just take the modulo of a in the beginning itself, since we do it below anyways
    
    int ans = 1 ;

    while (b)
    {
        if ( b & 1 )
            ans = ( ans * 1LL * a ) % M ;
        
        a = ( a * 1LL * a ) % M ;   // a ^ 2 
        b >> 1 ;                    // b /= 2 
    }

    return ans ;
}

// Special Case 2
// M <= 1e18
// Let's take a new constant variable
const long long int mtemp = 1e18 + 17 ;

// Earlier value of a was restricted at < 1e9, and it went max to 1e9*1e9 = 1e18, when we did
// a = (a*a)%M, and then again, M brought it back to 1e9. But if M = 1e18, then a can be 1e18, and
// then, a*a will overflow even for long long int.

// So to deal with this, we make a new function for binary multiplication

int binMultiply ( long long int a , long long int b )   // We can't do direct multiplication of two nos. of 1e18
{
    // Now, a*b = a + a + a + ... ( b times ), we can use (a+b)%M = (a%M + a%M)%M ;
    // But this will make binMultiply O(N), and we want it to be O(logN), that's why we use binary multiplication

    // a * b, give binary representation to b
    // eg : a * 13 = a * ( 1 1 0 1 ) = a * ( 8 4 0 1 )
    // So now a*14 = a*8 + a*4 + a*0 + a*1 , and since the no. of bits = log(N), the time complexity also reduces

    int ans = 0 ;   // Since we will be adding to the answer, instead of multiplying, like in binExp,
                    // in which case, we would've used ans = 1
    
    while (b) 
    {
        if ( b & 1 )    // This is the set bit, so we add here
            ans = ( ans + a ) % mtemp ; // In 1 1 0 1 , the 0 case will not be added
        a = (a + a ) % mtemp ;  // This looks like O(N), but since there are log(N) bits in b, so we only do this operation log(N) times, besides b is already reducint by /=2
        b >> 1 ;    // Traversing from the rightmost to the leftmost bit of a
    }

    return ans ;
}

// Now we can use the binary exponentiation, just use binMultiply for a * a ;int binExp ( int a , int b )
int binExp2 ( int a , int b )
{
    a %= mtemp ;    // Just take the modulo of a in the beginning itself, since we do it below anyways
    
    int ans = 1 ;

    while (b)
    {
        if ( b & 1 )
            ans = ( ans * 1LL * a ) % mtemp ;   // Large value of m
        
        a = binMultiply(a,a) ;   // a ^ 2 
        b >> 1 ;                    // b /= 2 
    }

    return ans ;
}

// Special Case 3 : Large values of B : b <= 1e18 // Works fine
// Since loop runs log(B) times, so if b goes form 1e9 to 1e18, loop may run from 16 to 32, or form 32 to 64 times, whatever the no of bits
// But after a while, even though the code works for each value, but we can't just keep increasing the value of b.
// The max possible value than can be directly stored will be 1e18 ( for long long int )

// But what if b is even greater ?

// eg.: a ^ (b ^ c) : 50 ^ (64^32)
// It's very difficult to divide 64^32 by 2 in every iteration
// Now earlier we did : a^b = (a%M)^b , this works because a is just getting multiplied b times here, and so a = a*1 = (a%M * 1*M)%M = (a%M)%M = a%M
// But, we can't just do : a^b = a^(b%M), this is absurd ( Mathematically incorrect)

// We use the concept of Eular Totient Functino ETF , often representeed by Phi (Q)
// ETF(N) = no. of numbers in the range [1,N-1], which are co-prime with N.
// ETF(N) = N * MULITPLICATION_PI_SYMBOL : (1 - 1/p ) , where p is the unique prime factor of N.
// eg.: 12 = 2^2 * 3^1 , ETF(12) = 12 * (1 - 1/2) * (1 - 1/3) = 4 {1,5,7,11}

// For prime numbers ETF(N) = N * (1 -1/N) = N * (N-1) / N = (N-1) // All nos. from 1 to N-1 are co-prime with N, if N is an odd number

// Now, we have the formula :-  (a^b) % M = ( a^(b % ETF(M)) ) % M
// If M is prime, which it mostly is, then ETF(M) == M-1, so the formula changes to
// (a^b) % M = ( a^(b % M-1) ) % M)

int binExp3 ( int a , long long b , int m ) // Pass the modulo value as a parameter
{
    int ans = 1 ;
    while ( b )
    {
        if ( b & 1 )
            ans = ( ans * 1LL * a ) % m ;
        
        a = ( a * 1LL * a ) % m ;
        b >> 1 ;
    }

    return ans ;
}

int main ()
{
    // 50 ^ 64 ^ 32

    int a = 50 , b = 64 , c = 32 ;

    // First, we find 64^32 % ETF(M), which is just 64^32 % M-1, if M is prime
    b= binExp3 ( 32 , 64 , M-1 ) ;    // Since M is a prime number : 1000000007

    // Now, calculate the final result
    long long int res = binExp(64,32) ;

    cout << res << endl ;

    // OR 

    cout << binExp( a , binExp3(b,c,M-1) ) << endl ;

    return 0 ;
}