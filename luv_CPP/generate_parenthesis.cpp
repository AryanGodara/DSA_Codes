// Given n pairs of parenthesis, write a function to generate all combinations of well-formed
// parenthesis

# include <bits/stdc++.h>
using namespace std ;


vector <string> valid_strings ;

class Solution
{
    public :

    void generate ( string &str , int open , int close )
    {
        if ( open == 0 && close == 0 )  // We've found a valid string
        {
            valid_strings.push_back(str) ;
            return ;
        }
        
        if ( open > 0 )
        {
            str.push_back('(') ;
            generate( str , open-1 , close ) ;

            str.pop_back() ;    // Backtracking
        }

        if ( close > 0 )
        {
            if ( open < close )
            {
                str.push_back(')') ;
                generate( str , open , close-1 ) ;

                str.pop_back() ;    // Backtracking
            }
        }
    }

} ;

int main ()
{
    int n ;
    cin >> n ;

    Solution obj ;

    string s = "" ;
    obj.generate( s , n , n ) ;

    for ( auto &x : valid_strings )
        cout << x << endl ;

    return 0 ;
}