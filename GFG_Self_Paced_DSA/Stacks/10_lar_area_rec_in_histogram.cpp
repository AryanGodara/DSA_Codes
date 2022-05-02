//? Calculate the Ara of the largest rectangle in a histogram

# include <bits/stdc++.h>
using namespace std ;

//? Better Solution (Naive = O(N^2))
int get_max_area ( int arr[] , int n )
{
    int res = 0 ;

    int ps[n] , ns[n] ; // Previous smaller , next smaller

    stack <int> s ;
    s.push(0) ;

    for ( int i = 0 ; i < n ; i++ ) // Previuos smaller element for each element
    {
        while ( !s.empty() && arr[s.top()] >= arr[i] )
            s.pop() ;
        
        int pse = s.empty() ? -1 : s.top() ;
        ps[i] = pse ;
        s.push(i) ;
    }

    while ( !s.empty() )
        s.pop() ;
    
    s.push(n-1) ;

    for ( int i = n-1 ; i >= 0 ; i-- )  // Next smaller element for each element
    {
        while ( !s.empty() && arr[s.top()] >= arr[i] )
            s.pop() ;
        
        int nse = s.empty() ? n : s.top() ;
        ns[i] = nse ;
        s.push(i) ;
    }

    // Finding the solution
    for ( int i = 0 ; i < n ; i++ )
    {
        int cur = arr[i] ;

        cur += (i - ps[i] - 1) * arr[i] ;
        cur += (ns[i] - i - 1) * arr[i] ;

        res = max ( res , cur ) ;
    }

    return res ;
}

//? Efficient Solution
int getMaxArea ( int arr[] , int n )
{
    stack <int> s ;

    int res = 0 , tp , cur ;

    for ( int i = 0 ; i < n ; i++ )
    {
        while ( !s.empty() && arr[s.top()] >= arr[i] )  // Find previous smaller element
        {
            tp = s.top() ;
            s.pop() ;

            cur = arr[tp] * ( s.empty() ? i : i-s.top()-1 ) ;

            res = max ( cur , res ) ;
        }

        s.push(i) ;
    }

    while ( !s.empty() )    // These elements have no smaller element on the right
    {
        tp = s.top() ;
        s.pop() ;

        cur = arr[tp] * ( s.empty() ? n : n-s.top()-1) ;

        res = max ( res , cur ) ;
    }

    return res ;
}

//? Driver Function
int main ()
{
    int arr[] = {6,2,5,4,1,5,6} ;

    int n = 7 ;

    cout << "Maximum Area1 : " << get_max_area(arr,n) << endl ;
    cout << "Maximum Area2 : " << getMaxArea(arr,n) << endl ;

    return 0 ;
}