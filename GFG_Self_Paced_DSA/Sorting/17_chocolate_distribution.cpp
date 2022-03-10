//? We're given an array and need to select 'm' elements out of these, such that the difference
//? between the maximum and the minimum of the 'm' elements we picked, is minimized

# include <bits/stdc++.h>
using namespace std ;

//TODO: We pick an element, and set it as the minimum of 'm' elements, and then look for
//TODO: the other 'm-1' elements, that are greater than this
//? (Looks like we'll have to do partitioning from quicksort)

int min_diff ( int arr[] , int n , int m )
{
    if ( m > n )    // Invalid Case
        return -1 ;

    sort ( arr , arr+n ) ;

    int res = arr[m-1]-arr[0] ;

    for ( int i = 0 ; i < n-m+1 ; i++ )
        res = min ( res , arr[i+m-1] - arr[i] ) ;

    return res ;
}

int main ()
{
    int arr[] = {7,3,2,4,9,12,56} ;

    int n = sizeof(arr)/sizeof(arr[0]) , m = 3 ;

    cout << min_diff(arr,n,m) << endl ;

    return 0 ;
}