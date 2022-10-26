//? Next greater element
# include <bits/stdc++.h>
using namespace std ;

vector <int> next_greater ( int arr[] , int n )
{
    vector <int> ret(n,-1) ;

    stack <int> s ;
    s.push(arr[n-1]) ;

    for ( int i = n-2 ; i >= 0 ; i-- )
    {
        while ( !s.empty() && s.top() <= arr[i] )
            s.pop() ;

        int ng = s.empty() ? -1 : s.top() ;

        ret[i] = ng ;
        s.push(arr[i]) ;
    }

    return ret ;
}

int main ()
{
    int arr[] = {5,15,10,8,6,12,9,18} ;

    int n = 8 ;

    for ( int x: next_greater(arr,n) )
        cout << x << " " ;
    
    return 0 ;
}