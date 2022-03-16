//? Check if both strings are anagrams of each other

# include <bits/stdc++.h>
using namespace std ;

//* Naive solution is just sorting the strings, and checking if they become equal :P

//* Efficient method is using a hashmap to store the count of each character in the strings

const int CHAR = 256 ;  //! ASCII values are from 0 to 255

bool are_anagram ( string &s1 , string &s2 )
{
    int n1 = s1.length() , n2 = s2.length() ;
    
    if ( n1 != n2 )
        return false ;

    vector <int> count (CHAR,0) ;

    for ( int i = 0 ; i < n1 ; i++ )    // n1 == n2
        count[s1[i]]++ , count[s2[i]]-- ;   // Overall should get cancelled out
    
    for ( int i = 0 ; i < CHAR ; i++ )
        if ( count[i] ) // This one wasn't zero, so there was a difference in characters
            return false ;
        
    return true ;
}

// Driver Function
int main ()
{
    string s1 = "abaac" , s2 = "aacba" ;

    cout << boolalpha << are_anagram(s1,s2) << endl ;

    return 0 ;
}