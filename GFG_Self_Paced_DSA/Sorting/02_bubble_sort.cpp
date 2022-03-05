# include <bits/stdc++.h>
using namespace std ;

//? This is a stable sorting algorithm

void print ( vector<int> &arr )
{
    for ( auto &x: arr )
        cout << x << " " ;
    cout << endl ;
}

void sort_naive ( vector <int> arr , int n )
{

//TODO: On each step from i = 0 to i = n-1, we look at adjacent elements, and swap them to 
//TODO: the correct position. So, by the end, the maximum element is at the rightmost valid
//TODO: position. This way, the last element gets placed at n-1, n-2, ..., 1, 0 : finally
//TODO: sorting the entire array.

    for ( int i = 0 ; i < n ; i++ )
        for ( int j = 0 ; j < n-i-1 ; j++ )
            if ( arr[j] > arr[j+1] )
                swap(arr[j],arr[j+1]) ;

    print(arr) ;
}

void sort_efficient ( vector <int> arr , int n )
{
    //TODO: We simply use a bool flag variable, to check if we sorted even once, for each
    //TODO: value of i from 0 to n-1. This may be more efficient, if the array gets sorted
    //TODO: before reaching i = n, so we'll save some time, by not iterating over the array
    //TODO: after it has already been sorted.

    for ( int i = 0 ; i < n ; i++ )
    {
        bool flag = true ;
        for ( int j = 0 ; j < n-i-1 ; j++ )
            if ( arr[j] > arr[j+1] )
            {
                swap(arr[j],arr[j+1]) ;
                flag = false ;
            }
        if (flag)   // No swaps occured
            break ;
    }

    print(arr) ;
}

// Driver Function
int main ()
{
    vector <int> arr = {2,1,3,4} ;
    int n = arr.size() ;

    sort_naive(arr,n) ;

    cout << "\n" ;
    
    sort_efficient(arr,n) ;

    return 0 ;
}