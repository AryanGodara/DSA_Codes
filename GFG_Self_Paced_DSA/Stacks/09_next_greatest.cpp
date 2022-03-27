# include <bits/stdc++.h>
using namespace std ;

// Given an array of distinct integers, find the NextGreater(position-wise closest and on the 
// right side) of every array elements.

vector <int> nextGreater ( vector <int> &arr , int n )
{
    vector <int> v ;
    stack <int> s ;

    s.push(arr[n-1]) ;
    v.push_back(-1) ;   // No greater element to the left of the rightmost element

    for ( int i = n-2 ; i >= 0 ; i-- )
    {
        while ( !s.empty() && s.top() <= arr[i] )
            s.pop() ;

        v.push_back( (s.empty() ? -1 : s.top()) ) ; // Store the answer
        
        s.push(arr[i]) ; // Push current element in the stack, for the next step
    }

    reverse(v.begin(),v.end()) ;

    return v ;
}

//? Driver Function
int main() 
{ 
    vector <int> arr = {5,15,10,8,6,12,9,18};
    int n=8;

    for( int &x: nextGreater(arr,n) )
        cout<<x<< " ";   

    return 0; 
}