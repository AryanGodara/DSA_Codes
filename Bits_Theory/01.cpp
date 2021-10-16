# include <bits/stdc++.h>
using namespace std ;

string to_bin ( int n )    // Only for whole numbers
{
    if ( n == 1 )
        return "1" ;
    if ( n == 0 )
        return "0" ;

    string ret = "" ;

    while ( n )
    {
        ret += (char)((n&1)+'0') ;    // The last bit of n
        n >>= 1 ;   // Right shift n by 1 bit, OR n /= 2 ;
    }
    reverse(ret.begin(),ret.end()) ;
    return ret ;
}

void count_bits_in_range ( int L , int R )
{
    // Print the no. of Bits of each no. in the range L to R
    // Use the formula : bits[i] = bits[i/2] + i&1 ;    // Bits of i>>1 + the bit at ones place

    // OR, bits[i] = bits[i-prev_power_of_two] + 1 ;

    // Now, for the second method, we'll have to start from L = 0 (to save computation later)
    int cur_pow_2 = 2 ;

    vector <int> dp(R+1) ;

    dp[0] = 0 , dp[1] = 1 , dp[2] = 1 ;

    for ( int i = 3 ; i <= R ; i++ )
    {
        if ( i == cur_pow_2<<1 )  // We have reached a higher power of 2
            cur_pow_2 <<= 1 ;  // Update the value by multiplying it by 2
        
        dp[i] = dp[i-cur_pow_2] + 1 ;
    }

    for ( int i = L ; i <= R ; i++ )
    {
        cout << i << ": " << to_bin(i) << " : " << dp[i] << endl ;
    }
}

// Maximising XOR :-
/*
    Given two intergers l and r, find the maximal value of a xor b, where a and b satisfy the 
    following conditions : l <= a <= b <= r 
    l,r  <= 1e3
*/

void two_repeated ( vector <int> arr )
{
    int xorsum = 0 ;

    for ( auto &x : arr )
        xorsum ^= x ;   // xorsum = a^b
    
    // Find the rightmost set bit for xorsum
    int rmsb = xorsum & ~(xorsum-1) ; // Right most set bit

    int fno = 0 ;   // First number

    // Now take xor of all the numbers that have this bit set
    for ( auto &x : arr )
        if ( rmsb & x  )    // This is the same as x & 1<<i OR x>>i & 1
            fno ^= x ;
    
    int sno = xorsum ^ fno ;
    cout << fno << " " << sno << endl ;
}

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    //count_bits_in_range(0,20) ;

    two_repeated( {1 , 2 , 4 , 5 , 6 , 1 , 4 , 6 } ) ;
}