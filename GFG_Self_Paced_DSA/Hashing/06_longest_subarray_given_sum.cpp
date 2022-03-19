//? Return the length of the longest subarray with given sum.

# include <bits/stdc++.h>
using namespace std ;

int largest_subarray ( vector <int> &arr , int n , int sum )
{
    int prefix_sum = 0 , res = 0 ;
    
    unordered_map<int,int> mp ; // prefix_sum , ending_index of this prefix_sum

    for ( int i = 0 ; i < n ; i++ )
    {
        prefix_sum += arr[i] ;

        if ( prefix_sum == sum ) // This HAS to be the longest subarray yet
            res = i+1 ;
        
        if ( mp.find(prefix_sum) == mp.end() ) // Occuring for the first time
            mp.insert({prefix_sum,i}) ;

        if ( mp.find(prefix_sum-sum) != mp.end() )
            res = max ( res , i - mp[prefix_sum-sum] ) ;
        
        //! mp[presum-sum] = index where we find presum-sum, so we start the current res subarr
        //! from the NEXT index, not mp[presum-sum], but mp[presum-sum] + 1 .
    }

    return res ;
}