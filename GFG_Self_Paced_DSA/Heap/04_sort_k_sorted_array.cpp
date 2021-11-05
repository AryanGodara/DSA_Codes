# include <bits/stdc++.h>
using namespace std ;

// A k-sorted array, is an array that is 'almost' sorted. In the k-sorted array :-
// An element at index i will be presented between the indexes i-k to i+k in the sorted array.
// This array can be sorted in (N)log(K) time, instead of Nlog(N)
// If we want to sort in increasing order, we use min heap, else we use max heap.

void sort_k_sorted ( vector<int> &arr , int n , int k )
{
    priority_queue < int , vector<int> , greater<int> > pq ;    // Min Heap
    // Default binary heap in C++ is max heap for some reason

    for ( int i = 0 ; i <= k ; i++ )    // Put the first k+1 elements in the min heap
        pq.push(arr[i]) ;
    
    int index = 0 ; // Index where the cur 'correctly sorted' element needs to be placed

    for ( int i = k+1 ; i < n ; i++ )   
    {
        // Adding the remaining elements, to the heap, after we place each min element from
        // the heap in each step, and place it at its correct position in the sorted array.

        arr[index++] = pq.top() ;   // Place the smallest element in the min heap, in 'arr'
        pq.pop() ;  // Now, remove this root element from the min_heap
        pq.push(arr[i]) ;   // Add the new element to the min heap
    }

    // Now more elements to add now, so just keep placing the root (minimum) element from the
    // heap into the sorted array, and then keep updating the min_heap (done automatically).
    while ( !pq.empty() )
    {
        arr[index++] = pq.top() ;
        pq.pop() ;
    }
}

int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;

    vector<int> arr1 = { 9 , 8 , 7 , 19 , 18 } ;

    sort_k_sorted ( arr1 , 5 , 2 ) ;     // k = 2

    for ( auto &x : arr1 )
        cout << x << " " ;
    cout << endl ;

    vector <int> arr2 = { 10 , 9 , 7 , 8 , 4 , 70 , 50 , 60 } ;     // k = 4

    sort_k_sorted ( arr2 , 8 , 4 ) ;

    for ( auto &x : arr2 )
        cout << x << " " ;
    cout << endl ;

    return 0 ;
}