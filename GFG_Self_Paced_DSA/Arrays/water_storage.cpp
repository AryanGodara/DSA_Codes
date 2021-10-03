# include <bits/stdc++.h>
using namespace std ;

// The naive solution, brute-force approach, O(n^2)
/*
int main () 
{
    int n ;
    cin >> n; 
    vector <int> arr(n) ;
    
    for ( int i = 0 ; i < n ; i++ )
        cin >> arr[i] ;
    
    int res = 0 ;

    // For each element, we find how much water will be stored over it
    // We find the max heights on its left and right side, and the value of water that it can store
    // is the min(lmax,rmax)-arr[i]. 

    for ( int i = 1 ; i < n-1 ; i++ )
    {
        int lmax = arr[i] ;
        for ( int j = 0 ; j < i ; j++ )
            lmax = max(lmax,arr[j]) ;
        
        int rmax = arr[i] ;
        for ( int j = i+1 ; j < n ; j++ )
            rmax = max(rmax,arr[j]) ;

        res += ( min(lmax,rmax) - arr[i] ) ;
    }
    
    cout << res << endl ;
    
    return 0 ;
}
*/

// Efficient Approach, O(n)
// The idea is to precompute the lmax and rmax by using two pre-arrays.
// Rest of the approach remains the same

int main ()
{
    int n ;
    cin >> n; 
    vector <int> arr(n) ;
    
    for ( int i = 0 ; i < n ; i++ )
        cin >> arr[i] ;
    
    int res = 0 ;
    vector <int> lmax(n,0) , rmax(n,0) ;

    lmax[0] = arr[0] ; 
    rmax[n-1] = arr[n-1] ;

    for ( int i = 1 ; i < n ; i++ )
        lmax[i] = max(arr[i],lmax[i-1]) ;
    // The max value,is either the same as the previous one, or equal to the current element

    for ( int i = n-2 ; i >= 0 ; i-- )
        rmax[i] = max(arr[i],rmax[i+1]) ;
    // The max value,is either the same as the previous one, or equal to the current element

    for ( int i = 1 ; i < n-1 ; i++ )   // No water is stored on the first and last elements
    {
        res += ( min(rmax[i],lmax[i]) - arr[i] ) ;
    }

    cout << res << endl ;

    return 0 ;
}