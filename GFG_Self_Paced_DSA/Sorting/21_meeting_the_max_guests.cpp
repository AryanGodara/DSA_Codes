//? You are given the arrival and departure time of the guests, you need to find the time to
//? go to the party, such that, you can meet maximum people.

# include <bits/stdc++.h>
using namespace std ;

int max_guests ( int arr[] , int dep[] , int n ) // Arrival time, Departure time
{
    sort(arr,arr+n) ;
    sort(dep,dep+n) ;

    int i = 1 , j = 0 , res = 1 , cur = 1 ;

    while ( i<n && j<n )
    {
        if ( arr[i] < dep[j] )
            cur ++, i++ ;
        else
            cur-- , j++ ;

        res = max ( res, cur ) ;
    }

    return res ;
}

int main ()
{
    int arr[] = {900,600,700} ;
    int dep[] = {1000,800,730} ;

    int n = sizeof(arr)/sizeof(arr[0]) ;

    cout << max_guests(arr,dep,n) << endl ;

    return 0 ;
}