//? Does less memory write compared to other sorting algorithms like Quicksort, MergeSort,
//? InsertionSort, etc.
//? But this isn't optimal in terms of memory writes, unlike "Cycle Sort" which is.
//* Example: When we're writing data to the hard disk, memory writes can be very costly
//? The Basic Idea for HeapSort (HS uses heap DS to optimize the selection sort idea)
//! Not Stable (Order of equal-value elements may change)
//? In place sorting (Not extra memory required)

# include <bits/stdc++.h>
using namespace std ;

//TODO: In each run from i to n-1, we find the smallest element, and at the end of the 
//TODO: iteration we swap the highest element with the i'th element, then do i++, to move on
//TODO: to the next iteration. (We can do the same, for greatest element also)

// Sorting Function
void selection_sort ( vector <int> &arr, int n )
{
    for ( int i = 0 ; i < n ; i++ )
    {
        int mn = i ;
        for ( int j = i ; j < n ; j++ )
        {
            if ( arr[j] < arr[mn] )
                mn = j ;
        }
        swap(arr[i],arr[mn]) ;  //* Only one swap per i, unlike bubble sort.
    }
}

// Driver Function
int main ()
{
    vector <int> arr = {10,5,7,20,2,18} ;
    int n = arr.size() ;

    selection_sort(arr,n) ;

    for ( auto &x: arr )
        cout << x << " " ;
    cout << endl ;

    return 0 ;
}