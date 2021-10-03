/*
The Standard Template Library in C++ offers a built-in implementation of the Queue data structure
for simpler and easy use. The STL implementation of queue data structure implements all basic 
operations such as enque() , deque() , clear() , etc.
*/

// SYNTAX :-
/*
    queue <data_type> queue_name ;
*/

// The functions supported by std::queue are :
/*
1. empty(): returns whether the queue is empty
2. size(): returns the size of the queue
3. swap(): exchange the contents of two queues, but they must be of the same data type, size may differ
4. emplace(): insert a new element, at the end of the queue container
5. front() and back(): the normal functioning, as discussed previously.
6. push() and pop(): add element at the end, and delete the first element, respectively.
*/


// Sample Program

# include <bits/stdc++.h>
using namespace std ;

void showq ( queue <int> gq )
{
    queue <int> g = gq ;
    while ( ! g.empty() )
    {
        cout << g.front() << endl ;
        g.pop() ;
    }
    cout << endl ;
}

int main ()
{
    queue <int> gquiz ;
    gquiz.push(10) ;
    gquiz.push(20) ;
    gquiz.push(30) ;

    cout << "The queue gquiz is : \n" ;
    showq(gquiz) ;

    cout << endl ;

    cout << "gquiz.size() = " << gquiz.size() << endl ;
    cout << "gquiz.front() = " << gquiz.front() << endl ;
    cout << "gquiz.back() = " << gquiz.back() << endl ;

    cout << "\ngquiz.pop()\n" ;
    gquiz.pop() ;
    showq(gquiz) ;

    return 0 ;
}