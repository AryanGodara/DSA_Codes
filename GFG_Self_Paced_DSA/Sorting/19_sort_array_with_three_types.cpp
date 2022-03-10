/*
* 
? The important examples of 'Array with three types of elememts' :-
* 
? 1. Sort an array of 0s, 1s and 2s 
* 
! I/P arr[] = {0,1,0,2,1,2}
* O/P arr[] = {0,0,1,1,2,2}
* 
? 2. Three-way partitioning when multiple occurences of a pivot may exist
* 
! I/P arr[] = {2,1,2,20,2,20,1} , pivot = 2
* O/P arr[] = {1,1,2,2,2,20,20}
* 
? 3. Partitioning around a range
* 
! I/P arr[] = {10,5,6,3,20,9,40} , range = [5,10]
* O/P arr[] = {3,5,6,9,10,20,4}
* 
*/

# include <bits/stdc++.h>
using namespace std ;

//? Dutch National Flag Algorithm (Variation of Hoare's Partition Algorithm)

//! Takes O(N) times, don't confuse with O(NlogN) binary search, due to presence of 'mid' index

void sort ( int arr[] , int n )
{
    int l = 0 , h = n-1 , mid = 0 ;

    while ( mid <= h )  
    {
        switch ( arr[mid] )
        {
            case 0: 
                swap ( arr[l++] , arr[mid++] ) ;
                break ;
            
            case 1:
                mid++ ;
                break ;
            
            case 2:
                swap ( arr[mid] , arr[h--] ) ;
                break ;
        }
    }
}

int main ()
{
    int arr[] = {0,1,1,2,0,1,1,2} ;

    int n = sizeof(arr)/sizeof(arr[0]) ;

    sort (arr,n) ;

    for ( int &x: arr )
        cout << x << " " ;
    cout << endl ;

    return 0 ;
}