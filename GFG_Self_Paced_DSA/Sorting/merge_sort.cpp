// MergeSort
# include <bits/stdc++.h>
using namespace std ;

void merge ( int arr[] , int l , int m , int h ) // Low , Mid / High
{
	int n1 = m-l+1 , n2 = h-m ; // The lengths of the two arrays
	int left[n1] , right[n2] ;	// Two arrays to be formed
	
	for ( int i = 0 ; i < n1 ; i++ )
		left[i] = arr[i+l] ;
	
	for ( int j = 0 ; j < n2 ; j++ )
		right[j] = arr[m+1+j] ;
	
	// These elements are copied into two temp arrays, which will be used to put these elements 
	// back in the original array, but this time in a sorted order

	int i = 0 , j = 0 , k = l ;	
	// k = starting point of inserting sorted elements back into the orignal array

	while ( i < n1 && j < n2 )
	{
		if ( left[i] <= right[i] )
			arr[k++] = left[i++] ;
		else
			arr[k++] = right[j++] ;
	}		// One partial array will be left at this points

	while ( i < n1 )		// In case, some elements of left array were left to be added
		arr[k++] = left[i++] ;
	while ( j < n2 )		// In case, some elements of right array were left to be added
		arr[k++] = right[j++] ;
}

void mergesort ( int arr[] , int l , int r )
{
	if ( r > l )	// There are at least two elements, otherwise there's nothing to sort
	{
		int m = (l+r) / 2 ;

		mergesort(arr,l,m) ;	// Recursive Call
		mergesort(arr,m+1,r) ;  // Recursive Ccall
		merge(arr,l,m,r) ;
	}
	// return ;	// Goes here directly, for 1 element arrays.
}

int main ()
{
	int arr[] = { 10 , 5 , 30 , 15 , 7 } ;
	int l = 0 , r = 4 ;

	mergesort( arr , l , r ) ;

	for ( int x : arr )
		cout << x << " " ;

	return 0 ;
}