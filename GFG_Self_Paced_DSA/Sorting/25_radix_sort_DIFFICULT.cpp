//? Utilizes counting sort
//* Radix sort takes linear time even for a range of k = n^2 or even k = n^3

# include <bits/stdc++.h>
using namespace std ;

void counting_sort ( int arr[] , int n , int exp )
{
    int output[n] ;
    
    int count[10] = {0} ;

    for ( int i = 0 ; i < n ; i++ )
        count[ (arr[i]/exp) % 10 ]++ ;
    
    for ( int i = 1 ; i < 10 ; i++ )
        count[i] += count[i-1] ;    // Presum type technique

    for ( int i = n-1 ; i >= 0 ; i-- )
    {
        output[ count[(arr[i]/exp) % 10] - 1 ] = arr[i] ;
        count[ (arr[i]/exp) % 10 ] -- ;     //! if exp > arr[i] , whole thing = 0 ;
        //? (arr[i]/exp % 10)  replaces  arr[i]
        //* arr[i]/exp % 10  == exp'th digit of arr[i], ranging from 1st to last (from right)
    }

    for ( int i = 0 ; i < n ; i++ )
        arr[i] = output[i] ;
}

void radix_sort ( int arr[] , int n )
{
    int mx = arr[0] ;   // Find the maximum element of the array
    for ( int i = 1 ; i < n ; i++ )
        mx = max ( mx , arr[i] ) ;

    //? Going from rightmost (ones) digit to the max possible digit of the maximum character
    for ( int exp = 1 ; mx/exp > 0 ; exp *= 10 ) // exp = no. of digits
        counting_sort(arr,n,exp) ; //TODO: Sort elements acc. to their exp 'th digit from right
}

int main ()
{
    int arr[] = {319,212,6,8,100,50} ;

    int n = sizeof(arr)/sizeof(arr[0]) ;

    radix_sort(arr,n) ;

    for ( int i = 0 ; i < n ; i++ )
        cout << arr[i] << " " ;
    cout << endl ;

    return 0 ;
}