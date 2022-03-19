//? Print all the elements in an array of length n, that occur more than n/k times

# include <bits/stdc++.h>
using namespace std ;

//! Naive Solution, sort the array and count for all elements : O(NlogN)

//? Better Solution : O(N) + time for unordered_map
void prinNbyK ( vector <int> arr , int n , int k ) // Use unordered_map to store count of each
{
    unordered_map <int,int> mp ;

    for ( int i = 0 ; i < n ; i++ )
        mp[arr[i]]++ ;
    
    for ( auto &e: mp )
        if ( e.second > n/k )
            cout << e.first << " " ;
}

//* Efficient Solution : O(nk)
/*
! Check yourself too, but the map can have atmost k-1 elements (whose count is > n/k)

1. Create an empty map m

2. for ( i = 0 ; i < n ; i++ )
    a. if ( m contains arr[i] )
        m[arr[i]]++ ;
    b. else if m.size() < k-1
        m.put(arr[i],1)
    c. else
        decrease all values in m by one. If value becomes 0, remove

3. For all elements in m, print the elements that actually appear more than n/k times
*/

void solve ( int arr[] , int n , int k )
{
    unordered_map <int,int> mp ;

    for ( int i = 0 ; i < n ; i++ )
    {
        if ( mp.find(arr[i]) != mp.end() )
            mp[arr[i]]++ ;
        else if ( mp.size() < k-1 )
            mp[arr[i]] = 1 ;
        else
        {
            for ( auto &x: mp )
            {
                x.second -- ;
                if ( x.second == 0 )
                    mp.erase(x.first) ;
            }
        }
    }

    for ( auto &x: mp )
    {
        int count = 0 ;

        for ( int i = 0 ; i < n ; i++ )
            if ( x.first == arr[i] )    // This element occurs in the array
                count++ ;
            
        if ( count > n/k )
            cout << x.first << " " ;
    }
}