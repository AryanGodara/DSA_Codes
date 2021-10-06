/*
    Minimum Cost to reach from top-left to the bottom-right corner.
    1. You are given a number n, representing the number of rows
    2. You are given a number m, representing the numbers of cols
    3. You are given n*m numbers, representing the elements of the 2D array A, which represents
       a maze
    4. You are standing in the top-left cell and are required to move to the bottom-right cell
    5. You are allowed to move 1 cell right (h move) or 1 cell down (v move) in 1 motion
    6. Each cell has a value that will have to be paid to enter that cell ( even for the top-left 
       and the bottom-right cells )
    7. You are required to traverse through the matrix and print the cost of path which is the
       least costly
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    DP Approach :-
    1. Array arr[n][m] is taken as the input for dimensions n and m
    2. We make a new array dp[n][m] with the same dimensions as arr where each cell stores the min
       cost of all the paths to travel from that cell to the destination cell dp[n-1][m-1] 
    3. Since we start from the bottom row to the top row of the grid, therefore our loop runs from
       n-1 to 0'th tow
    4. For every row, we start traversing from the rightmost column hence the column iteration runs
       from m-1 to 0
    5. As we have already discussed in the "traversal" section, if we are at the destination cell
       then the minium cost at that cell is the value of teh input cell iself
    6. If you are at the bottom row then there isn't an option of going vertically down. Hence, the
       value at the cell is the value of the input array added to teh previous cell at the right.
    7. If one is at the last column then there isn't an option of going horizontally right available.
       Hence, the value at the cell is teh value of the input array added to the previous cell below it
    8. If it is neither of the above 2 cases, then the value at the cell is the sum of the value of 
       input array and the minimum of vertical and horizontal costs.
    9. As already discussed, teh minimum cost path out of all the possible paths is stored in 
       dp[0][0]. This value is printed
*/

int min_cost ( vector < vector<int> > arr , int n , int m ) // n rows , m columns
{
    int dp[n][m] ;
    dp[n-1][m-1] = arr[n-1][m-1] ;

    // Set the values for the last row and the last column
    for ( int i = m-2 ; i >= 0 ; i-- ) // All values of m, for the last row
        dp[n-1][i] = arr[n-1][i] + dp[n-1][i+1] ;
    
    for ( int j = n-2 ; j >= 0 ; j-- )
        dp[j][m-1] = arr[j][m-1] + dp[j+1][m-1] ;

    for ( int i = m-2 ; i >= 0  ; i-- )
    {
        for ( int j = n-2 ; j >= 0 ; j-- )
        {
            dp[i][j] = min ( arr[i][j] + dp[i][j+1] , arr[i][j] + dp[i+1][j] ) ;
        }
    }

    return dp[0][0] ;
}

int main ()
{
    vector <vector<int> > arr = {
        {2,8,4,1,6,4,2} ,
        {6,0,9,5,3,8,5} ,
        {1,4,3,4,0,6,5} ,
        {6,4,7,2,4,6,1} ,
        {1,0,3,7,1,2,7} ,
        {1,5,3,2,3,0,9} ,
        {2,2,5,1,9,8,2} ,
    } ;

    cout << min_cost ( arr , 7 , 7 ) << endl ;

    return 0 ;
}