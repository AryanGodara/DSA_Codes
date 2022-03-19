//? Find the length of the longest consecutive subsequence (x,x+1,x+2,...,x+i)
//* (These elements can occur in any random order, and don't have to be contiguous)


# include <bits/stdc++.h>
using namespace std ;


//! Naive Method : Use Sorting, then use linear traversal to find the answer

int longest_sub_naive ( vector <int> arr , int n )  //? O(NlogN)
{
    sort ( arr.begin() , arr.end() ) ;

    int res = 1 , cur = 1 ;

    for ( int i = 1 ; i < n ; i++ )
        if ( arr[i] == arr[i-1]+1 )
            cur++ ;
        else
            res = max ( res , cur ) , cur = 1 ;
    
    return max ( res , cur ) ;
}

//* Efficient Solution

int longest_consecutive_subsequence ( vector <int> arr , int n ) //* O(2n) => O(N)
{
    unordered_set <int> s ;
    int res = 0 ;

    for ( int i = 0 ; i < n ; i++ ) // Store all the distinct elements in the set
        s.insert(arr[i]) ;
    
    for ( int i = 0 ; i < n ; i++ )
    {
        if ( s.find(arr[i]-1) == s.end() ) // This can be the smallest element of a subsequence
        {
            int cur = 1 ;

            while ( s.find(arr[i] + cur) != s.end() )
                cur++ ; // As long as we keep finding the next consecutive element
            
            res = max ( res , cur ) ;
        }
    }

    return res ;
}