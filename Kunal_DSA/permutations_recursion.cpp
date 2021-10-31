# include <bits/stdc++.h>
using namespace std ;

vector <string> ret ;

void permutations ( string &str , int n , int i ) // All the permutations of a string
{
    // Base Case
    if ( i == n-1 )   // We've traversed the entire string, so we add it to the result
    ret.push_back ( str ) ;

    // Recursion

    for ( int j = i ; j < n ; j++ )
    {
        swap ( str[i] , str[j] ) ;
        permutations ( str , n , i+1 ) ;
        swap ( str[i] , str[j] ) ;
    }
}


// 2nd Method ( From the CP Handbook )
vector<bool>chosen(3) ; // 0 = false , 1 = false , 2 = false

void permutation ( vector <string> &ret , string &str , string &cur  , int i )
{
    // Base Case
    if ( i == str.size() )
    {
        ret.push_back(cur) ;
        return ;
    }

    // Recursion
    for ( int j = 0 ; j < str.length() ; j++ )
    {
        if ( chosen[j] )
            continue ;
            
        chosen[j] = true ;
        
        cur.push_back( str[j] ) ;

        permutation (ret,str,cur,i+1) ;

        chosen[j] = false ; // Backtracking

        cur.pop_back() ;    // Backtracking
    }
}


// Driver Function
int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    // 1st Method
    string str = "abc" ;

    permutations(str , str.length() , 0) ;

    for ( auto &x : ret )
        cout << x << " " ;
    cout << endl << endl ;


    // 2nd Method
    vector<string> res ;
    string s = "abc" , cur = "" ;

    permutation(res,s,cur,0) ;

    for ( auto &x : res )
        cout << x << " " ;
    cout << endl << endl ;


    // 3rd Method
    do
    {
        cout << str << " " ;
    } while ( next_permutation( str.begin(),str.end() ) ) ;
    cout << endl << "str now = " << str << " (Back to Normal)" << endl ;

    return 0 ;
}