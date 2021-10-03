// Largest Increasing Subsequence
# include<bits/stdc++.h>
using namespace std ;

int lis_DP ( vector <int> &arr )    // DP solution, but it has time complexity of O(n^2) 
{
    int n = arr.size() ;

    vector <int> dp(n,0) ;
    
    dp[0] = 1 ;

    for ( int i = 1 ; i < arr.size() ; i++ )
    {
        int temp = 1 ;              
        for ( int j = 0 ; j < i ; j++ )
        {
            if ( arr[j] < arr[i] )  // We can append to this subsequence
            {
                temp = max(temp,dp[j]+1) ;
            }
        }
        dp[i] = temp ;
    }

    /*
        OR, we can do this :-
        
        vector <int> dp(n,1) ;
        
        for ( int i = 1 ; i < n ; i++ )
        {
            for ( int j = 0 ; j < i ; j++ )
            {
                if ( arr[j] < arr[i] )
                    dp[i]  = max(dp[i],dp[j]+1) ;
            }
        }
    */

    int res = 0 ;

    for ( auto &x : dp )
        res = max(res,x) ;
    
    return res ;
}

int ceil_index ( vector <int> &tail , int beg , int end , int x ) // Used in lis_BS
{
    while ( end > beg )
    {
        int mid = beg + (end-beg)/2 ;

        if ( tail[mid] >= x )
            end = mid ;
        else
            beg = mid+1 ;
    }

    return end ;
}

int lis_BS ( vector <int> &arr )    // Binary search has a time complexity of O(nlog(n))
{
    int n = arr.size() ;

    vector <int> tail ;
    // tail[i] : stores the minimum possible tail value from LIS of length(i+1) ;
    tail.push_back(arr[0]) ;
    int len = tail.size() ;
    for ( int i = 1 ; i < n ; i++ )
    {
        if ( arr[i] > tail[len-1] )
        {
            tail.push_back(arr[i]) ;
            len++ ;
        }
        else
        {
            int c = ceil_index(tail,0,len-1,arr[i]) ;   // Place it at the required position
            tail[c] = arr[i] ;
        }
    }

    return len ; // The tail array stores longest possible subsequence, atleast, length is the same
}

int MSIS ( vector <int> &arr )  // Maximum sum increasing subarray
{
    int n = arr.size() ;
    vector <int> msis = arr ;   // msis[i] == arr[i], initially

    for ( int i = 1 ; i < n ; i++ )
    {
        for ( int j = 0 ; j < i ; j++ )
        {
            if ( arr[j] < arr[i] )  // msis ending at arr[j] can be continued at arr[i]
                msis[i] = max( msis[i] , arr[i] + msis[j] ) ;
        }
    }

    auto x = max_element(msis.begin(),msis.end()) - msis.begin() ;
    // max_element() returns an iterator, so after subtracting from msis.begin(), we get an integer
    // This integer is the index of the element, which is the maximum of all the element in the array

    return msis[x] ;
}

int main ()
{
    vector <int> arr1 = { 3 , 4, 2 , 8 , 10 } , arr2 = { 8 , 100 , 150 , 10 , 12 , 14 , 110 } ;

    cout << lis_DP(arr2) << endl ;
    cout << lis_BS(arr1) << endl ;
    cout << MSIS(arr1) << endl ;
    cout << MSIS(arr2) << endl ;

    return 0 ;
}