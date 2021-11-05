# include <bits/stdc++.h>
using namespace std ;

// Prints the 'k largest' elements of an array in an increasing order
void k_largest ( vector <int> &arr , int n , int k )
{
    priority_queue < int , vector<int> , greater<int> > min_heap ;

    for ( int i = 0 ; i < k ; i++ ) // Put k elements in the binheap
        min_heap.push(arr[i]) ;
    
    for ( int i = k ; i < n ; i++ ) // Check if the remaining elements belong in the heap
    {
        if ( min_heap.top() > arr[i] )  // This element is fine
            continue ;
        else
        {
            min_heap.pop() ;    // Remove the smallest element from the heap
            min_heap.push(arr[i]) ; // Replace it with a larger element
        }
    }

    // Print all the elements of the heap // These are the k largest elements of the array
    while ( !min_heap.empty() )
    {
        cout << min_heap.top() << " " ;
        min_heap.pop() ;
    }
    cout << endl ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    vector <int> arr = { 11 , 3 , 2 , 1 , 15 , 5 , 4 , 45 , 88 , 96 , 60 , 45 } ;
    int k = 3 ;

    k_largest ( arr , arr.size() , k ) ;

    return 0 ;
}