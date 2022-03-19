# include <bits/stdc++.h>
using namespace std ;

bool zero_sum_subarray ( vector <int> &arr , int n ) // Subarray means continuous
{
    unordered_set <int> us ;

    int prefix_sum = 0 ;

    us.insert(0) ;

    for ( int i = 0 ; i < n ; i++ )
    {
        prefix_sum += arr[i] ;

        if ( us.find(prefix_sum) != us.end() ) // This sum already existed earlier
            return true ;
        
        us.insert(prefix_sum) ;
    }

    return false ;
}

// If we encounter the same 'prefix sum' twice, it means that the sum of all the elements
// between these two occurences was 0.

int main ()
{
    vector <int> arr = {5,3,9,-4,-6,7,-1} ;

    cout << zero_sum_subarray(arr,arr.size()) << endl ;

    return 0 ;
}