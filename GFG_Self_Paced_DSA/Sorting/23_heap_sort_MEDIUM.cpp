# include <bits/stdc++.h>
using namespace std ;

//? Basic Idea of Heap Sort is based on Selection Sort algorithm (we find the max element)
//? and swap it with the last element. But instead of using linear search to find the greatest
//? element (like selection sort); heap sort uses the heap data structure, to do this in 
//? O(logN) time instead. 

void heapify ( int arr[] , int n , int i )
{
    int largest = i , l = 2*i + 1 , r = 2*i + 2 ;   //* Parent, left child, right child

    //* Find the larger of the three points
    if ( l < n && arr[l] > arr[largest] )
        largest = l ;
    if ( r < n && arr[r] > arr[largest] )
        largest = r ;

    if ( largest != i )
    {
        swap ( arr[i] , arr[largest] ) ;
        //* Now, i may not be at the correct position
        heapify(arr,n,largest) ;    //* So, we heapify that position
    }
}

void build_heap ( int arr[] , int n )   //? Create a max heap
{
    for ( int i = n/2 - 1 ; i >= 0 ; i-- )
        heapify(arr,n,i) ;
}

//? The main sorting function
void heap_sort ( int arr[] , int n )
{
    build_heap (arr,n) ;    // TODO: First, convert the array into a heap

    for ( int i = n-1 ; i >= 0 ; i-- )
    {
        swap( arr[0] , arr[i]) ;
        heapify(arr,i,0) ;
    }
}

void print_array ( int arr[] , int n )
{
    for ( int i = 0 ; i < n ; i++ )
        cout << arr[i] << " " ;
    cout << endl ;
}

//? Driver Function
int main ()
{
    int arr[] = {12,11,13,5,6,7} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    heap_sort(arr,n) ;

    cout << "Sorted array is : \n" ;

    print_array(arr,n) ;

    return 0 ;
}