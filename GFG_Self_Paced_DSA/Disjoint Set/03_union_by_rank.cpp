//? A simple representation of find() and union() operations

# include <bits/stdc++.h>
using namespace std ;

# define n 5

int parent[n] ;
int ranks[n] ;

void initialize ()
{
    for ( int i = 0 ; i < n ; i++ )
    {
        parent[i] = i ; 
        ranks[i] = 0 ;
    }
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

    if ( x == y )
        return ;
    
    if ( ranks[x] < ranks[y] )    // Attach smaller tree to the bigger tree
        parent[x] = y ;
    else if ( ranks[y] > ranks[x] )
        parent[y] = x ;
    else        // Both have same ranks, to rank of x will increase if we attach y to it
    {
        parent[y] = x ;
        ranks[x]++ ;
    }
}


// Driver Function
int main () 
{
    ios_base :: sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    initialize();

    unions(3,4) ;
    unions(2,3) ;
    unions(1,2) ;
    unions(0,1) ;
    
    cout << parent[3] << endl ;
    cout << ranks[3] << endl ;

    return 0 ;
}