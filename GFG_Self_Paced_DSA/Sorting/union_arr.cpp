// Union of two sorted arrays
# include <bits/stdc++.h>
using namespace std ;

void unionarr ( int a[] , int b[] , int m , int n )
{
    int i = 0 , j = 0 ;

    while ( i < n && j < n )
    {
        if ( i > 0 && a[i] == a[i+1] )
        {
            i++ ;   continue ;
        }
        if ( j > 0 && b[j] == b[j+1] )
        {
            j++ ;   continue ;
        }
        // These two were to avoid duplicates

        if ( a[i] < b[i] )      // print a[i], the smaller element
        {
            cout << a[i] << endl ;
            i++ ;
        }
        else if ( a[i] > b[j] ) // print b[j], the smaller element
        {
            cout << b[j] << endl ;
            j++ ;
        }

        else    // Both are equal
        {
            cout << a[i] << endl ;
            i++ ;   j++ ;
        }
    }       // Now when this loop ends, one array is left which is not yet comleted

    while ( i < m )
    {
        if ( i == 0 || a[i] != a[i-1] )
        {
            cout << a[i] << endl ;
            i++ ;
        }
    }
    while ( j < n )
    {
        if ( j == 0 || b[j] != b[j-1] )
        {
            cout << b[j] << endl ;
            j++ ;
        }
    }
}

int main ()
{
    int a[] = { 1 , 20 , 20 , 40 , 60 } ;
    int b[] = { 2 , 20 , 20 , 40 } ;

    unionarr(a,b,sizeof(a)/sizeof(a[0]),sizeof(a)/sizeof(a[0])) ;

    return 0 ;
}