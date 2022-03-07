# include <bits/stdc++.h>
using namespace std ;

int partition ( int arr[] , int l , int h )
{
    int pivot = arr[h] ;    //? Lomuto Partition
    int i = l-1 ;

    for ( int j = l ; j < h ; j++ )
        if ( arr[j] < pivot )
            swap(arr[++i],arr[j]) ;

    swap(arr[++i],arr[h]) ; //? Place the pivot at the correct position

    return i ;  //? Return the position of the pivot
}

int kthSmallest ( int arr[] , int n , int k )   //? Returns the index of the k'th smallest
{
    int l = 0 , r = n-1 ;

    while ( l <= r )   //? Code is kind of like Binary Search Code
    {
        int p = partition(arr,l,r) ;
        
        if ( p == k-1 ) //* The partition element is the k'th smallest
            return p ;
        else if ( p > k-1 ) //* The k'th smallest will be on the left side
            r = p-1 ;
        else                //* It's on the right side
            l = p+1 ;
    }

    return -1 ;
}

// Driver Function
int main ()
{
    int arr[] = {10,4,5,8,11,6,26} ;
    
    int n = sizeof(arr)/sizeof(arr[0]) ;
    int k = 5 ;

    int index = kthSmallest(arr,n,k) ;

    cout << index << " : " << arr[index] << endl ;

    return 0 ;
}

/*
* In the worst case, it takes O(N^2) time, which may seem worse than simply sorting the 
* array, and return arr[k-1]; which was O(NlogN).
* 
* But on average, it's faster than O(NlogN) (uses quicksort).
* 
* We could also use a maxheap of size k, and solve this in Nlog(K) time.
* 
*/