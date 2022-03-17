# include <bits/stdc++.h>
using namespace std ;

bool areRotations ( string s1 , string s2 )
{
    if ( s1.length() != s2.length() )
        return false ;
    
    return ( (s1+s1).find(s2) != string::npos ) ;
    // npos = Value returned by various member functions when they fail.
}

int main ()
{
    string s1 = "ABCD" , s2 = "CDAB" ;

    cout << boolalpha << areRotations(s1,s2) << endl ;

    return 0 ;
}