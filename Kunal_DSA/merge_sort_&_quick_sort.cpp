# include <bits/stdc++.h>
using namespace std ;

void merge ( vector <int> &nums , int beg , int mid , int end )
{
    vector <int> newarr (end-beg) ;

    int i = beg , j = mid , k = 0 ;     // k = first index of the newly formed 'newarr'
    // i = first index of first half, j = first index of the second half

    while ( i < mid-beg && j < end-mid )
    {
        if ( nums[i] < nums[j] )
            newarr[k++] = nums[i++] ;
        else
            newarr[k++] = nums[j++] ;
    }

    while ( i < mid-beg )
        newarr[k++] = nums[i++] ;
    
    while ( j < end-mid )
        newarr[k++] = nums[j++] ;

    for ( i = 0 ; i < k ; i++ )
        nums[beg+i] = newarr[i] ;
}

void merge_sort ( vector <int> & nums , int beg , int end )
{
    if ( end - beg <= 1 )   // Nothing to sort 
        return ;
    
    int mid = beg + (end-beg)/2 ;

    // Sort the two halves
    merge_sort ( nums , beg , mid ) ;
    merge_sort ( nums , mid+1 , end ) ;

    // Merge the two sorted halves
    merge ( nums , beg , mid , end ) ;
}

void quick_sort ( vector <int> &arr , int beg , int end )
{
    // Base Case
    if ( beg >= end )   // 1 or 0 elements ; or an invalid call
        return ;

    int s = beg , e = end , m = s + (e-s)/2 , pivot = arr[m] ; // Taking middle element as pivot

    while ( s <= e )
    {
        // Also a reason why, it will not swap, if the subarray is already sorted
        while ( arr[s] < pivot )
            s++ ;
        while ( arr[e] > pivot )
            e-- ;
        
        // A this point, both s and e violate the condition
        if ( s <= e )   // Check this first, to see if we have
            swap ( arr[s++],arr[e--] ) ;   // Sort by reference
    }

    // At thsi point, the pivote is at the correct position, ie., all the elements on the LHS of
    // the pivot are smaller than the pivot, and all the elements on its RHS are greater than it.
    
    // Now, we recursively call quicksort for the LHS and RHS
    quick_sort( arr , beg , e ) ;
    quick_sort( arr , s , end ) ;
}

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    vector <int> arr = { 5 , 4 , 3 , 2 , 1 } ;

    quick_sort ( arr , 0 , arr.size()-1 ) ;

    for ( auto &x : arr )
        cout << x << " " ;
    cout << endl << endl ;

    /*********************************************/

    vector <int> nums = { 5 , 4 , 3 , 2 , 1 } ;

    quick_sort ( nums , 0 , nums.size()-1 ) ;

    for ( auto &x : nums )
        cout << x << " " ;
    cout << endl ;


    return 0 ;
}