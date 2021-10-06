/*
    GOLDMINE :-
    YOu are given a grid of size n*m and the grid as a whole represents a gold min. You are standing
    in front of the left wall and are supposed to dig to the right wall. You can start from any row
    in the left wall. You are allowed to move 1 cell right-up (d1) , 1 cell right (d2) or 1 cell
    right-down (d3).
    Each cell has a value that is the amount of gold available in the cell.
    You are required to identify the maximum amount of gold that can be dug out from the mine.
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    Approach :0

    Storage and Meaning :-
    It's fairly simple. We make an array for DP of hte dimensions same as that of the gold mine.
    The meanining assigned to a single cell in this grid is that "if we would have started from this
    cell, what is the maximum amount of gold we could have collected."

    1. Array arr[n][m] is taken as the input for dimensions n and m.
    2. We make a new array dp[n][m] with the same dimensions as arr where each cell stores the
       maximum amount of gold that would be collected if we start from that cell.
    3. Since we start from the last col of the grid, therefore our loop runs from m-1'th to 0'th col
    4. For every column, we start traversing from a row at the extremities hence the row iteration
       runs from n-1'th to 0'th row ( or 0 to n-1, both work fine )
    5. If we are at teh "end" column then the maximum value at cell in the DP array is the value of
       the input cell itself.
    6. If one is at the last row of a column then there isn't an option of going right-up. Hence, the
       value at the cell is the value of the input array added to the max of right and right down.
    7. If one is at the first row of a column then there isn't an option of going right-down. Hence,
       the value at the cell is the value of the input array added to the max of right and right up.
    8. If it's neither of the above 2 cases, then the value at teh cell is the sum of the values of
       the input array and the maximum of right-up, right, and right-down.
    9. Now that the dp grid is filled, the result is the maximum element of the first column.
*/

int solve ( vector <vector<int>> &goldmine )
{
    int n = goldmine.size() , m = goldmine[0].size() ;

    int dp[n][m] ;

    for ( int i = 0 ; i < n ; i++ )     // Last Column
        dp[i][m-1] = goldmine[i][m-1] ;
    
    for ( int j = m-2 ; j >= 0 ; j-- )  // From 2nd last to the first column
    {
        dp[0][j] = goldmine[0][j] + max ( dp[0][j+1] , dp[1][j+1] ) ;   // First row
        
        for ( int i = 1 ; i < n-1 ; i++  )  // The rest of the rows
            dp[i][j] = goldmine[i][j] + max( dp[i][j+1] , max ( dp[i+1][j+1],dp[i-1][j+1] ) ) ;
        
        dp[n-1][j] = goldmine[n-1][j] + max ( dp[n-1][j+1] , dp[n-2][j+1] ) ;   // Last row
    }

    int res = dp[0][0] ;

    for ( int i = 0 ; i < n ; i++ )
        res = max ( res , dp[0][i] ) ;

    return res ;
}

int main ()
{
    vector <vector<int>> grid = 
    {
        {26,24,21,14,12,2},
        {31,26,23,17,6,4},
        {28,27,21,11,10,6},
        {29,25,25,13,8,2},
        {33,26,23,18,9,4},
        {32,30,18,17,9,1},
    } ;

    cout << solve(grid) << endl ;

    return 0 ;
}