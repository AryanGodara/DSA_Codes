/*
* 
? The important examples of 'Array with two types of elememts' :-
* 
? 1. Segregate positive and negative 
* 
! I/P arr[] = {15,-3,-2,18}
* O/P arr[] = {-3,-2,15,18}
* 
? 2. Segregate even and odd
* 
! I/P arr[] = {15,14,13,12}
* O/P arr[] = {14,12,15,13}
* 
? 3. Sort a binary array
* 
! I/P arr[] = {0,1,1,1,0}
* O/P arr[] = {0,0,1,1,1}
* 
*/

# include <bits/stdc++.h>
using namespace std ;

//TODO: Naive Solution, is just traversing the array twice, and putting the elements in a
//TODO: temporary array, and return the temp array as the solution. O(2N)

//? Efficient Approach :-
//TODO: Simply use hoarse partition to partition the array, while taking the pivot as '0'
//TODO: for positive negative, arr[x]&1 bool value for even odd, and 0 or 1, for binary sort.

void sort ( int arr[] , int n )
{
    int i = -1 , j = n ;

    while ( true )
    {
        do { i++ ; } while ( arr[i] < 0 ) ;
        do { j-- ; } while ( arr[j] >= 0 ) ;

        if ( i >= j )
            return ;
        else
            swap(arr[i],arr[j]) ;
    }
}

int main ()
{
    int arr[] = {13,-12,18,10} ;
    
    int n = sizeof(arr)/sizeof(arr[0]) ;

    sort (arr,n) ;

    for ( int &x: arr )
        cout << x << " " ;

    return 0 ;
}