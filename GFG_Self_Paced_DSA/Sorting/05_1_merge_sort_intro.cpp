# include <bits/stdc++.h>
using namespace std ;

/*
? MERGE SORT :-
* 
* 1. Divide and Conquer Algorithm (Divide, Conquer, and Merge)
* 
* 2. Stable Algorithm
* 
? 3. Theta(NlogN) time ; O(N) auxillary space
* 
* 4. Well suited for linked lists. (Works in O(1) Auxillary Space)
* 
? 5. Used in External Sorting
* 
! 6. QuickSort outperforms MergeSort in general, for Arrays.
* 
*/


//? Naive Function to Merge to Sorted Arrays
void merge_naive ( int a[] , int b[] , int m , int n )
{
    int c[m+n] ;    // The resultant array, obtained after merging a[] and b[]

    for ( int i = 0 ; i < m ; i++ )
        c[i] = a[i] ;
    
    for ( int j = 0 ; j < n ; j++ )
        c[j+m] = b[j] ;

    sort (c,c+m+n) ;    // O((m+n)log(m+n))     //! Highly Inefficient

    for ( auto &x: c )
        cout << x << " " ;
    cout << endl ;
}


//? Efficient Function to Merge to Sorted Arrays
void merge_efficient ( int a[] , int b[] , int m , int n )
{
    int i = 0 , j = 0 ;

    while ( i < n && j < n)
    {
        if ( a[i] <= b[j] )
            cout << a[i++] << " " ;
        else
            cout << b[j++] << " " ;
    }

    while ( i < m )
        cout << a[i++] << " " ;
    while ( j < n )
        cout << b[j++] << " " ;

    cout << endl ;
}