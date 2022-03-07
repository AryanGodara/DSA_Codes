//? This partitioning method is better than naive and lomuto; it only takes constant space
//? and O(N) time for partitioning. It also travels the array only once
//! You'll notice that the pivot is not at its correct position in the array (Drawback)

# include <bits/stdc++.h>
using namespace std ;

int partition ( int arr[] , int l , int h )
{
    int pivot = arr[l] ;    // This time, the first element is the pivot
    int i = l-1 , j = h+1 ; //? One before starting, one after ending

    // for ( int k = l ; k <= h ; k++ )
    //     cout << arr[k] << " " ;
    // cout << endl ;

    while ( true )
    {
        do {
            i++ ;
        } while ( arr[i] < pivot ) ;

        do {
            j-- ;
        } while ( arr[j] > pivot ) ;

        if ( i >= j )   //? This only happens if, the array is already partitioned
            return j ;  //! The position of the last element, smaller than pivot

        swap(arr[i],arr[j]) ;

        // cout << "Swapped elements at: " << i << " and " << j << "\n" ;
        // for ( int k = l ; k <= h ; k++ )
        //     cout << arr[k] << " " ;
        // cout << endl ;
    }

}

int main ()
{
    int arr[] = {5,3,8,4,2,7,1,10} ;

    int n = sizeof(arr)/sizeof(arr[0]) ;

    cout << "\n\nPivot is now at : " << partition(arr,0,n-1) << "\n\n" ;

    for ( int &x: arr )
        cout << x << " " ;
    cout << endl ;
}