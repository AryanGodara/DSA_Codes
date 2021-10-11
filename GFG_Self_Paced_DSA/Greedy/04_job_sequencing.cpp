/*
    Job Sequencing Problem
    We are given n jobs. Every job has a deadline and a profit.
    We get this profit, if we finish the job before their respective deadline.

    We have to maximise the profit.

    Rules :-
    1. Every job takes one unit of time
    2. Only one job can be assigned at a time.
    3. Time starts with 0
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    Greedy Algorithm Approach :-
    1. We sort the jobs in the decreasing order of their profits.
    2. Initialize the rsult as first joob in the sorted list. Assign the latest possible slot.
    3. Do the following for the remaining (n-1) jobs.
        a. If this job can't be added, ignore it.
        b. Else, add it to teh latest possible slot.
*/

bool cmp ( pair<int,int> a , pair<int,int> b )
{
    if ( a.second != b.second )
        return a.second > b.second ;
    return a.first < b.first ;
}

int solve ( vector <pair<int,int>> jobs )
{
    int n = jobs.size() ;
    // jobs.first = deadline , jobs.second = profit
    sort ( jobs.begin() , jobs.end() , cmp ) ;

    int max_time = 0 ;  // The maximum deadline in the entire jobs array
    
    for ( int i = 0 ; i < n ; i++ )
        max_time = max ( max_time , jobs[i].first ) ;

    vector <int> res (max_time+1,0) ;   // The res[0] slot remains empty (no job has 0 deadline)

    for ( int i = 0 ; i < n ; i++ )
    {
        int place_here = jobs[i].first ;  // This is the latest place, where we can place this job

        while ( res[place_here] != 0 && place_here )
            place_here-- ;
        
        if ( place_here <= 0 )   // There isn't any empty space for this job
            continue ;  // We can't assign it here
        else    // We found a spot
            res[place_here] = jobs[i].second ;  //Add its profit
    }

    for ( auto &x : res )
        cout << x << " " ;
    cout << endl ;

    return accumulate(res.begin(),res.end(),0) ;    // Sum of all the profits
}

int main ()
{
    vector <pair<int,int>> arr1 = { {4,70} , {1,80} , {1,30} , {1,100} } ;
    vector <pair<int,int>> arr2 = { {2,50} , {2,60} , {3,20} , {3,30} } ;
    vector <pair<int,int>> arr3 = { {2,100} , {1,50} , {2,10} , {1,20} , {3,30} } ;

    cout << solve(arr1) << endl ;
    cout<< endl ;
    cout << solve(arr2) << endl ;
    cout << endl ;
    cout << solve(arr3) << endl ;
    cout << endl ;

    return 0 ;
}