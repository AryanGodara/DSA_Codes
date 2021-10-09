// Egg Dropping Challenge
/*
    We have 'e' eggs and 'f' floors.
    Find the minimum no. of trials in worst case, to find the threshhold floor in the worst case. 
    (The first floor from which, if we drop the egg, it breaks).

    // We need to find the min no. of trials in the worst case

    Some Rules :-
    1. Egg may break from the 1st floor
    2. Egg may not break from the top floor
    3. If an egg breaks from a floor, it will break from a higher floor also
*/

# include <bits/stdc++.h>
using namespace std ;

// Recursive Solution
/*
    Let res(f,e) be the minimum no. of trials in the worst case for f floors and e eggs.

    res(f,e) = min(x = 1 to x = f) ( max(breaks , doesn't break) ) + 1  // Two recursive calls
*/

int rec ( int f , int e )
{
    // Base Case
    if ( f <= 1 )   // If 1 floor is left : 1 trial max. If 0 floors left : 0 trials
        return f ;
    if ( e == 1 )   // If we have just 1 egg, we'll have to try out all the floors
        return f ;

    // Recursion
    int res = INT_MAX ;
    for ( int i = 1 ; i <= f ; i++ )
        res = min ( res , max ( rec(i-1,e-1) , rec(f-i,e)  ) ) ;
    
    // 1st recursive call is in the case egg breaks. So, we'll then check the floors below the
    // i'th floor. And since we broke the egg, the no. of eggs left is e-1
    
    // 2nd recursive call is if the egg doesn't break. So, we'll check the floors above the i'th
    // floor. And since the egg didn't break, we still have 'e' eggs.

    // Since we have to find this for the worst possible case, we take the max of the two rec calls
    // And since, we have to find the 'minimum' no. of trials in the 'worst' case
    // We take the min of all the values of res.
    
    return res + 1 ;
}


// Dynamic Programming Solution

// Since we have two parameters that are changing : e and f. So, we'll need at 2D array
// f goes from 0 to f, and e goes from 1 to e. But it will be simpler to take e from 0 to e.
// e=0 is just a dummy column (it's never accessed), but it makes it simpler to store the elements
// in the matrix, since we don't have to use e-1 or any other relations.

int rec_dp ( int f , int e )    // Tabulation Solution
{
    int dp[f+1][e+1] ;  // Rows are floors, Columns are eggs. We fill this in row major style.

    for ( int i = 0 ; i <= f ; i++ )   // When eggs are 0
        dp[i][0] = 0 ;
    for ( int i = 0 ; i <= f ; i++ )   // When eggs are 1
        dp[i][1] = i ;
    for ( int i = 0 ; i <= e ; i++ )    // When floor is 0'th
        dp[0][i] = 0 ;
    for ( int i = 0 ; i <= e ; i++ )    // When floor is 1'st
        dp[0][i] = 1 ;
    
    // Now, we fill the rest of the array

    for ( int i = 2 ; i <= f ; i++ )
    {
        for ( int j = 2 ; j <= e ; j++ )
        {
            dp[i][j] = INT_MAX ;

            // Traverse all the floors from 1 to i
            for ( int k = 1 ; k <= i ; k++ )
                dp[i][j] = min ( dp[i][j] , max ( dp[k-1][j-1] , dp[i-k][j]) ) ;
            
            dp[i][j]++ ;    // return res+1
        }
    }

    return dp[f][e] ;
}


// Driver Function
int main ()
{
    int e = 2 , f = 10 ;
    cout << rec ( f , e ) << endl ;
    cout << rec_dp ( f , e ) << endl ;

    return 0 ;
}