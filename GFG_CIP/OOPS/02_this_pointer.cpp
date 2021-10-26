# include <bits/stdc++.h>
using namespace std ;

/*
No Output in this, just a very basic example of 'this' pointer
class Point
{
    int x , y ;
    public :
        Point ( int x , int y ) // Parameterized Constructor
        {   // Parameter names are the same as the class members' names
            this -> x = x ;
            this -> y = y ;   // 'this' pointer is useful in avoiding the confusion here
        }
} ;

int main ()
{
    Point p1 ( 10 , 20 ) , p2 ( 5 , 5 ) ;
}
*/

class Point
{
    int x , y ;
    public :
        Point ( int x , int y )
        {
            this -> x = x ;
            this -> y = y ;
        }

        Point &setX ( int x )   // Returns 'reference' to the cur object of class 'Point' 
        {
            this -> x = x ;
            return *this ;  // Return the value stored in 'this' pointer, ie, the cur object itself
        }
        Point &setY ( int y )
        {
            this -> y = y ;
            return *this ;  // We can chain these two functions together, like we do with cin/cout
        }
        void print()
        {
            cout << x << " " << y << endl ; // Example of chaining calls to the 'cout' function
        }
};

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    Point p1(10,10) ;
    p1.print() ;
    p1.setX(5).setY(15) ;
    p1.print() ;

    return 0 ;
}

/*
    To understand the 'this' pointer, it's important ot know how objects look at function and
    data members of a class.
        1. Each class gets its own copy of the data member.
        2. All-access the same function definition as present in the code segment.
    Meaning that all objects share a single copy of member functions. But then how are the proper
    data members accessed and updated, without accidentally, changing the members of another object?

    The compiler supplies an implicit pointer laong with the names of the functions as 'this'.
    The 'this' pointer is passed as a hiddern argument to all non-static member function calls and
    is available as a local variable withing the body of all non-static functions.
    'this' pointer is not available in static member functions as static member functions can be
    called without any object ( with class name ).

    For a class named 'X', the type of 'this' pointer is 'X*'. Also, if a member function of X is
    declared as const, then the type of this pointer is 'const X*'

    In the early version of C++, programmers were allowed to change the 'this' pointer; by doing so,
    they could change which object a method was working on. This feature was eventually removed, and
    now 'this' in C++ is an r-value. 

    C++ lets object destroy themselves by calling the following code :-
        delete this ;
*/

// Using 'this' to return reference to the calling object :-
class Test {
    public :
        Test &func() ;
} ;

Test &Test::func ()  // explicit function declaration or something, idk lol, google it
{
    // Some processing
    return *this ;
}