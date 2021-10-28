# include <bits/stdc++.h>
using namespace std ;

// Binary Search in 2D Arrays

// Matrix is sorted in a row wise and col wise manner. So, all rows and cols are sorted.

pair<int,int> lin_search ( vector < vector <int> > arr , int x )
{
    int m = arr.size() , n = arr[0].size() ;    // Row and Col
    int r = 0 , c = n-1 ;   // Starting from the first row, and the last column

    while ( r < m && c >= 0 )
    {
        if ( arr[r][c] == x )
            return {r,c} ;
        else if ( arr[r][c] < x )   // This row is then useless
            r++ ;
        else                        // This column is useless
            c-- ;
    }

    return {-1,-1} ;
}


// Strictly Sorted Array, Elements keep on increasing row by row
/*
Eg : 
1  2  3  4  5 
6  7  8  9  10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
*/

int simple_bin_search ( vector <int> arr , int target , int s , int e )
{
    int beg = s , end = e ;

    while ( beg <= end )
    {
        int mid = beg + (end-beg)/2 ;

        if ( arr[mid] == target )
            return mid ;
        if ( arr[mid] < target )
            beg = mid+1 ;
        else
            end = mid-1 ;
    }

    return -1 ;
}

pair<int,int> bin_search ( vector <vector <int>> arr , int x )
{
    int m = arr.size() , n = arr[0].size() ;    // Be cautious, matrix may be empty
    // Perform linear_bin_search in rows, as rows here are vector<int>, which can be directly
    // passed into the above functon , i.e., simple_bin_search

    if ( m == 1 )   // There's only 1 row
        return { 0 , simple_bin_search(arr[0],x,0,n-1) } ;

    // Run the loop till 2 rows are remaining
    
    int row_start = 0 , row_end = m-1 , col_mid = n/2 ;

    while ( row_start < row_end-1 ) // As long as this is satified, there will be > 2 rows
    {
        int row_mid = row_start + (row_end-row_start)/2 ;   // Select the mid row
        
        int pos_in_row = simple_bin_search(arr[row_mid],x,0,n-1) ;

        if ( pos_in_row != -1 )
        {
            return { row_mid , pos_in_row } ;
        }
        else if ( arr[row_mid][col_mid] < x )  // Ignore the rows above row_min
            row_start = row_mid ;
        else                                    // Ignore the rows below row_max
            row_end = row_mid ;
    }

    // If the control reaches here, that means that we have two rows
    // So, check whether the target is in the col of 2 rows
    if ( arr[row_start][col_mid] == x )
        return { row_start , col_mid } ;
    if ( arr[row_end][col_mid] == x )
        return { row_end , col_mid } ;
    
    // Search in 1st half
    if ( x <= arr[row_start][col_mid-1] )
        return {row_start , simple_bin_search(arr[row_start] , x , 0 , col_mid-1)} ;
    // Search in 2nd half
    if ( x >= arr[row_start][col_mid+1] && x < arr[row_start+1][col_mid+1])
        return {row_start,simple_bin_search(arr[row_start] , x , col_mid+1 , n-1)} ;
    // Search in 3rd half
    if ( x <= arr[row_start+1][col_mid-1] )
        return {row_start+1,simple_bin_search(arr[row_start+1] , x , 0 , col_mid-1)} ;

    // Search in 4th half
    if ( x >= arr[row_start+1][col_mid+1] )
        return {row_start+1,simple_bin_search(arr[row_start+1] , x , col_mid+1 , n-1)} ;

    return {-1,-1} ;
}

int main ()
{
    vector <vector<int>> arr = {
        {10,20,30,40},
        {15,25,35,45},
        {28,29,37,49},
        {33,34,38,50}
    } ;

    vector <vector<int>> grid = {
        {1,  2,  3,  4,  5 },
        {6,  7,  8,  9,  10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    } ;

    int x = 100 , y = 14 ;

    cout << lin_search(arr,x).first << " " << lin_search(arr,x).second << endl ;

    cout << bin_search(arr,y).first << " " << bin_search(arr,y).second << endl ;

    return 0 ;
}