# include <bits/stdc++.h>
using namespace std ;

//! O(N^3)
// Check each and every substring.
// O(N^2) to select start and end, then O(N) to check distinct

//? O(N^2)
int longest_distinct_better ( string str )
// Check the longest possible, from each index i
{
    int n = str.length() , res = 0 ;

    for ( int i = 0 ; i < n ; i++ )
    {
        vector <bool> visited(256,0) ;

        for ( int j = i ; j < n ; j++ )
        {
            if ( visited[str[j]] )
                break ;
            else
                res = max ( res , j-i+1 ) ;
                
            visited[str[j]] = true ;
        }
    }

    return res ;
}


//* O(N)
int longest_distinct_efficient ( string str )
{
    int n = str.length() , res = 0 ;
    vector <int> prev(256,-1) ;

    int i = 0 ;
    for ( int j = 0 ; j < n ; j++ )
    {
        i = max ( i , prev[str[j]]+1 ) ;
        int max_end = j-i+1 ;

        res = max ( res , max_end ) ;
        prev[str[j]] = j ;
    }

    return res ;
}


int main ()
{
    string str = "geeksforgeeks" ;
    cout << longest_distinct_efficient(str) << endl ;

    return 0 ;
}