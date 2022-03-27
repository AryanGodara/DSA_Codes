# include <bits/stdc++.h>
using namespace std ;

//? Naive Approach
void printSpan_naive ( int arr[] , int n )
{
    for ( int i = 0 ; i < n ; i++ )
    {
        int span = 1 ;

        for ( int j = i-1 ; j >= 0 && arr[j] <= arr[i] ; j-- )
            span++ ;
        
        cout << span << " " ;
    }
}

void print_span_efficient ( int arr[] , int n )
{
    stack <int> st ;

    st.push(0) ;
    cout << "1 " ;

    for ( int i = 1 ; i < n ; i++ )
    {
        while ( !st.empty() && arr[st.top()] <= arr[i] ) // Remove all the greater elements
            st.pop() ;

        cout << ( st.empty() ? i+1 : i-st.top() ) << " " ;

        st.push(i) ;
    }
}


//? Driver Function
int main ()
{
    int arr[] = {18,12,13,14,11,16} ;
    int n = 6 ;

    printSpan_naive(arr,n) ;
    cout << endl ;
    print_span_efficient(arr,n) ;

    return 0 ;
}