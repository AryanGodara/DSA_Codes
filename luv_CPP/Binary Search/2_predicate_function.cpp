// Adnaced Binary Search with Predicate Function
# include <bits/stdc++.h>
using namespace std ;

/*
    Any function that returns true or false, is called a predicate function

    Monotonic Predicated Functions :-
        a. TTTFFFFFFF       b. FFFFFTTTTTT      // Only these two types are possible

    So, we need to create a predicate function that returns true(or false) upto some point, and
    after that, print only false(or true).
    So, we can find the first false or last true (in a ), using binary search, or upper_/lower_bound
*/

const int N = 1e7 ;   // Arrays of size > 1e5 should be declared globally
int n ;  // Declared globally, so we don't have to pass it as a function parameter
long long m ;
vector <long long> trees(N) ;

bool predicate_isWoodSufficient ( int h )
{
    long long int wood = 0 ;
    for ( int i = 0 ; i < n ; i++ ) // Traversing the entire array
    if ( trees[i] >= h )    // We can cut this
        wood += trees[i]-h ;
    return wood>=m ;   // The total collected wood should be greater than or equal to m
}


// Driver Function
int main ()
{
    int T ;
    cin >> T ;
    
    while (T--)
    {
        cin >> n >> m ;
        for ( int i = 0 ; i < n ; i++ )
            cin >> trees[i] ;
        
        long long beg = 0 , end = 1e9 ; // Max tree height = 1e9

        // We have to find the last position of True in T T T T F F F F F F F F F (monotonic)
        while ( end-beg > 1 )
        {
            long long int mid = beg + (end-beg) / 2 ;

            if ( predicate_isWoodSufficient(mid) )  // Lies in the range 'T T T T T' F F F F
                beg = mid ; // Not mid+1, as this value of mid can also be the final answer
            else    // Lies in the range T T T T T 'F F F F F'
                end = mid-1 ;   // This value of mid, can't be the answer, so we do mid '-1'
        }
        // At this point end = beg or beg+1 // And both can be true
        // And we have to find the 'last' position of true

        if ( predicate_isWoodSufficient(end) )
            cout << end << endl ;
        else // Since it's guaranteed that a valid height WILL be found, no need to check for beg
            cout << beg << endl ;
    }

    return 0 ;
}