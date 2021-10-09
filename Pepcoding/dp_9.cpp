/*
    Count Binary Strings 
    1. You are given a number n.
    2. You are required to print the number of binary strings of length n with no consecutive 0's.
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    This type of problem is counted in a whole different group of problem solving methods of recursion
    We call this trick the 'Include Exclude Sign'

    Approach :-

    Let's assume 2 arrays, with n+1 length. Both of these arrays will store the count of appropriate
    binary strings of length i at the i'th index but one stores the count of strings ending with 1,
    while the other stores the count of strings ending with 0.

    Logic : dp0[i] = dp1[i-1]
            dp1[i] = dp0[i-1] + dp1[i-1]
    
    For the strings ending with zero, we can only append zero to the strings of length i-1 which 
    end with 1 (Otherwise we'll have consecutive 0's)
    And for the strings ending with one, we can append 1 to both, strings of length i-1 which end
    with 0 and strings which end with 1, as none of them will give consecutive 0's.
*/

int binary_strings ( int n )
{
    vector <int> dp0(n+1) , dp1(n+1) ;
    dp0[0] = dp1[0] = 0 ;
    dp0[1] = dp1[1] = 1 ;

    for ( int i = 2 ; i <= n ; i++ )
    {
        dp0[i] = dp1[i-1] ;
        dp1[i] = dp0[i-1] + dp1[i-1] ;
    }

    return ( dp0[n] + dp1[n] ) ;
}

/*
    We now notice, that since the relation with the subproblems is so linear, we don't actually
    need to waste O(N) auxiliary space by creating an array, we can just use two variables instead.
*/

int solve ( int n )
{
    if ( n == 0 || n == 1 )
        return n+n ;
    
    int end0 = 1 , end1 = 1 ;   // No. of strings of length 1, ending w/ 0 and 1, respectively.

    for ( int i = 2 ; i <= n ; i++ )
    {
        int temp = end0 ;
        end0 = end1 ;
        end1 += temp ;
    }

    return (end0 + end1) ;
}

int main ()
{
    cout << binary_strings(10) << endl ;
    cout << binary_strings(3) << endl ;

    cout << solve(10) << endl ;
    cout << solve(5) << endl ;

    return 0 ;
}

/*
    Arrange Buildings :-

    1. You are given a number n, which represents the length of the road. The road has n plots
       on each side.
    2. The road is to be so planned that there shouldn't be consecutive buildings on either side
       of the road.
    3. You are required to find and print the number of ways in which buildings can be built on
       both sides of the road.

    If you'll notice, this is exactly like the count binary strings problem.

    Suppose you have a road of length n, then on one side of the road, if we denote a building by 1,
    and empty space by a 0. Then this question simply asks us to find the no. of binary strings of
    length 'n' with no consecutive 1's. (We can just flip all strings with no consecutive 0's, and
    the result will remain the same).
    
    Now, since there are two sides of the road, we can do this operation twice. So we'll have two
    sets of answers, say f(n).
    
    Using the concept from PNC, The no. of ways to do things A AND B = nA * nB.
    
    So, in this case, the answer will be f(n)*f(n)
*/