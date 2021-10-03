/*
    Given an integer array which represents the height of N buildings, the task is to delete N-2 
    buildings such that the water trapped between two buildings is gap between them (number of 
    buildings removed) multiplied by height of the smaller building.
*/

/*
    The Naive approach will be to do a n^2 approach, and go through all the pairs, maintaining a 
    max and cur, and return the max value of water.
*/

# include <bits/stdc++.h>
using namespace std ;

// Efficient Approach :-
// 1. Sort the array according to increasing height without affecting the original i.e make pairs
//    of ( elements , index ).
// 2. Then for every element, assume it is the building with minimum height among the two buildings
//    required then the height of the required water will be equal to the height of the chosen 
//   building and the building to be found.
// 3. In order to choose the other building which maximises the water, the other building has to be as
//    far as possible and must be greater in height as compared to the currently chosen building.
// 4. Now, the problem gets reduced to finding the max and min indices on the right for every building
//   in the sorted array.

bool compare ( pair<int,int> p1 , pair<int,int> p2 )    // Comparator Function
{
    return p1.second < p2.second ;
}

// Return the max water than can be stored
int maxWater(int height[], int n) 
{ 
    // Make pairs with indices
    pair <int,int> pairs[n] ;
    for ( int i = 0 ; i < n ; i++ )
        pairs[i] = make_pair ( i , height[i]) ;

    // Sort array based on heights
    sort ( pairs , pairs + n , compare ) ;

    // To store the min and max index so far from the right
    int minindsofar = pairs[n-1].first ;
    int maxindsofar = pairs[n-1].first ;
    int maxi = 0 ;

    for ( int i = n - 2 ; i >= 0 ; i++ )
    {
        // Current building paired with the building greater in height and on the extreme left
        int left = 0 ;
        if ( minindsofar < pairs[i].first )
        {
            left = (pairs[i].second * (pairs[i].first - minindsofar - 1) ) ;
        }

        // Current building paired with the building greater in height and on 
    }
} 