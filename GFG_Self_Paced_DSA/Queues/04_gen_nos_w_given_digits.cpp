//? Given a number n, print first n numbers ( in increasing order ) such that all these numbers
//? have digits in the set {5,6}

//* eg.: n = 10 :- 5, 6, 55, 56, 65, 66, 555, 556, 565, 566

//! n can be a very big number, and the result values may not fit in basic data types like
//! long int or long long int

# include <bits/stdc++.h>
using namespace std ;

void printFirstN ( int n )
{
    queue<string> q ;

    q.push("5") ;
    q.push("6") ;

    for ( int i = 0 ; i < n ; i++ )
    {
        string cur = q.front() ;

        cout << cur << " " ;

        q.pop() ;

        q.push(cur+"5") ;
        q.push(cur+"6") ;
    }
}