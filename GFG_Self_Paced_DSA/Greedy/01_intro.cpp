# include <bits/stdc++.h>
using namespace std ;

int min_coins ( vector <int> coins , int n , int amt )
{
    sort(coins.begin(),coins.end()) ;

    int res = 0 ;

    for ( int i = n-1 ; i >= 0 ; i-- )
    {
        if ( coins[i] <= amt )
        {
            int c = floor(amt/coins[i]) ;
            res += c ;
            amt -= c*coins[i] ;
        }

        if (!amt)
            break ;
    }

    return res ;
}

int main ()
{
    cout << min_coins ( { 5 , 10 , 2 , 1 } , 4 , 57 ) << endl ;
    return 0 ;
}