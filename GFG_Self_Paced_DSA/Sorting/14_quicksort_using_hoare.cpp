# include <bits/stdc++.h>
using namespace std ;

//? Returns the index of the "last element of left array" after partitioning the array
int iPartition ( int arr[] , int l , int h )
{
    int pivot = arr[l] ;    //* The first element is taken as the pivot
    int i = l-1 , j = h+1 ;

    while (true) {
        do { i++ ; } while ( arr[i] < pivot ) ;
        do { j-- ; } while ( arr[j] > pivot ) ;

        if ( i >= j )
            return j ;
        // Else
        swap(arr[i],arr[j]) ;
    }
}

//? Sorts the two halves of the array, after it's partitioned
void quicksort ( int arr[] , int l , int h )
{
    if ( l < h )    // if l==h, array is already sorted
    {
        int p = iPartition(arr,l,h) ;
       
        //TODO: Now that we have the position of the pivot, all elements on the left are
        //TODO: Shorter than the pivot, and all elements on the right are greater than it.

       
        //TODO: So, we call quicksort for these two havles of the array
        quicksort(arr,l,p) ;
        quicksort(arr,p+1,h) ;
    }
}

// Driver Function
int main ()
{
    int arr[] = {8,4,7,9,3,10,5} ;

    int n = sizeof(arr)/sizeof(arr[0]) ;

    quicksort(arr,0,n-1) ;

    for ( int &x: arr )
        cout << x << " " ;
    cout << endl ;

    return 0 ;
}