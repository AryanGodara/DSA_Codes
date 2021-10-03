# include <bits/stdc++.h>
using namespace std ;

void intersection ( int a[] , int b[] , int m , int n )
{
    int i = 0 , j = 0 ;

    while ( i < m && j < n )
    {
        if ( i > 0 && a[i] == a[i-1] )  // Duplicate Element
        {
            i++ ;   continue ;
        }
        if ( a[i] < b[i] )
        {
            i++ ;   continue ;
        }
        if ( a[i] > b[i] )
        {
            j++ ;   continue ;
        }
        if ( a[i] == b[i] )
        {
            cout << a[i] << endl ;    i++ ;    j++ ;
        }
    }
}

int main ()
{
    int a[] = { 1 , 20 , 20 , 40 , 60 } ;
    int b[] = { 2 , 20 , 20 , 40 } ;

    intersection(a,b,sizeof(a)/sizeof(a[0]),sizeof(a)/sizeof(a[0])) ;

    return 0 ;
}