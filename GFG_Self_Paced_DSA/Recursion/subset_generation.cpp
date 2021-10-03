# include <bits/stdc++.h>
using namespace std ;

// You are given a string, and you need to print its lexographically increasing powerset

// Function to generate powerset of the string
void PowerSetUtil ( string &str , vector<string> &v , int index = 0 , string curr = "" )
{
    int n = str.length() ;

    // Base case
    if ( index == n )
    {
        v.push_back(curr) ;
        return ;
    }

    // Recursive Steps

    // Two cases for every character :-
    // 1. We consider the character as a part of this subset
    // 2. We don't consider the character as a part of this subset

    PowerSetUtil(str , v , index + 1 , curr + str[index] ) ;
    PowerSetUtil(str , v , index + 1 , curr ) ;
}

// Function to return the lexographically sorted powerset of the string
vector <string> powerSet ( string s )
{
    vector <string> ans ;   // Declare an empty vector of strings
    PowerSetUtil(s,ans) ;   // It automatically takes the values for the last two parameters

    // Now the powersetutil function has updated the vector string. Now return this string
    return ans ;
}

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int T ;
    cin >> T ;

    while ( T-- )
    {
        string s ;
        cin >> s ;

        // Calling the powerSet() function
        vector <string> ans = powerSet(s) ;

        // Printing the Result
        for ( auto &x : ans )
            cout << x << " " ;
        
        cout << endl ;
    }

    return 0 ;
}