/*
    Write a function that takes a string as input, and outputs all the permutations of the
    given string
*/
# include <bits/stdc++.h>
using namespace std ;

void permute ( string s , int i )
{
    if ( i == s.length()-1 )
    {
        cout << s << endl ;
        return ;    // To avoid further unecessary recursive calls.
    }
    for ( int j = i ; j < s.length() ; j++ )    // All permutations after i^th element
    {
        swap(s[i],s[j]) ;
        permute(s,i+1) ;
        swap(s[i],s[j]) ;   // Back to normal
    }
}

int main ()
{
    string str = "ABC" ;
    permute(str,0) ;
    return 0 ;   
}