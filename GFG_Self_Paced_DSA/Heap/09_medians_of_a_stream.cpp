# include <bits/stdc++.h>
using namespace std ;

// Naive Solution ( Maintaining Sorted Array )
void naive_print_medians ( vector<int> &arr )
{
    int n = arr.size() , size = 0 ;
    vector <double> temp (n) ;

    for ( int i = 0 ; i < n ; i++ )
    {
        temp[i] = arr[i] ;
        size++ ;
        int j = i ;
        while ( j>0 && temp[j]<temp[j-1] )
        {
            swap(temp[j],temp[j-1]) ;
            j-- ;
        }

        if ( size & 1 ) // Odd number of elements
            cout << temp[size/2] << " " ;
        else            // Even no. of elements
            cout << (temp[size/2]+temp[(size-1)/2])/2 << " " ;
    }
    cout << endl ;
}

// Efficient Solution ( Using Augmented BST )
void print_medians ( vector <int> &arr )
{
    int n = arr.size() ;

    priority_queue <int> s ;    // Max Heap     // s === smaller heap
    priority_queue <int,vector<int>,greater<int>> g ; // Min Heap   // g === greater heap

    s.push(arr[0]) ;
    cout << arr[0] << " " ;

    for ( int i = 1 ; i < n ; i++ )
    {
        int x = arr[i] ;

        if ( s.size() > g.size() )  // The max item needs to be placed in the second heap
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