# include <bits/stdc++.h>
using namespace std ;

// Implement stack data structure, when the library only provides the queue data structure
struct Stack {
    queue <int> q1 , q2 ;

    int cur_size ;

    Stack () { cur_size = 0 ; } // Default Constructor

    void push ( int x )
    {
        cur_size++ ;

        // Push x first in the empty q2
        q2.push(x) ;

        // Push all the remaning elements in q1 to q2
        while ( !q1.empty() )
        {
            q2.push(q1.front()) ;
            q1.pop() ;
        }

        // Push all elements from q2 to q1 (in O(1) by swapping their names )
        queue <int> q = q1 ;
        q1 = q2 ;
        q2 = q ;
    }

    void pop ()
    {
        if ( !q1.empty() )
            return ;
        
        q1.pop() ;
        cur_size-- ;
    }

    int top ()
    {
        if ( q1.empty() )
            return -1 ;

        return q1.front() ;
    }

    int size () { return cur_size ; }
};