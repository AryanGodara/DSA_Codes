//? We're given two binary arrays of the same size. Our task is to find the longest span
//? in these two arrays, for which, the subarray sum is equal for BOTH the arrays.
//* Length of the longest possible common subarray, with the same sum.

/*
    eg.:
    a1[] = {0,1,0,0,0,0}
    a2[] = {1,0,1,0,0,1}
              _______       (Both these subarrays have sum == 1, and max possible length == 4)
*/

# include <bits/stdc++.h>
using namespace std ;

// TODO : Create a new subarray temp[] , and temp[i] = +- ( arr1[i] - arr2[i] )
// * : Now, are problem has simply reduced to finding the length of the longest subarray 
// * : with 0 sum, on temp[] array.

//! This works here because both arr[1] and arr[2] are binary subarrays.