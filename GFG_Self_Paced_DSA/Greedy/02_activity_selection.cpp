/*
    Activity Selection Problem
    I/P : { (2,3) , (1,4) , (5,8) , (6,10) }
    O/P : 2
    I/P : { (1,3) , (2,4) , (3,8) , (10,11) }
    O/P : 3

    pair.first = start_time , pair.second = end_time

    Return the max no. of activites that can happen on a single tasking machine
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    A Naive Solution would be to iterate through the array, and consider each activity as the 
    first activity. Then call the function recursively for the activities that start after the
    end of that activity.
    Then take the max of these values, and return the final answer.
    This is a very lengthy approach (Exponential Time Required, which can be brought down to
    polynomial time using Dynamic Programming)

    Check '04_largest_incr_subseq.cpp' for context
*/

/*
    Greedy Algorithm :-

    1. Sort the array accodgin to the finish time.
    2. Initialise Solution as first activity
    3. Do the following for remaining activities
        a. If current activity overlaps with the last picked activity in the solution, ignore
           the current activity.
        b. Else add the current activity to the solution
*/

bool cmp ( pair<int,int> a , pair<int,int> b )
{
    if( a.second != b.second )
        return a.second < b.second ;
    return a.first < b.first ;
}

bool overlaps ( pair<int,int> a , pair<int,int> b )
{
    if ( b.first >= a.second )  // The cur task starts, only after the prev one ends
        return false ;
    
    return true ;
}

int solve ( vector <pair<int,int>> arr )    // Greedy Approach
{
    sort ( arr.begin() , arr.end() , cmp ) ;

    pair<int,int> soln = arr[0] ; // First activity has the lowest finish time, finished the earliest
    int count = 1 ; // We have already included the first activity in the solution

    for ( int i = 1 ; i < arr.size() ; i++ )
    {
        if ( overlaps(soln,arr[i]))
            continue ;  // Ignore this
        else
        {
            soln = arr[i] ; // We selected this for hte solution
            count++ ;
        }
    }

    return count ;
}


// Driver Function
int main ()
{
    vector <pair<int,int>> arr1 = { {12,25} , {10,20} , {20,30} } ;
    vector <pair<int,int>> arr2 = { {3,4} , {2,6} , {1,5} } ;

    cout << solve ( arr1 ) << endl ;
    cout << solve ( arr2 ) << endl ;

    return 0 ;
}