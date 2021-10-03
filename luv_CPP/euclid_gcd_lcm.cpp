# include <bits/stdc++.h>
using namespace std ;

int gcd1 ( int a , int b )   // a = dividend , b = divisor
{
    if ( a==b )     // Base case
        return a ;
    // Recursion
    if ( a>b)
        return gcd1(a-b,b) ;
    else
        return gcd1(a,b-a) ;
}

int gcd2 ( int a , int b )   // a = dividend , b = divisor
{
    if ( b==0 )     // Base case
        return a ;
    // Recursion
    return gcd2(b,a%b) ;
}

int main ()
{
    int a , b ;
    cin >> a >> b ;
    cout << gcd1(a,b) << endl ;
    cout << gcd2(a,b) << endl ;

    // LCM(a,b) * HCF(a,b) = a*b ;      // Very important relationship

    /*
        Euclid's Algorithm :
        gcd(a,b) = gcd(a,b-a) ;     // When b>a
                 = gcd(a-b,a) ;     // when a>b
    */

    return 0 ;
}