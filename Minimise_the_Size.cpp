# include <bits/stdc++.h>
using namespace std ;

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int t ;
    cin >> t ;

    while ( t-- )
    {
        long long int c ;
        cin >> c ;

        vector <long long int> v ;
        long long int cur_xor = 0 ;

        for ( int i = 60 ; i >= 0 ; i-- )   // Going through all bits of C, from MSB to LSB
        {
            long long int b1 = (1LL << i) & c ; // This bits of C, 1 or 0
            long long int b2 = (1LL << i) & cur_xor ;  // This bit of cur_xor, set or not

            if ( b1 != b2 ) // One is set, but the other isn't
            {
                v.push_back ( (1LL<<(i+1))-1 ) ;    // Add nos which has 1 upto this point
                cur_xor ^= ( (1LL<<(i+1))-1 ) ;     // Add this item to the xorsum
            }
        }

        if ( v.size() == 0 )    // Means, c has no set bit. Therefore, c = 0 ;
        {
            v.push_back(1) ;    // Xor of 1^1 = 0
            v.push_back(1) ;
        }

        sort ( v.begin() , v.end() ) ;

        cout << v.size() << endl ;
        for ( auto &x : v )
            cout << x << " " ;
        cout << endl ;
    }

    return 0 ;
}