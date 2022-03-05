//? Complete Implementation of the MergeSort Algorithm

# include <bits/stdc++.h>
using namespace std ;

//? Helper function to merge to sorted subarrays
void merge ( int arr[] , int l , int m , int h )
{
    int n1 = m-l+1 , n2 = h-m ; // Divide the array into two halves

    int left[n1] , right[n2] ;  // Make two new arrays (temporary)

    for ( int i = 0 ; i < n1 ; i++ )    // Store half of the elements in left array
        left[i] = arr[i+l] ;    // From l to l+n1-1
    for ( int j = 0 ; j < n2 ; j++ )    // And store the rest in right array
        right[j] = arr[m+j+1] ; // From m+1 to m+n2

    //? Now, we have two sorted arrays left[] and right[]
    //TODO: we just need to merge them now    
    
    int i = 0 , j = 0 , k = l ;

    while ( i < n1 && j < n2 )
    {
        if ( left[i] <= right[j] )
            arr[k++] = left[i++] ;
        else
            arr[k++] = right[j++] ;
    }
    
    while ( i < n1 )
        arr[k++] = left[i++] ;

    while ( j < n2 )
        arr[k++] = right[j++] ;

}

//? Sorting Function
void merge_sort ( int arr[] , int l , int r )   // Recursive Function
{
    if ( r > l )    //? Base case if (l==r) : there's only 1 element in subarray (already sorted)
    {
        int m = l + (r-l)/2 ;

        merge_sort(arr,l,m) ;   // Recursively sort the left half
        merge_sort(arr,m+1,r) ; // Recursively sort the right half

        merge(arr,l,m,r) ;  // Merge these two halves
    }
}

//? Driver Function
int main ()
{
    int a[] = {10,5,30,15,7} ;

    int l = 0 , r = 4 ; // 1st and last element

    merge_sort(a,l,r) ;

    for ( int &x: a )
        cout << x << " " ;
    cout << endl ;
}