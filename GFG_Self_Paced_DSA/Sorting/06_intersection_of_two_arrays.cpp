//? We don't want to print any duplicates
//? Both arrays are already Sorted

# include <bits/stdc++.h>
using namespace std ;

void printIntersection ( int a[] , int b[] , int m , int n )
{
    int i = 0 , j = 0 ;

    while ( i < m && j < n )
    {
        if ( i>0 && a[i] == a[i-1] )    //? We use a[] for printing the elements
        {
            i++ ;
            continue ;
        }

        if ( a[i] < b[j] ) {
            i++ ;
        }
        else if ( a[i] > b[j] ) {
            j++ ;
        }
        else {
            cout << a[i] << " " ;
            i++ , j++ ;
        }
    }
}

int main ()
{
    int a[] = {3,5,10,10,15,15,20} , b[] = {5,10,10,15,30} ;
    int m = sizeof(a)/sizeof(a[0]) , n = sizeof(b)/sizeof(b[0]) ;

    printIntersection(a,b,m,n) ;

    return 0 ;
}