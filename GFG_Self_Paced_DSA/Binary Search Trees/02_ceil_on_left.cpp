# include <bits/stdc++.h>
using namespace std ;

/*
    Given an array, print the ceiling on the left side, for each side of the array.
    (For each element, if there is an element greater than or equal to that elemeent on its
    left of that element in the array. Else, print -1 for that element.)
*/

void print_ceiling ( vector <int> arr )
{
    cout << "-1 " ;
    
    set<int> s ;
    s.insert(arr[0]) ;

    for ( int i = 1 ; i < arr.size() ; i++ )
    {
        if ( s.lower_bound(arr[i]) != s.end() )
            cout << *(s.lower_bound(arr[i])) << " " ;
        else
            cout << "-1 " << " " ;
        s.insert(arr[i]) ;
    }
}


// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    vector <int> arr = { 2 , 15 , 30 , 15 , 25 , 12 } ;

    print_ceiling(arr) ;

    return 0 ;
}