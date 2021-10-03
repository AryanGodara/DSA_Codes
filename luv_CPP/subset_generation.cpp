# include <bits/stdc++.h>
using namespace std ;

void generate_subsets ( string &str , string &res , int i )
{
    // Base Case
    if ( i == str.length() )
    {
        cout << res << endl ;
        return ;
    }

    // Recursion

    res = res + str[i] ;
    generate_subsets(str,res,i+1) ;

    res.pop_back() ;

    generate_subsets(str,res,i+1) ;


}

int main ()
{
    string str = "ABC" , res = "" ;

    generate_subsets(str,res,0) ;
}