// Find the lexiographic rank of a string ( position in a dictionary )
// We find all the words, with lower rank, than the given string, and add 1 to the result
// ( Same as the method using in Permutations and Combinations in School )

# include <bits/stdc++.h>
using namespace std ;

const int CHAR = 256 ;

bool cmp ( char a , char b )
{
    return a > b ;
}

int fact ( int n )
{
    return ( (n<=1) ? 1 : n*fact(n-1) ) ;
}

int lexorank ( string &str , int n )
{
    int res = 1 ;   // The minimum rank is one
    int mul = fact(n) ;
    
    if ( is_sorted(str.begin(),str.end()) )
        return 1 ;
    if ( is_sorted ( str.begin(),str.end(),cmp) )
        return mul ;
    
    // Now, the main function
    int count[CHAR] = {0} ;

    for ( int i = 0 ; i < n ; i++ )
        count[str[i]]++ ;
    for ( int i = 1 ; i < CHAR ; i++ )
        count[i] += count[i-1] ;   
    // Now count 
    for ( int i = 0 ; i < n-1 ; i++ )// for str[n-1] , mul /= 1, and count[str[i]-1] = count[0] = 0
    {
        mul /= (n-i) ; // mul goes from n! to n-1! to n-2!, and so on till it reaches 1! = 1.

        res += count[str[i] - 1]*mul ;
        for ( int j = str[i] ; j < CHAR ; j++ )
            count[j]-- ;    // This removes this character from the count array.
    }// This way we only count the smaller characters on the right side
    return res ;
}

int main ()
{
    string str = "string" ;

    cout << lexorank(str,str.length()) << endl ;

    return 0 ;
}