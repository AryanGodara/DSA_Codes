//? O(N+k) time to sort n elements in the range from 0 to k-1 :- [0,k-1]
//* Lineary Time sorting algorithm (but for relatively smaller range of elements)

# include <bits/stdc++.h>
using namespace std ;

void naive_count_sort ( int arr[] , int n , int k)
{
    int count[k] = {0} ;

    for ( int i = 0 ; i < n ; i++ )
        count[arr[i]]++ ;
    
    int index =  0 ;
    for ( int i = 0 ; i < k ; i++ ) // For each element from 0 to k-1
        for ( int j = 0 ; j < count[i] ; j++ ) // Place it as many times as it appears in 'arr'
            arr[index++] = i ;
}

//? Efficient, General Purpose
void count_sort ( int arr[] , int n , int k )
{
    int count[k] = {0} ;

    for ( int i = 0 ; i < n ; i++ )
        count[arr[i]]++ ;

    for ( int i = 1 ; i < k ; i++ )
        count[i] += count[i-1] ;    // Presum type technique
    
    int output[n] ;

    // Initially, count[arr[n-1]] == n (total no. of elements in the original array)
    for ( int i = n-1 ; i >= 0 ; i-- )
    {
        output[ count[arr[i]]-1 ] = arr[i] ;
        count[arr[i]]-- ;   // Decrease the count, each time we place an element
    }

    for ( int i = 0 ; i < n ; i++ ) // Copy the sorted elements back to the original array
        arr[i] = output[i] ;
}

//? Driver Function
int main ()
{
    int arr[] = {1,4,4,1,0,1} ;

    int n = sizeof(arr)/sizeof(arr[0]) ;

    int k = 5 ;

    count_sort(arr,n,k) ;

    for ( int i = 0 ; i < n ; i++ )
        cout << arr[i] << " " ;
    cout << endl ;

    return 0 ;
}