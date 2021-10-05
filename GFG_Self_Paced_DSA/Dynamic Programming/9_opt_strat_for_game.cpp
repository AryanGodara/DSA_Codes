// Optimal Strategy for a game 
// Since the previous file was accidentally deleled, I won't be explaining everything again :(

# include <bits/stdc++.h>
using namespace std ;


// 1st Solution for : Just win every game, no other rules :-
//      Compare the summation of odd coins and even coins, and pick whichever is the greater
//      You'll notice that the player starting first has the choice of picking either all the odd
//      coins or all the even coins (Do a dry run, to check for yourself)



// Now, we come to the solutions, where we try to win with the greatest possible margin :-


// 1st Vanilla Recursion Solution
int sol1 ( vector <int> &arr , int i , int j , int sum )
{
    if ( j == i+1 )
        return max (arr[i] , arr[j] ) ;
    
    return max ( sum - sol1(arr,i+1,j,sum-arr[i]) , sum - sol1(arr,i,j-1,sum-arr[j]) ) ;
}

int main_sol1 ( vector <int> &arr , int n )
{
    int sum = accumulate(arr.begin(),arr.end(),0) ;   // Sum of all the coins

    return sol1 ( arr , 0 , n-1 , sum ) ;
}


// 2nd Vanilla Recursion Solution ( Doesn't require the parameter 'sum' )

int sol2 ( vector <int> &arr , int i , int j )
{
    // Base Case
    if ( j == i+1 )
        return max ( arr[i] , arr[j] ) ;

    return max ( arr[i] +  min( sol2(arr,i+2,j) , sol2(arr,i+1,j-1) ) ,
               arr[j] +  min( sol2(arr,i,j-2) , sol2(arr,i+1,j-1) ) ) ;
}


// DP Solution : Tabulation : Bottom-Up : Iterative

int sol_DP ( vector <int> &arr , int n )
{
    int dp[n][n] ;  // The final solution is : dp[0][n-1] (max from 0 to n-1 coins)
    // So this matrix isn't filled like the other dp matrices we've used in the previous solutions

    for ( int i = 0 ; i < n-1 ; i++ )
        dp[i][i+1] = max ( arr[i] , arr[i+1] ) ;
    
    for ( int gap = 3 ; gap < n ; gap += 2 )
    {
        for ( int i = 0 ; i + gap < n ; i++ )
        {
            int j = i + gap ;

            dp[i][j] = max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),arr[j]+min(dp[i+1][j-1],dp[i][j-2])) ;
        }
    }

    return dp[0][n-1] ;
}

int main ()
{
    vector <int> arr = { 20 , 5 , 4, 6 } ;      // n = length of the array  // n should be even

    cout << main_sol1 ( arr , 4 ) << endl ;
    cout << sol2 ( arr , 0 , 4 - 1 ) << endl ;
    cout << sol_DP( arr , 4 ) ;

    return 0 ;
}