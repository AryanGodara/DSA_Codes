//? Merge Function of MergeSort

# include <bits/stdc++.h>
using namespace std ;

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

// Driver Function
int main ()
{
    //? This is an example, so assume, we have already sorted all the smaller subarrays,
    //? and now, we only have to sort the complete array, by mergin together the two sorted
    //? halves. (m is the index after which array is sorted, and upto which array is sorted)

    //TODO: So, we need to merge these to parts, to form a completely sorted array

    int arr[] = {10,15,20,40,8,11,15,22,25};
    int l = 0 , h = 8 , m = 3 ;

    merge(arr,l,m,h) ;

    for ( int &x: arr )
        cout << x << " " ;
    cout << endl ;

    return 0 ;
}