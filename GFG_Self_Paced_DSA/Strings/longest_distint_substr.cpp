// Find the longest substring of a string, that has unique characters
# include <bits/stdc++.h>
using namespace std ;

// Naive ( Better ) Solution :- O(n^2)
/*

int longestDistinct ( string str )
{
    int n = str.size() ;
    int res = 0 ;

    for ( int i = 0 ; i < n ; i++ )
    {
        vector<bool> visited(256) ;
        for ( int j = i ; j < n ; j++ )
        {
            if ( visited[str[i]] == true )
                break ;
            else
            {
                res = max(res,j=i+1) ;
                visited[str[i]] = true ;
            }
        }
    }
    return res ;
}

*/

// Efficient Solution :- O(n)
/*
    maxEnd(j) = length of the longest substring that has distinct characters, and ends at j.
    res = ForLoop(j = 0 , to n-1) max(maxEnd(j))

    maxEnd(j) = { maxEnd(j-1) + 1 , if str[j] is not present in maxEnd(j-1)
                { j - prev(str[i]) + 1 , where prev(str[j]) = previous index of the character str[j]
*/

int longestDistinct ( string str )
{
    int n = str.length() , res = 0 ;
    vector <int> prev (256,-1) ;
    
    int i = 0 ;
    for ( int j = 0 ; j < n ; j++ )
    {
        i = max( i , prev[str[j]] + 1 ) ;
        int maxEnd = j-i+1 ;
        res = max(res,maxEnd) ;
        prev[str[j]] = j ;  // Stores the previous position of this character
    }

    return res ;
}

int main ()
{
    string str = "geeksforgeeks" ;
    
    cout << longestDistinct(str) << endl ;

    return 0 ;
}