# include <bits/stdc++.h>
using namespace std ;

// My Approach

void permute ( string str , int l , int r )
{
    if ( str.substr(0,l).find("AB") != string::npos )   // AB is found in this string till this pos
        return ;

    if ( l == r )
    {
        cout << str << endl ;
        return ;
    }

    for ( int i = l ; i <= r ; i++ )
    {
        swap(str[l],str[i]) ;
        permute(str , l+1 , r ) ;
        swap(str[l],str[i]) ;
    }
}

// GFG Approach

bool isSafe ( string str , int l , int i , int r )
{
    if ( (l != 0) && (str[l-1] == 'A') && (str[i] == 'B') )
        return false ;
    if ( r == l+1 && str[i] == 'A' && str[l] == 'B' )
        return false ;
    return true ;
}

void permute_bt ( string str , int l , int r )
{
    if ( l == r )
    {
        cout << str << endl ;
        return ;
    }

    for ( int i = l ; i <= r ; i++ )
    {
        if ( isSafe(str,l,i,r) ) ;
        swap(str[i],str[l]) ;
        permute(str,l+1,r) ;
        swap(str[i],str[l]) ;
    }
}

int main ()
{
    permute("ABC",0,2) ;
    cout << endl ;
    permute_bt("ABC",0,2) ;

    return 0 ;
}