//? Using sort() function, using custom objects, and comparator functions.

# include <bits/stdc++.h>
using namespace std ;

struct Point {
    int x, y ;
};

bool cmp ( Point a , Point b )
{
    if ( a.x != b.x )
        return a.x < b.x ;
    return a.y <= b.y ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Point arr[] = { {3,10} , {2,8} , {2,7} , {3,10} , {5,4} } ;

    int n = sizeof(arr)/sizeof(arr[0]) ;

    sort(arr , arr+n , cmp ) ;

    for ( auto &point : arr )
        cout << point.x << " " << point.y << endl ;

    return 0 ;
}

/*
? Stable Sorting Algorithms :-
* Bubble Sort
* Insertion Sort
* Merge Sort

? Unstable Sorting Algorithms :-
* Selection Sort
* Quick Sort
* Heap Sort

*/