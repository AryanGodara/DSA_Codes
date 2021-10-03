# include <bits/stdc++.h>
using namespace std ;

// Given an sorted array, and a number x, we need to find if there is a pair in the array with
// the sum equals x
// The hash approach works better for an unsorted array, and the two pointer approach works best 
// for a sorted array. As if we first sort the array, it will take nlog and n, so O(nlogn),
// whereas for an unsorted array, hashing takes O(n), but it take a lot more auxillary space/

// We begin with two pointers, one from arr.begin(), and one from arr.end()-- ;
// If (cur_sum>sum),r_ptr-- ; elseif ((cur_sum>sum)),l_ptr++. else ( return *lptr , *rptr)

vector <int> twoptr ( vector <int> arr , int sum )
{
    int lptr = 0 , rptr = arr.size()-1 ;

    vector <int> ret ;

    while ( lptr < rptr )
    {
        if ( arr[lptr] + arr[rptr] < sum )
            lptr++ ;
        else if ( arr[lptr] + arr[rptr] > sum )
            rptr-- ;
        else
        {
            ret.push_back(lptr) ;
            ret.push_back(rptr) ;
            break ;
        }
    }
    if ( lptr >= rptr )
    {
        ret.push_back(-1) ;
    }
    return ret ;
}

 