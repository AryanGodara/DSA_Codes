// Maximum Difference Between two elements
# include <bits/stdc++.h>
using namespace std ;

int maxdif ( vector <int> arr )
{
    int diff = arr[1] - arr[0] , minval = arr[0] ;

    for ( int i = 1 ; i < arr.size() ; i++ )
    {
        diff = max( diff , arr[i]-minval ) ;// minval is still <i, so arr[i]-minval checks maxdif
        minval = min(minval,arr[i]) ;   // We take the reduced value of minval
    }

    return diff ;
}

int main ()
{
    vector <int> arr = {2,3,10,6,4,8,1} ;

    cout << maxdif(arr) << endl ;

    return 0 ;
}