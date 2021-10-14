# include <bits/stdc++.h>
using namespace std ;

/*
    Serving pie, N pies , F friends Plus 1 for me. Each gets a piece of pie. One pice of one pie,
    not from several pies. This pice can be one whole pie though.
    Each person should get equal amount of pie. Each has vol 1, but different radius.
    If a piece of pie goes unwasted, it's not an issue. What's the largest possible size?

    Input :-
    One line with two integers, N and F. 1 <= N,F <= 1e5.
    One line with N integers, r. , 1 <= ri <= 1e5
    Output :-
    Largest possible volume V (Since ) height = 1 , so, vol is just the value of the no. of
    pieces pie is divided into, and volume.
*/

const int N = 1e5+5 ;

const long double pi=3.14159265358979323846264338327950 ;
vector <double> arr(N) ;

int n , f ; // To avoid passing parameters.

double eps = 1e-4 ; // Accurate upto 4 decimal places

bool predicate ( double x )
{
    int to_feed = f ;

    for ( int i = 0 ; i < n ; i++ )
        to_feed -= ((int)(arr[i])/f) ;// This is the no. of pie pieces, we can obtain from this pie
    return (to_feed<=0) ; // This should at least be enough to feed everyone
}

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int T ;
    cin >> T ;

    while ( T-- )
    {
        // Store the volume in each element
        double temp ;
        cin >> n >> f ;
        f++ ;   // One plate for yourself :)

        for ( int i = 0 ; i < n ; i++ )
        {
            cin >> arr[i] ;
            arr[i] = pi*arr[i]*arr[i] ;
        }
        
        sort(arr.begin(),arr.end()) ;

        double beg = 0 , end = arr[n-1];

        // Now, we do a binary search for all possible value of vol, which starts from
        // a lo = 0 and hi = min_element(arr) ;

        while ( end - beg > eps )
        {
            int mid = beg + (end-beg)/2 ;

            if ( predicate(mid) )  // Possible solution, it can also be after this
                beg = mid ;
            else    // Not a possible soln, hence also out of the solution space
                end = mid-1 ;
        }

        // Using monotonous predicate function, we have to find the last T value, the max size
        if ( predicate(end) )
            cout << end << endl ;
        else // Since it's guaranteed that a valid height WILL be found, no need to check for beg
            cout << beg << endl ;
    }

    return 0 ;
}