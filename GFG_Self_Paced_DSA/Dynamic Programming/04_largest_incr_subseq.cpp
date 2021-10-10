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

    // Instead of using the ceil_index() function, which is essentially binary search, we can
    // also use the built in lower_bound() function. In this case, int c will be equal to 
    // int c = lower_bound(arr.begin(),arr.end(),arr[i]) - arr.begin() ;
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

int MLBS ( vector <int> &arr )  // Maximum length of bitonic subsequence
{   
    // A subsequence that is first increasing, then decreasin (A peak)
    
    int n = arr.size() ;

    // Find the Longest increasing subsequences from the left side of the array
    // And then find the Longest Decreasing subsequences from the right side of the array.
    // And then do a linear search at each element, whichever has the greatest sum of the 
    // LIS and LDS, is the peak, of the long bitonic subsequence, and the sum of the corresponding
    // LIS+LDS is our answer

    vector <int> incr(n,1) , decr(n,1) ;    // Minimum subsequence is of length 1, for each case.
        
    for ( int i = 1 ; i < n ; i++ )     // LIS
    {
        for ( int j = 0 ; j < i ; j++ )
        {
            if ( arr[j] < arr[i] )
                incr[i]  = max( incr[i] , incr[j]+1 ) ;
        }
    }

    for ( int i = n-2 ; i >= 0 ; i-- )  // LDS
    {
        for ( int j = n-1 ; j > i ; j--)
        {
            if ( arr[j] < arr[i] )  // Subsequence should decrease as we move right
            {
                decr[i] = max( decr[i] , decr[j]+1 ) ;
            }
        }
    }

    int res = 1 ;   // The smallest possible answer

    for ( int i = 0 ; i < n ; i++ )
        res = max ( res , incr[i]+decr[i]-1 ) ; // -1 because arr[i] is added twice to the lists

    return res ;

    // We can also do this using the binary search approach, which is O(nlog(n))

    // NOTE : Both increasing and decreasing sorted arrays, are also considered as bitonic.
}

bool cmp ( pair<int,int> a , pair<int,int> b )
{
    if ( a.first != b.first )
        return a.first < b.first ;
    return a.second < b.second ;
}

int building_bridges ( vector < pair<int,int> > arr )
{
    // The maximum no. of bridges that can be build across a river such that no two bridges
    // intersect with each other

    // Steps :-
    // 1. Sort the array, on the basis of teh first value of the pair. (Normal sort function will do)
    // 2. Find the LIS of the sorted array, according to the second values. (So that the bridges)
    //    don't intersect

    sort(arr.begin(),arr.end(),cmp) ;

    int n = arr.size() ;

    vector <int> dp(n,1) ;

    for ( int i = 1 ; i < n ; i++ )
    {
        for ( int j = 0 ; j < i ; j++ )
        {
            if ( arr[j].second < arr[i].second )
            {
                dp[i] = max( dp[i] , dp[j] + 1 ) ;
            }
        }
    }

    int res = 1 ;
    for ( int i = 0 ; i < n ; i++ )
        res = max ( res , dp[i] ) ;

    return res ;
}

int main ()
{
    vector <int> arr1 = { 3 , 4, 2 , 8 , 10 } , arr2 = { 8 , 100 , 150 , 10 , 12 , 14 , 110 } ;
    vector <int> arr3 = { 1 , 11 , 2 , 10 , 4 , 5 , 2 , 1 } ;
    vector <pair<int,int>> bridges { {6,2} , {4,3} , {2,6} , {1,5} } ;

    cout << lis_DP(arr2) << endl ;
    cout << lis_BS(arr1) << endl ;
    cout << MSIS(arr1) << endl ;
    cout << MSIS(arr2) << endl ;
    cout << MLBS(arr3) << endl ;
    cout << building_bridges(bridges) ;

    return 0 ;
}