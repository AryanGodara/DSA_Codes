// Using Binary Search
/*
* We're given an unsorted array, where each element a[i] denotes the no. of pages in the i'th
* book of the array. We need to divide these book among k students, st, they array can't be
* rearranged, and each student can only select a continuos selection of books. 
* So, each student will get different no. of pages alloted to them, one of which will be the
* maximum amount of pages, a student has to read.
? Now, we need to divide these books in such a way that, we minimize the max pages allocated.
*/

# include <bits/stdc++.h>
using namespace std ;

bool isFeasible ( vector <int> &arr , int n , int k , int ans )     //! O(N)
{
    int req = 1 , sum = 0 ;

    for ( int i = 0 ; i < n ; i++ )
    {
        if ( sum+arr[i] > ans ) // We'll need another student to accomodate this answer
        {
            req++ ;
            sum = arr[i] ;
        }
        else
            sum += arr[i] ;
    }

    return req <= k ;   // Is feasible, if we require less than or equal to k students
}


int minPages ( vector <int> &arr , int n , int k )    //! O((sum-mx)Log(sum-mx))
{
    int sum = 0 , mx = 0 ;

    for ( int i = 0 ; i < n ; i++ )
    {
        sum += arr[i] ;
        mx = max ( mx , arr[i] ) ;
    }

    int low = mx, high = sum , res = 0 ;
    // The possible solution, will always be between these two values.

    while ( low <= high )
    {
        int mid = (low+high)/2 ;

        if ( isFeasible(arr,n,k,mid) ) {
            res = mid ; // We found a possible solutoin
            high = mid-1 ;
        }
        else {
            low = mid+1 ;   // We'll need to increase the answer, to get a valid one
        }
            
    }
    
    return res ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int n , k ;
    cin >> n ;

    vector <int> arr(n) ;
    for ( int i =0 ; i < n ; i++ )
        cin >> arr[i] ;

    cin >> k ;

    cout << minPages(arr,n,k) << endl ;

    return 0 ;
}