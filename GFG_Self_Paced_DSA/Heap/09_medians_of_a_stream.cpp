# include <bits/stdc++.h>
using namespace std ;

// Naive Solution ( Maintaining Sorted Array )



// Better Solution ( Using Augmented BST )

void print_medians ( vector <int> &arr )
{
    int n = arr.size() ;

    priority_queue <int> s ;    // Max Heap
    priority_queue <int,vector<int>,greater<int>> g ; // Min Heap

    s.push(arr[0]) ;
    cout << arr[0] << " " ;

    for ( int i = 1 ; i < n ; i++ )
    {
        int x = arr[i] ;

        if ( s.size() > g.size() )
        {
            if ( s.top() > x )
            {
                g.push(s.top()) ;
                s.pop() ;
                s.push(x) ;
            }
            else
                g.push(x) ;
            cout << ( s.top() + g.top() ) / 2.0 << " " ; // Even no. of elements are present

        }
        else
        {
            if ( x <= s.top() )
                s.push(x) ;
            else
            {
                g.push(x) ;
                s.push(g.top()) ;
                g.pop() ;
            }
            cout << s.top() << " " ;
        }
    }
    cout << endl ;
}

// Efficient Solution



// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    vector <int> arr = { 12 , 15 , 10 , 5 , 8 , 7 , 16 } ;

    print_medians (arr) ;

    return 0 ;
}