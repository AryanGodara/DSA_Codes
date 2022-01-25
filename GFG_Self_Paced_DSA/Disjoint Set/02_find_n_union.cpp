//? A simple representation of find() and union() operations

# include <bits/stdc++.h>
using namespace std ;

# define n 5

int parent[n] ;

void initialize ()
{
    for ( int i = 0 ; i < n ; i++ )
        parent[i] = i ;
}

int find ( int x )
{
    if ( x == parent[x] )
        return x ;
    return find(parent[x]) ;
}

void unions ( int x , int y )
{
    x = find(x) ;
    y = find(y) ;

    if ( x != y )
        parent[y] = x ;
}


// Driver Function
int main () 
{

    initialize();

    unions(0,2) ;
    unions(0,4) ;

    cout << find(4) << endl << find(3) << endl ;

    return 0 ;
}