//? Given a string, find the first character (whose leftmost appeareance is first) that repeats

# include <bits/stdc++.h>
using namespace std ;

//! Super naive solution O(N^2)
int leftMost ( string &str , int n )
{
    for ( int i = 0 ; i < n ; i++ )
        for ( int j = i+1 ; j < n ; j++ )
            if ( str[i] == str[j] ) // First repeating character
                return i ;
    
    return -1 ; // No repeating characters
}

// Better Approach O(N) but also uses O(256) auxillary space
const int CHAR=256;
int leftMost(string &str) 
{
    int count[CHAR] = {0} ;

    for(int i = 0 ; i <str.length() ; i++ )   // Store the frequency of all the characters
        count[str[i]]++ ;

    for(int i = 0 ; i < str.length() ; i++ )
        if ( count[str[i]] > 1 )
            return i ;

    return -1;
}

//* Efficient Approach 1
int left_most_1 ( string s , int n )
{
    vector <int> fIndex (CHAR,-1) ; // Stores the count of first occurence of character

    int res = INT_MAX ;

    for ( int i = 0 ; i < n ; i++ )
    {
        int fi = fIndex[s[i]] ;   // The first occurence of str[i], else -1
        
        if ( fi == -1 ) // This is the first appearance
            fIndex[s[i]] = i ;
        else
            res = min ( res , fi ) ;    // Make sure that this is the "first" repeating char
    }

    return (res == INT_MAX) ? -1 : res ;
}

//* Efficient Approach 2
int leftmost ( string s , int n )
{
    vector<bool> visited (CHAR,false) ;

    int res = -1 ;

    // The last character that we find repeating, means that it is the answer
    //* No need to check the minimum res here, like we did above
    for ( int i = n-1 ; i >= 0 ; i-- )  // Traverse from right to left
    {
        if ( visited[s[i]] )
            res = i ;   // This MAY be the solution
        else
            visited[s[i]] = true ;    // Mark this one as visited
    }

    return res ;
}

int main ()
{
    string s = "geeksforgeeks" ;

    cout << leftmost(s,s.length()) << endl ;

    return 0 ;
}