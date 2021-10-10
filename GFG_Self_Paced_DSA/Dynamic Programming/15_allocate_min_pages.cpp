/*
    We are given n books, and we are given the no. of pages in those booka ( an array of length n )
    And, we are given the no. of students (represented with 'k' here)
    These 'k' students are supposed to read all of these books.
    If a student wants to read two books, then he must also read all the book b/w those two books.
    OR, the array must be divided into contiguous parts (No gaps in selections)
    When we divide the books among all the students, we'll be allocating some pages to each student.
    We have to divide the books in such a way that we minimize the 'max pages' read by a single
    student.
    And return the minimum possible 'max pages' to the user.
*/

# include <bits/stdc++.h>
using namespace std ;

int sum_arr ( vector <int> &arr , int i , int j )
{
    int sum = 0 ;

    for ( int x = i ; x <= j ; x++ )
        sum += arr[x] ;
    
    return sum ;
}

// Vanilla Recursion Solution

int solve ( vector <int> &arr , int k , int i , int j ) // No. of students, beginning,  and end
{
    // Base Case
    if ( j-i+1 < k )    // More students than no. of books
        return INT_MAX ;
    if ( i == j ) // Single element
        return arr[i] ;
    if ( j-i+1 == k ) // Each student will get one book, so just return the max elemnt in this range
        return arr[max_element( arr.begin()+i , arr.begin()+j ) - arr.begin() ];
    if ( k == 2 )   // Find the best partition
    {
        int net_sum = sum_arr(arr,i,j) ;
        // Traverse the entire array, each student has to read at least 1 book
        int res = net_sum , cur_sum = arr[i] ;
        for ( int x = i+1 ; x < j ; x++ )
        {
            cur_sum += arr[x] ;
            res = min ( res , max ( cur_sum , net_sum - cur_sum ) ) ;
        }
        res = min ( res , max ( arr[i] , net_sum-arr[i] ) ) ;

        return res ;
    }    
    if ( k == 1 )   // There's only one student     
        return sum_arr(arr,i,j) ;

    // Recursion
    int res = INT_MAX ; // The max books to be read by a student
    int sum_upto_x = 0 ;
    for ( int x = i ; x < j ; x++ )
    {
        sum_upto_x += arr[x] ;
        // Select the no. of books read by the first student
        res = min ( res , max ( sum_upto_x , solve(arr,k-1,x+1,j) ) ) ;
        // We now have one less student to read the rest of the books
    }       // Doesn't Work for all cases

    return res ;
}

int min_pages ( vector <int> &arr , int n , int k )
{
    if ( k == 1 )
        return sum_arr(arr,0,n-1) ;
    if ( n == 1 )
        return arr[0] ;
    
    int res = INT_MAX ;

    for ( int i = 1 ; i < n ; i++ )
        res = min ( res , max ( min_pages(arr,i,k-1) , sum_arr(arr,i,n-1) ) ) ;

    return res ;
}

int min_pages_dp ( vector <int> &arr , int n , int k )
{
    int dp[k+1][n+1] ;

    for ( int i = 1 ; i <= n ; i++ )    // When only one student is there, he gets all the books
        dp[1][i] = sum_arr(arr,0,i-1) ;
    
    for ( int i = 1 ; i <= k ; i++ )    // If there is only 1 element, then that's the max
        dp[i][1] = arr[0] ; 
    
    for ( int i = 2 ; i <= k ; i++ )
    {
        for ( int j = 2 ; j <= n ; j++ )
        {
            int res = INT_MAX ;

            for ( int p = 1 ; p < j ; p++ )
                res = min ( res , max ( dp[i-1][p] , sum_arr(arr,p,j-1) ) ) ;
            
            dp[i][j] = res ;
        }
    }

    return dp[k][n] ;
}

int main ()
{
    vector <int> arr1 = {10,20,30,40} , arr2 = {10,20,30} , arr3 = {10,5,30,1,2,5,10,10} ;

    cout << solve(arr1,2,0,arr1.size()-1) << endl ;
    cout << solve(arr1,3,0,arr1.size()-1) << endl ;
    cout << solve(arr2,2,0,arr2.size()-1) << endl ;
    cout << solve(arr3,3,0,arr3.size()-1) << endl ;
    cout << solve(arr3,4,0,arr3.size()-1) << endl ;
    cout << solve(arr3,5,0,arr3.size()-1) << endl ;
    cout << endl ;
    cout << min_pages(arr1,arr1.size(),2) << endl ;
    cout << min_pages(arr1,arr1.size(),3) << endl ;
    cout << min_pages(arr2,arr2.size(),2) << endl ;
    cout << min_pages(arr3,arr3.size(),3) << endl ;
    cout << min_pages(arr3,arr3.size(),4) << endl ;
    cout << min_pages(arr3,arr3.size(),5) << endl ;
    cout << endl ;
    cout << min_pages_dp(arr1,arr1.size(),2) << endl ;
    cout << min_pages_dp(arr1,arr1.size(),3) << endl ;
    cout << min_pages_dp(arr2,arr2.size(),2) << endl ;
    cout << min_pages_dp(arr3,arr3.size(),3) << endl ;
    cout << min_pages_dp(arr3,arr3.size(),4) << endl ;
    cout << min_pages_dp(arr3,arr3.size(),5) << endl ;

    return 0 ;
}