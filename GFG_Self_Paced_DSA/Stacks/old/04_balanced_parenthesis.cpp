# include <bits/stdc++.h>
using namespace std ;

bool matching(char a,char b)
{
    return (( a=='(' && b==')' )||( a=='[' && b==']' )||( a=='{' && b=='}' ));
}
bool isBalanced ( string str )
{
    stack <char> s ;

    for ( int i = 0 ; i < str.length() ; i++ )
    {
        if ( str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.push(str[i]) ;
        else if ( s.empty() )
            return false ;
        else if ( !matching(s.top(),str[i]) )
            return false ;
        else
            s.pop() ;
    }

    return s.empty() ;
}