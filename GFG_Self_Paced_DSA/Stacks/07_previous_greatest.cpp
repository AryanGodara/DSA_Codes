// Given an array of distinct integers, find the closest (positive wise) greater on left of
// every element. If there is no greater element on left, print -1

# include <bits/stdc++.h>
using namespace std ;

void prev_greater ( int arr[] , int n )
{
    stack <int> st ;
    st.push(arr[0]) ;

    for ( int i = 0 ; i < n ; i++ )
    {
        while ( !st.empty() && st.top() <= arr[i] )
            st.pop() ;
        
        cout << ( st.empty() ? -1 : st.top() ) << " " ;

        st.push(arr[i]) ;
    }
}

int main ()
{
    int arr[] = {20,30,10,5,10} ;

    int n = 5 ;

    prev_greater(arr,n) ;
}