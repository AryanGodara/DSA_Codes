// Find the maximum of all subarrays of size k ( k <= sizef=of(arr) )
/*
IP : arr[] = { 10 , 8 , 5 , 12 , 15 , 6 , 6 }       k = 3
OP : 10 , 12 , 15 , 15 , 15
*/

# include <bits/stdc++.h>
using namespace std ;

void printMax ( int arr[] , int n , int k )
{
    deque <int> dq ;

    for ( int i = 0 ; i < k ; ++i )
    {
        while ( !dq.empty() && arr[i] >= arr[dq.back()] )
            dq.pop_back() ;
        
        dq.push_back(i) ;
    }

    for ( int i = k ; i < n ; i++ )
    {
        cout << arr[dq.front()] << " " ;

        while ( !dq.empty() && dq.front() <= i-k )  // Within the ranke of k subarray
            dq.pop_front() ;
        
        while ( !dq.empty() && arr[i] >= arr[dq.back()] )
            dq.pop_back() ;
        
        dq.push_back(i) ;
    }
    
    cout << arr[dq.front()] << endl ;
}