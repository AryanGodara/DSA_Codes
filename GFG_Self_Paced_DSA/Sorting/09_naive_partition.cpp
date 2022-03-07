# include <bits/stdc++.h>
using namespace std ;

void partition ( int arr[] , int l , int h , int p )
{
    int temp[h-l+1] , index = 0 ;

    //? First, all elements <= arr[p], go to the left of the array
    for ( int i = l ; i <= h ; i++ )
        if ( arr[i] <= arr[p] && i != p )
            temp[index++] = arr[i] ;
    
    //? Then comes arr[p] itself
    temp[index++] = arr[p] ;

    //? Then, come all the remaining elements, that were > arr[p]
    for ( int i = l ; i <= h ; i++ )
        if ( arr[i] > arr[p] )
            temp[index++] = arr[i] ;
    
    //TODO: Put the values of temp[] back to arr, after they've been partitions around 'p'
    for ( int i = l ; i <= h ; i++ )
        arr[i] = temp[i-l] ;
}

// Driver Function
int main ()
{
    int arr[] = {5,14,6,9,12,11,8} ;

    int n = sizeof(arr)/sizeof(arr[0]) ;

    partition(arr,0,n-1,3) ;

    for ( int &x: arr )
        cout << x << " " ;
    cout << endl ;

    return 0 ;
}