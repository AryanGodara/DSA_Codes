# include <bits/stdc++.h>
using namespace std ;

string to_bin ( int x )
{
    string res = "" ;
    while ( x )
    {
        res += (char)( (x&1) + '0' ) ;
        x /= 2 ;
    }
    reverse(res.begin(),res.end()) ;

    return res ;
}

int main ()
{
    cout << to_bin(13) << endl ;
    cout << to_bin(~13) << endl ;
    cout << 0 << to_bin((1 <<(int)log2(13))-1) << endl ;

    return 0 ;
}