// Find the maximum of all subarrays of size k ( k <= sizef=of(arr) )
/*
IP : arr[] = { 10 , 8 , 5 , 12 , 15 , 6 , 6 }       k = 3
OP : 10 , 12 , 15 , 15 , 15
*/

# include <iostream>
# include <cmath>
# include <bits/stdc++.h>
# include <climits>
# include <deque>

using namespace std ;

void printMax ( int arr[] , int n , int k )
{
    deque <int> dq ;

    for ( int i = 0 ; i < k ; ++i )
    {
        while ( !dq.empty() && arr[i] >= arr[dq.back()] )
            dq.pop_back() ;// Remove all the elements, smaller than this one, to keep only max elements
        
        dq.push_back(i) ;
    }
}