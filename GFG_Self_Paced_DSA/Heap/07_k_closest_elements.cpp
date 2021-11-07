# include <bits/stdc++.h>
using namespace std ;

// We are given an array, a number x, and a number k.
// We need to find the k closest elements to x present in the array

// Efficient Solution
void k_closest ( vector <int> &arr , int x , int k )
{
    priority_queue< pair<int,int> > pq ;    // Can't make a min_heap for pairs lol

    for ( int i = 0 ; i < arr.size() ; i++ )
        pq.push ( {-abs(x-arr[i]),i} ) ;    // So, storing the elements in -ve forms
    
    for ( int i = 0 ; i < k ; i++ )
    {
        cout << arr[pq.top().second] << " " ;
        pq.pop() ;
    }
    cout << endl ;
}

// GFG approach for Efficient Solution
void print_k_closest (vector <int> &arr , int x , int k)// Prints elements in decreasing order
{
    priority_queue < pair<int,int> > pq ;   // Max Heap

    for ( int i = 0 ; i < k ; i++ )
        pq.push ( { abs(x-arr[i]) , i } ) ;

    for ( int i = k ; i < arr.size() ; i++ )
    {
        int diff = abs ( arr[i] - x ) ;
        if ( pq.top().first > diff )    // This element needs to be replaced
        {
            pq.pop() ;
            pq.push( { abs(x-arr[i]) , i } ) ;
        }
    }

    while ( !pq.empty() )
    {
        cout << arr[ pq.top().second ] << " " ;
        pq.pop() ;
    }
    cout << endl ;
}

// Naive Solution
void naive_k_closest ( vector <int> &arr , int x , int k )  // T = O(N.K)
{
    int n = arr.size() ;
    vector <bool> visited(n,false) ;

    for ( int i = 0 ; i < k ; i++ ) // We have to find k numbers
    {
        int min_diff = INT_MAX , min_diff_index ;

        for ( int j = 0 ; j < n ; j++ ) // Traverse the entire array for each iteration
        {
            if ( !visited[j] && abs(arr[j]-x)<=min_diff )
            {
                min_diff = abs ( arr[j] - x ) ;
                min_diff_index = j ;
            }
        }
        cout << arr[min_diff_index] << " " ;
        visited[min_diff_index] = true ;
    }
    cout << endl ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    vector <int> arr1 = {10,15,7,3,4} , arr2 = {100,80,10,5,70} , arr3 = {20,40,5,100,150} ;
    int x1 = 8 , k1 = 2 , x2 = 2 , k2 = 3 , x3 = 100 , k3 = 3 ;

    k_closest(arr1,x1,k1) ;
    k_closest(arr2,x2,k2) ;
    k_closest(arr3,x3,k3) ;

    cout << endl ;
    
    naive_k_closest(arr1,x1,k1) ;
    naive_k_closest(arr2,x2,k2) ;
    naive_k_closest(arr3,x3,k3) ;

    cout << endl ;
    
    print_k_closest(arr1,x1,k1) ;
    print_k_closest(arr2,x2,k2) ;
    print_k_closest(arr3,x3,k3) ;

    return 0 ;
}