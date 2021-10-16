/*
    Count A + B + C Subsequences
    1. You are given a string str
    2. You are required to find calculate and print the count of subsequences of the nature a+b+c

    eg.:
    abbc -> 3 : abc , abc , abbc
    abcabc -> 7 : abc , abc , aabc , abbc , abcc , abc , abc
*/
# include <bits/stdc++.h>
using namespace std ;
/*
    Approach :-

    Appending 'a'
    We can't append a to 'ab' because that will make it 'aba', which doesn't follow the pattern.
    Similarly, we can't append to 'abc','aabc'. So one pattern arises that if we had to append 'a'
    to some strings, such that after appending it follows the 'a+b+c pattern', then for sure the
    string has to be a+ like 'a', 'aaa' or 'aaaa

    Appending 'b'
    We can't append 'b' to 'abc'. We can only append it to 'a+b+' or 'a+'.

    Appending 'c'
    We can only append it to 'a+b+' or 'a+b+c+'
*/

int solve ( string str )
{
    int n = str.length() ;

    int a = 0 , ab = 0 , abc = 0 ;  // Count of each type of valid strings

    for ( int i = 0 ; i < n ; i++ ) // Traverse the entire string
    {
        if ( str[i] == 'a' )
            a = 2*a + 1 ;
        // We double the no. of existing 'a+' strings by appending to them, plus we just got a new
        // string of type 'a'

        else if ( str[i] == 'b' )
            ab = a + 2*ab ;
        // All strings of type 'a' are converted to type 'ab', and for the existing 'ab' strings,
        // we follow the same pattern as we did in the case of str[i]=='a'

        else if ( str[i] == 'c' )
            abc = ab + 2*abc ;
    }

    return abc ;    // The count of all strings of type 'a+b+c'
}

// Driver Function
int main ()
{
    cout << solve("abbc") << endl ;
    cout << solve ("abcabc") << endl ;

    return 0 ;
}