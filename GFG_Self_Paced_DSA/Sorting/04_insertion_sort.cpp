//* In-Place and Stable
//? Used in Practice for small ararys (TimSort and IntroSort)
/*
    TimSort in as algorithm used by Python.
    TimSort typically uses mergesort algorithm to sort the array, but during mergesort
    when the individual arrays become small, it switches to insertion sort to sort them.
    ? Insertion Sort is most preferred algorithm for short array inputs

    IntroSort uses HeapSort, QuickSort and InsertionSort.
*/
//! O(n^2) in Worst Case        (When the input array is reversed sorted)
//* O(n) is Best Case           (When the input array is already sorted)

# include <bits/stdc++.h>
using namespace std ;

//TODO: Look up the video again :P
//TODO: But the basic idea is that as we move from i = 0 to n-1, at each step, we make sure
//TODO: that the subarray from 0-i is already sorted. And on each step, we perform operations
//TODO: such that, as the size of this "sorted subarray" increases, it remains sorted

void insertion_sort ( vector <int> &arr , int n )
{
    for ( int i = 1 ; i < n ; i++ ) // No need for i=0, as 1 element array is already sorted
    {
        int key = arr[i] ;
        int j = i-1 ;
        while ( j >= 0 && arr[j] > key )    //! arr[j]<key (will sort the array in descending)
        {
            arr[j+1] = arr[j] ;
            j-- ;
        }
        arr[j+1] = key ;
    }
}

// Driver Function
int main ()
{
    vector <int> arr = {20,5,40,60,10,30} ;
    int n = arr.size() ;

    insertion_sort(arr,n) ;

    for ( auto &x: arr )
        cout << x << " " ;
    cout << endl ;

    return 0 ;
}