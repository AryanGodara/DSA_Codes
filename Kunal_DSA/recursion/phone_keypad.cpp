# include <bits/stdc++.h>
using namespace std ;

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations
that the number could represent.
Return the answer in any order.
*/

vector <string> keypad = {
    "" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"
} ;

vector <string> ret ;   // Stores all the possible answers

void solve ( string str , int i , string cur = "" )
{
    // Base case, We've reached the end of the string
    if ( i >= str.length() )
    {
        if ( cur.length() == str.length() )
            ret.push_back(cur) ;
        return ;
    }
    //cout << "Cur = " << cur << " ,i = " << i << endl ;
    // Recursion

    // Go through each letter of keypad[str[i]], and then, go through all the subsequent nodes
    // And repeat the same process

    string cur_num = keypad[str[i]-'0'] ;

    for ( int j = 0 ; j < cur_num.length() ; j++ )
    {
        cur.push_back( cur_num[j] ) ;

        // Now go through the rest of the string 'str'
        for ( int k = i+1 ; k <= str.length() ; k++ )
        {
            // Call the function recursively for the subproblem
            solve(str,k,cur) ;
        }

        cur.pop_back() ;    // Backtrack, by removing cur_num[j], to make it ready
                            // for the next value in keypad[i]
    }
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;

    string str = "23" ;

    solve(str,0) ;

    for ( auto &x : ret )
        cout << x << " " ;
    cout << endl ;

    return 0 ;
}