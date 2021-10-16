/*
    Maximum Sum of Non-Adjacent Substrings
    You are given an array of n elements.
    You are required to find the maximum sum of a subsequence with no adjacent elements.
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    Approach :-

    We make a DP array of size 2*n. (Or two arrays dp_inc[n] and dp_exc[n]). dp[i] store the max
    sum out of the valid subsets ending with arr[i] (inc) or not ending with arr[i] (exc).

    Since the most basic subproblem is for n=1, we traverse the arr from first to last element.
    When the dp arrays are full, we return the maximum of their last elements.

    We can also complete this using OO(1) auxiliary space. We can use two variable, inc and exc
*/

int solve ( vector <int> arr )
{
    int inc = arr[0] , exc = 0 ;    // Current max sum, when current element is excluded and 
                                    // included, respectively.

    for ( int i = 1 ; i < arr.size() ; i++ )
    {
        int ninc = exc + arr[i] ;
        // This stores the sum upto this element, if we ignored the last element.
        // So, it's max value will be exc(sum of all elements, before the prev element), plus the
        // value of the current element.

        int nexc = max ( inc , exc ) ;
        // If we exclude this element, then the max possible sum, is the max of the inc and exc for
        // the previous element.

        inc = ninc ;    // Update the value for, including the current element.
        exc = nexc ;    // Update the value for, excluding the current element.
    }

    return max ( inc , exc ) ;
}

int main ()
{
    cout << solve ({ 5 , 10 , 10 , 100 , 5 }) ;

    return 0 ;
}