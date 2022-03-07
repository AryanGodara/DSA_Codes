//? In this method, unlike the naive method; traversal is done only once, with constant
//? space complexity

# include <bits/stdc++.h>
using namespace std ;

int iPartition ( int arr[] , int l , int h )
{
    int pivot = arr[h] ;    // This time, the last element is the pivot

    int i = l-1 ;

    for ( int j = l ; j <= h-1 ; j++ )
        if ( arr[j] < pivot )
            swap(arr[++i],arr[j]) ;

    swap(arr[++i],arr[h]) ;

    return i ;  //? Returns the current position of the pivot, in the array
}

// Driver Function
int main ()
{
    int arr[] = {10,80,30,90,40,50,70} ;

    int n = sizeof(arr)/sizeof(arr[0]) ;

    cout << "Pivot is at: " << iPartition(arr,0,n-1) << endl ;

    for ( int &x: arr )
        cout << x << " " ;

    return 0 ;
}