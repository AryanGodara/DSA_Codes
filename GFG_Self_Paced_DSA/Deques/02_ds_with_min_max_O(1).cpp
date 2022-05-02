//? Design a Data Structure that supports the following operations in O(1) time complexity :-
// 1. insertMin(x)
// 2. insertMax(x)
// 3. getMin()
// 4. getMax()
// 5. extractMin()
// 6. extractMax()

# include <iostream>
# include <cmath>
# include <bits/stdc++.h>
# include <climits>
# include <deque>

using namespace std ;

struct MyDS 
{
    deque <int> dq ;


    void insertMin ( int x ) { dq.push_front(x) ; }

    void insertMax ( int x ) { dq.push_back(x) ; }

    int getMin () { return dq.front() ; }

    int getMax () { return dq.back() ; }

    int extractMin ()
    {
        int x = dq.front() ;
        dq.pop_front(); 

        return x ;
    }

    int extractMax ()
    {
        int x = dq.back() ;
        dq.pop_back() ;

        return x ;
    }
};