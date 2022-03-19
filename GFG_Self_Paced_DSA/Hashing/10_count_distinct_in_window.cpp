//? Given an array of length n, and an integer k. Find the no. of 'distinct' elements in each
//? window of length 'k' for the array.

# include <bits/stdc++.h>
using namespace std ;

void print_distinct ( vector <int> arr , int n , int k )
{
    unordered_map <int,int> mp ;
    
    for ( int i = 0 ; i < k ; i++ )
        mp[arr[i]]++ ;
    
    cout << mp.size() << " " ; // Size of first window (count of distinct keys in the map)

    for ( int i = k ; i < n ; i++ )
    {
        mp[arr[i-k]]-- ;
        mp[arr[i]]++ ;

        if ( mp[arr[i-k]] == 0 ) // All occurences removed
            mp.erase(arr[i-k]) ;    // Freeing unwanted space

        cout << mp.size() << " " ;
    }

    cout << endl ;
}

//? Driver Function
int main ()
{
    vector <int> arr = {10,10,5,3,20,5} ;

    print_distinct(arr,arr.size(),4) ;

    return 0 ;
}