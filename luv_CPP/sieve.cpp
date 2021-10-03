# include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 10 ;
// const int N = 100 ;

vector <bool> isPrime ( N , 1 ) ;
vector <int> lp(N,0) , hp(N,0) ;    // lp[i] = lowest prime of i , hp[i] = highest prime of i
vector <int> p_factors ;
vector <int> divisors[N] ;  // A vector of integer arrays.

int main ()
{
    isPrime[0] = isPrime[1] = false ;

    for ( int i = 2 ; i < N ; i++ )
    {
        if ( isPrime[i] == true )
        {
            lp[i] = hp[i] = i ; // The prime no. iteslf is its greatest and lowest prime factor
            for ( int j = 2*i ; j < N ; j+=i )
            {
                isPrime[j] = false ;
                hp[j] = i ;         // i is the greatest prime no. that divides each of these j's
                //If in future we come across i' which also divides j. THen hp[j] will be updated to i'

                // Since the lowest prime shouldn't be updated like hp, we'll set a condition there
                if ( lp[j] == 0 )
                    lp[j] = i ; // Now, this won't be changed in the future
            }
        }
    }

    // PRIME FACTORISATION
    int num ;       // Find the prime factorisation of num
    cin >> num ;

    while ( num > 1 )
    {
        int primefactor = lp[num] ;
        while ( num%primefactor == 0 )  // Keep dividing by this prime factor as long as possible
        {
            num /= primefactor ;
            p_factors.push_back(primefactor) ;
        }
        // Loop keeps going on. We find the prime factorisation in log(n) time.
        // [ After we have already pre-computed sieve algorithm, to store highest and lowest_prime]

        // And if you want to store the prime factors for each number, we can create an unordered_map, 
        // with key as nums, and value as the number of prime factors.
    }
    for ( auto &x : p_factors )
        cout << x << " " ;
    cout << endl << endl ;


    // divisors[i] stores the divisors of i.
    for ( int i = 2 ; i < N ; i++ )
    {
        for ( int j = i ; j < N ; j+= i )
            divisors[j].push_back(i) ;  // Here 'i' is a divisor for all values of j
    }
    cout << endl << endl ;

    for ( int i = 1 ; i < 10 ; i++ )
    {
        for ( int div : divisors[i] )   // divisors[i] is an array, and divisors is a vector of arrays
            cout << div << " " ;
        cout << endl ;
    }


    cout << endl << endl ;
    for ( int i = 0 ; i < 101 ; i++ )
        cout << i << " : " << isPrime[i] << " " << lp[i] << " " << hp[i] << endl ;

    return 0 ;
}



/*
    // Sieve Algorithm
    {
    isPrime[0] = isPrime[1] = false ;

    for ( int i = 2 ; i < N ; i++ )
        if ( isPrime[i] == true )
            for ( int j = 2*i ; j < N ; j+= i )
                isPrime[j] = false ;

    for ( int i = 0 ; i < isPrime.size() ; i++ )
        if ( isPrime[i] )
            cout << i << " " ;
    cout << endl ;
    return 0 ;
}
*/