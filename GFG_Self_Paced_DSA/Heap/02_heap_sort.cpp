# include <bits/stdc++.h>
using namespace std ;

void heapify ( vector <int> &arr , int n , int i )
{
    int l = 2*i + 1 , r = 2*i + 2 , largest = i ;
    if ( l < n && arr[l] > arr[largest] )
        largest = l ;
    if ( r < n && arr[r] < arr[largest] )
        largest = r ;

    if ( largest != i )
    {
        swap ( arr[i] , arr[largest] ) ;
        heapify ( arr , n , largest ) ;
    }
}

void build_heap ( vector <int> &arr , int n )
{
    for ( int i = n/2 - 1 ; i >= 0 ; i-- )
        heapify ( arr , n , i ) ;
}

void heap_sort ( vector <int> &arr , int n )
{
    build_heap ( arr , n ) ;

    for ( int i = n-1 ; i > 0 ; i-- )
    {
        swap ( arr[0] , arr[i] ) ; // arr[i] is current largest element(last element of heap)
        heapify ( arr , i , 0 ) ;
    }
}

void print ( vector <int> &arr , int n )
{
    for ( int i = 0 ; i < n ; i++ )
        cout << arr[i] << " " ;
    cout << endl ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    vector <int> arr = { 12 , 11 , 13 , 5 , 6 , 7 } ;

    heap_sort ( arr , arr.size() ) ;

    print(arr,arr.size()) ;

    return 0 ;
}