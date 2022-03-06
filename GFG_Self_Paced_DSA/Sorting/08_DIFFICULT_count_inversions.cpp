//? Condition: arr[i] > arr[j] when i<j.

# include <bits/stdc++.h>
using namespace std ;

//TODO: Naive Approach (Simple O(N^2), check for each value of i and j)


//TODO: Efficient Approach :-
/*
* O(NlogN) time
* 
* We use the mergesort technique, ie, divide the array into two halves and sort these two
* halves recursively. Then, we merge these two halves.
* 
* But, in this version, we count inversions while we're sorting the array.
* We count inversions in the left and right half. And then we are merging, we count inversions
* when one element is from the left half, and the other one is from the right half.
* 
* Every Inversion (x,y) where x>y has the following possibilities :-
* 
* (a) Both x and y are in left half
* (b) Both x and y are in right half
* (c) x is in left half and y is in right half
* 
*/

int count_and_merge ( int a[] , int l , int m , int r )
{
    int n1 = m-l+1 , n2 = r-m ;

    int left[n1] , right[n2] ;

    for ( int i = 0 ; i < n1 ; i++ )
        left[i] = a[l+i] ;
    for ( int j = 0 ; j < n2 ; j++ )
        right[j] = a[m+j+1] ;
    
    //? It's the same upto this point, with an extra variable 'res' (no of inversions)
    int res = 0 , i = 0 , j = 0 , k = l ;

    //TODO: Go through the right array, for each element y in the left array, count the no. of
    //TODO: elements in the left array, say x, such that x>y, this is the no. of inversions
    //TODO: due to x>y , then move on to the next element in right array, do this until you've
    //TODO: gone through all the options.

    while ( i < n1 && j < n2 )
    {
        if ( left[i] <= right[j] )
        {
            a[k++] = left[i++] ;  //  Simple merge function
            //? No need to add to 'res' here, as this is not an "inversion"
        }
        else    //? This is an inversion now, as right[j] < left[i], in the merged array
        {
            a[k++] = right[j++] ;

            res += (n1-i) ;
            //* All elements to the right of left[i], will also be greater than right[j]
            //* So, we don't need to loop through each of them, instead we move forward
            //* in the right array.
        }
    }

    //? These steps also remain the same, as 
    //* 1. No element left in right[], so all the current left[i] elements are larger 
    //*    and we've already taken them into account.
    //* 2. No element left in left[], so all of them were smaller than the elements in right[]
    //*    and there were no more inversions to count.

    while ( i < n1 )
        a[k++] = left[i++] ;
    while ( j < n2 )
        a[k++] = right[j++] ;

    return res ;
    //? merge function is no longer "void", it returns the no. of inversions as well now.
}

int count_inversions ( int arr[] , int l , int r )
{
    int res = 0 ;

    if ( l < r )
    {
        int m = l + (r-l)/2 ;

        res += count_inversions(arr,l,m) ;      // Recursively Count for Left Half
        res += count_inversions(arr,m+1,r) ;    // Recursively Count for Right Half

        res += count_and_merge(arr,l,m,r) ;     // Merge the two halves, and count the answer
    }

    return res ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cout.tie(NULL) ;

    int arr[] = {2,4,1,3,5} ;

    int n = sizeof(arr)/sizeof(arr[0]) ;

    cout << count_inversions(arr,0,n-1) << endl ;

    return 0 ;
}