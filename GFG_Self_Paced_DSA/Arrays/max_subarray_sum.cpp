# include <bits/stdc++.h>
using namespace std ;

int main ()
{
    int n ;
    cin >> n ;
    vector<int> arr(n) ;
    for ( int i = 0 ; i < n ; i++ )
        cin >> arr[i] ;

    int res = INT_MIN , temp = 0 ;

    vector<int> maxsum(n) ;
    maxsum[0] = arr[0] ;
    temp = arr[0] ;

    for ( int i = 1 ; i < n ; i++ )
    {
        maxsum[i] = max(maxsum[i-1]+arr[i],arr[i]) ;    // Array approach
        // Two variable approach below
        temp = max(temp+arr[i],arr[i]) ;
        res = max(res,temp) ;
    }
    cout << *max_element(maxsum.begin(),maxsum.end()) << endl ;
    cout << res << endl ;
    
    return 0 ;
}