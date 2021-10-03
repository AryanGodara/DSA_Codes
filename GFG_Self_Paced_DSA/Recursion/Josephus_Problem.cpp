// jOSEPHUS pROBLEM
/*
    There are n people standing in a circle, we need to kill, k^th person in every iteration.
    After doing this repeatedly, we need to find the position of the survivor.
*/
# include <bits/stdc++.h>
using namespace std ;

int jos ( int n , int k )   // We need to update the remaining positions, and the strarting position
{
    // Base case, if only 1 object is left, that will be zero, so that's the base case.
    if ( n==1 )     // If only 1 person exists, only 
        return 0 ;
    
    // Recursion
    // When we check for the n-1 case, we have to add k, to the answer, we don't get into how the
    // recursion works, just have faith in it, only problem is that the answer should be less than n
    // So, we take modulus with n, every time
    return (jos(n-1,k) + k)%n ;

    // We take n-1, i.e., the remaining players. Now the circle starts from this new position
    // So, we call jos(n-1,k), but add k to this answer. Now, since this is a circular array,
    // the function should return a value that is less than n, so we take %n on the whole thing.
}

int  main ()
{
    cout << jos(3,2) << endl ;
    
    return 0 ;
}