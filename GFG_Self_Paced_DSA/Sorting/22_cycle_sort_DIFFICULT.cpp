/*
* 
! A worst case O(N^2) Sorting Algorithms
* 
? Does minimum memory writes and can be useful for cases where write is costly
* 
* In-Place
! Not Stable
* 
* Useful to solve questions like find minimum swaps to sort an array
* 
*/

# include <bits/stdc++.h>
using namespace std ;

//TODO: For each element, we count the number of elements, < to the current number

void cycle_sort_distinct ( int arr[] , int n )  //! Only for distinct elements
{
    //? As we move along with cs, all elements before 'cs' position are sorted.
    //! But the elements to the right of 'cs' may not be sorted
    for ( int cs = 0 ; cs < n-1 ; cs++ )
    {
        int item = arr[cs] ;
        int pos = cs ;

        for ( int i = cs+1 ; i < n ; i++ )  //? No. of elements after cur, that are < cur
            if ( arr[i] < item )
                pos++ ; 

        swap ( item , arr[pos] ) ;  //? Place item at the correct pos ; item = previous arr[pos] 

        while ( pos != cs )
        {
            pos = cs ;  //* Repeat above step for the element that took "item's" place above.

            for ( int i = cs+1 ; i < n ; i++ )
                if ( arr[i] < item )
                    pos++ ;
            
            swap ( item , arr[pos] ) ;
        }
    }
}

//? Driver Function
int main ()
{
    int arr[] = {20,40,50,10,30} ;
    int n = sizeof(arr)/sizeof(arr[0]) ;

    cycle_sort_distinct(arr,n) ;

    for ( int i = 0 ; i < n ; i++ )
        cout << arr[i] << " " ;
    cout << endl ;

    return 0 ;
}