/*
    Farmer john has a new long barm with N(2<=N<=1e6) stalls. The stalls are located in a straight
    line at positions x1,...,xN. ( 0 <= xi <= 1e9 ).
    His C(2<=C<=N) cows don't like this barn layout and become aggressive towards each other once
    put into a stall. To prevent the cows from hurting each other, Fj  wants to assign the cows to
    the stalls, such that the minimum distance between any two of them is as large as possible.
    What is the largest minimum distance.

    Input :-
    t - number of test cases, then t test cases follow.
    *Line 1 : Two space-separated integers : N and C
    *Line 2..N+1 : Line i+1 contains an integer stall location, xi

    Output :-
    For each test case output one integer : The largest minimum distance.
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    We'll have to create a predicate function, with a parameter dist = minimum_distance.
    dist is from 0 to n.
    We have to find the last occurence of true, which means, the max min_dist, with which we CAN
    place the cows.

    The function is a predicate monotonic function of the type : T T T T T T F F F F F F F 
*/

const int N = 1e6 + 10 ;    // Max possible size of array

int n , cows ;  // To save the hassle of passing them as parameters in the predicate function.

vector <long long> arr(N) ; // pos[i] = position of the i'th stall

bool predicate ( int min_dist )
{
    int placed = cows ;
    long long prev = 0 ;
    placed-- ;      // Placing the first cow at arr[0]

    for ( int i = 1 ; i < n ; i++ )
    {
        if ( arr[i] - prev > min_dist )
        {
            placed-- ;   // We can place the cow here
            prev = arr[i] ; // New previous location
        }
    }
    return !placed ;        // Placed should be zero, ie., all cows were placed
}


// Driver Function
int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int T ;
    cin >> T ;

    while ( T-- )
    {
        cin >> n >> cows ;

        for ( int i = 0 ; i < n ; i++ ) // Input the stall positions
            cin >> arr[i] ;

        sort(arr.begin(),arr.begin()+n) ;

        int beg = 0 , end = 1e9 ;   // The minimum and maximum possiible values of min_dist

        while ( end-beg > 1 )   // Find the min_dist
        {
            int mid = beg + (end-beg)/2 ;

            if ( predicate(mid) )   // This is a possible solution
                beg = mid ; // Not +1, as it will exclude
            else
                end = mid-1 ;   // -1, as we can exlude this 'F' from the search space
        }

        // At this point beg == end or end-1 == max(min_pos_sep_dist)
        if ( predicate ( end ) )    // Same logic as 2_predicate_function.cpp
            cout << end << endl ;
        else
            cout << beg << endl ;
    }

    return 0 ;
}