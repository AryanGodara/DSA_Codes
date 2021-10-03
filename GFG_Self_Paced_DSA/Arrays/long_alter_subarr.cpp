// Longest odd-even alternating subarray
# include <bits/stdc++.h>
using namespace std ;

int main ()
{
    int n ;
    cin >> n ;
    vector<int> arr(n) ;
    for ( int i = 0 ; i < n ; i++ )
        cin >> arr[i] ;

    int res = 1 , temp = 1 ;

    // Upto the first element, the max subarray length is 1
    for ( int i = 1 ; i < n ; i++ )
    {
        // cout << "For i = 1, temp =  " << temp << " & " ;
        if ( (arr[i-1]%2==0 && arr[i]%2!=0) || (arr[i]%2==0 && arr[i-1]%2!=0) )
            temp++ ;    // Keep adding this subarray
        else    // Streak brocken
        {
            res = max(res,temp) ;
            temp = 1 ;
        }
        // cout << temp << endl ;
    }
    res = max(res,temp) ;

    cout << res << endl ;

    return 0 ;
}