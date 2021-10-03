# include <bits/stdc++.h>
using namespace std ;

// Our range for the queries is 10^6, So, the no. of distinct prime factors can't be greater
    // than 10.
    // Because, even if all these prime factors have a power of 1, their product will be :
    // 2*3*5*7*11*13*17*19*23*27 = 6023507490 ~ 6e9


const int N = 2e6 + 10 ;

// vector <int> arr(N) ;   // For storing input, but not actually necessary, since we only need to
                        // store the hash-map of the elements of the array

vector <int> hsh(N) ;   // stores the hash value of all elements in the array

vector <int> hp(N) ; // Stores the highest prime of i'th digit

vector <int> distinctPF ( int x )   // Returns an array of the distinct PFs of a number
{
    vector <int> ret ;
    while ( x > 1 )
    {
        int pf = hp[x] ;

        while ( x%pf == 0 )
            x /= pf ;
        
        ret.push_back(pf) ;
    }

    return ret ;
}

vector <bool> canRemove(N) ; // canRemove[i] = true, if i or a no. whose power=i, is present in arr


int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    // Storing the hp       // helps to fidn the prime factors
    hp[0] = 0 ;
    hp[1] = 1 ;

    for ( int i = 2 ; i < N ; i++ )
    {
        if ( hp[i] == 0 )   // This is a prime number
        {
            for ( int j = i ; j < N ; j += i )
                hp[j] = i ;
        }
    }

    int n , q ;
    cin >> n >> q ;

    for ( int i = 0 ; i < n ; i++ )
    {
        int x ;
        cin >> x ; 
        hsh[x] = 1 ;
    }

    for ( int i = 2 ; i < N ; i++ )
    {
        if ( hsh[i] )
        {
            for ( long long int j = i ; j < N ; j *= i )
                canRemove[j] = true ;
        }
    }

    while ( q-- )
    {
        int x ;
        cin >> x ;

        vector <int> pf = distinctPF(x) ;   // Vector containing all unique prime factors
        // Now select all the possible pairs, by nC2
        bool isPossible = false ;


        for ( int i = 0 ; i < pf.size() ; i++ )
        {
            for ( int j = i ; j < pf.size() ; j++ )
            {
                long long int product = pf[i] * pf[j] ;

                if ( (i == j) && (x%product != 0) )
                    continue ;  // The number contains only 1 power of this prime factor
                
                int toRemove = x/product ;  // This no. has to be removed
                // So check if the array contains a toRemove, or a no. whose power is toRemove

                if ( canRemove[toRemove] || toRemove==1 )  // This value is present
                {
                    isPossible = true ;
                    break ;
                }
            }
            if ( isPossible )
                break ;
        }
        
        if ( isPossible )
            cout << "YES" << endl ;
        else
            cout << "NO" << endl ;
    }

    return 0 ;
}