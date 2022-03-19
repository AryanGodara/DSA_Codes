//TODO: Return the length of the longest subarray with equal number of zeroes and ones.

# include <bits/stdc++.h>
using namespace std ;

int largest_subarr ( vector <int> &arr , int n )
{
    for ( int i = 0 ; i < n ; i++ )
        arr[i] = ( !arr[i] ? -1 : 1) ;
    
    //* Now, we just need to find the longest subarray with sum == 0

    unordered_map <int,int> mp ;

    int res = 0 , presum = 0 ;

    // for ( int i = 0 ; i < n ; i++ )
    // {
    //     presum += arr[i] ;

    //     if ( presum == 0 )
    //         res = i+1 ;
        
    //     if ( mp.find(presum) == mp.end() )
    //         mp.insert({presum,i}) ;
        
    //     else if ( mp.find(presum-0) != mp.end() ) // We found a subarray
    //         res = max ( res , i - mp[presum-0] ) ;
    // }

    for ( int i = 0 ; i < n ; i++ )
    {
        presum += arr[i] ;

        if ( presum == 0 )
            res = i+1 ;
        
        if ( mp.find(presum+n) != mp.end() )
            res = max ( res , i - mp[presum+n] ) ;
        else
            mp.insert({presum+n,i}) ;
    }

    return res ;
}