# include <bits/stdc++.h>
using namespace std ;

// Considering only positive elements
struct MyStack1 {   
    stack <int> s ;
    int min ;

    void push ( int x )
    {
        if ( s.empty() )
        {
            min = x ;
            s.push(x) ;
        }
        else if ( x <= min )
        {
            s.push(x-min) ; // -ve element pushed into the stack
            min = x ;
        }
        else 
        {
            s.push(x) ;
        }
    }

    int pop ()
    {
        int t = s.top();
        s.pop() ;

        if ( t <= 0 )   // The top element was smaller than the previous min
        {
            int res = min ; // The current minimum
            min = min-t ;   // Going back to the previous min: t = new_min - prev_min

            return res ;
        }
        else    // The current top wasn't the min element, so no update is needed
            return t ;
    }

    int top ()
    {
        int t = s.top() ;

        return ( t <= 0 ? min : t ) ;
    }

    int getMin () { return min ; }
};

// Both positive and negative numbers are allowed
struct MyStack {    
    stack <int> s ;
    int min ;

    void push ( int x )
    {
        if ( s.empty() )
        {
            min = x ;
            s.push(x) ;
        }
        else if ( x <= min )
        {
            s.push(2*x - min) ;
            min = x ;
        }
        else
        {
            s.push(x) ;
        }
    }

    int pop ()
    {
        int t = s.top() ;
        s.pop() ;

        if ( t <= min ) // Current top element is equal to the current min element
        {
            int res = min ;
            min = 2*min - t ;

            return res ;
        }
        else    // Current top is not the min, so no changes required
            return t ;
    }

    int top ()
    {
        int t = s.top() ;

        return ( t <= min ? min : t ) ;
    }

    int getMin () { return min ; }
};