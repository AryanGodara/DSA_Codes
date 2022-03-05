# include <bits/stdc++.h>
using namespace std ;

//? We don't want to print any duplicates

void printUnion ( int a[] , int b[] , int m , int n )
{
    int i = 0 , j = 0 ;

    while ( i < m && j < n )
    {
        if ( i>0 && a[i-1] == a[i] )
        {
            i++ ;
            continue ;
        }
        if ( j>0 && b[j-1] == b[j] )
        {
            j++ ;
            continue ;
        }


        if ( a[i] < b[j] )
        {
            cout << a[i] << " " ;
            i++ ;
        }
        else if ( a[i] > b[j] )
        {
            cout << b[j] << " ";
            j++ ;
        }
        else    // Both are equal
        {
            cout << a[i] << " " ;   // or cout cout <<b[j] ; // Doesn't matter
            i++ ;
            j++ ;
        }
    }

    while ( i < m )
    {
        if ( i==0 || a[i] != a[i-1] )
            cout << a[i] << " " ;
        i++ ;
    }

    while ( j < n )
    {
        if ( j==0 || b[j] != b[j-1] )
            cout << b[j] << " " ;
        j++ ;
    }
}

int main ()
{
    int a[] = {3,8,8} , b[] = {2,8,8,10,15} ;
    int m = sizeof(a)/sizeof(a[0]) , n = sizeof(b)/sizeof(b[0]) ;

    printUnion(a,b,m,n) ;

    return 0 ;
}