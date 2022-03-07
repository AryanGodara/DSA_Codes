# include <bits/stdc++.h>
using namespace std ;

//? Returns the new index of the pivot element after partitioning the array
int iPartition ( int arr[] , int l , int h )
{
    int pivot = arr[h] ;    //* Last element is taken as the pivot
    int i = l-1 ;

    for ( int j = l ; j < h ; j++ )
        if ( arr[j] < pivot )
            swap(arr[j],arr[++i]) ;
    
    swap(arr[++i],arr[h]) ;

    return i ;  //* Return the position of the 'pivot' element
}

//? Sorts the two halves of the array, after it's partitioned
void quicksort ( int arr[] , int l , int h )
{
    if ( l < h )
    {
        int p = iPartition(arr,l,h) ;
       
        //TODO: Now that we have the position of the pivot, all elements on the left are
        //TODO: Shorter than the pivot, and all elements on the right are greater than it.

       
        //TODO: So, we call quicksort for these two havles of the array
        quicksort(arr,l,p-1) ;
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