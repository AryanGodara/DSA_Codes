#include <bits/stdc++.h>
using namespace std;

int sum ( vector<int> &arr, int s, int e )
{
    int ans = 0 ;
    for ( int i = s ; i <= e ; i++ )
        ans += arr[i] ;

    return ans ;
}

int minPages ( vector<int> &arr, int n, int k )
{
    if ( k == 1 )
        return sum(arr,0,n-1) ;
    if ( n == 1 )
        return arr[0] ; // Only one possible solution

    int ans = INT_MAX ;
    // Ans = minimum possible values of the 'max' pages a student will have to read

    for ( int i = 1 ; i < n ; i++ )
        ans = min ( ans , max(minPages(arr,i,k-1), sum(arr,i,n-1) )) ;
    // We give the current student, all the books from i to n-1
    // Then, we call the function recursively to find the ans for the remaining set of
    // books. Then, we take the maximum of those two, to find the final answer.
    
    // In this method, we're going through all of the possible solutions.
    
    return ans ;
}

int main () 
{
    vector<int> arr = {10,20,10,30} ;
    int k = 2 , n = 4 ;

    cout << minPages(arr,n,k) << endl ;

    k++ ;
    cout << minPages(arr,n,k) << endl ;

    return 0 ;
}