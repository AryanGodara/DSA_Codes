# include <bits/stdc++.h>
using namespace std ;


// Normal Constructo
/*
class Point
{
    private :
        int x , y ;
    public :
        Point ()
        {
            x = 0 , y = 0 ;
        }
        Point ( int x1 , int y1 )
        {
            x = x1 ;
            y = y1 ;
        }
        void print ()
        {
            cout << x << " " << y << endl ;
        }
} ;

int main ()
{
    Point p1 , p2(10,20) ;
    p1.print() ;
    p2.print() ;
    Point *ptr = new Point(5,10) ;  // Pointer of type 'struct Point'
    ptr -> print() ;

    return 0 ;

    // OP :- 
    // 0 0
    // 10 20
    // 5 10
}
*/


// Iniitalizer List
/*
class Point
{
    private :
        int x , y ;
    public :
        Point () : x(0) , y(0) {}

        Point ( int x1 , int y1 ) : x(x1) , y(y1) {}

        void print()
        {
            cout << x << " " << y << endl ;
        }
} ;
/*
// int main ()
// {
//     Point p1 , p2(10,20) ;
//     p1.print() ;
//     p2.print() ;
//     Point *ptr = new Point(5,10) ;
//     ptr -> print() ;

//     /*
//         OP :-
//         0 0
//         10 20
//         5 10
//     */
// }



// Without Initializer List
/*
class Test
{
    public :
        Test ()
        {
            cout << "Default\n" ;
        }
        Test ( int x )
        {
            cout << "Parameterized\n" ;
        }
} ;

class Main
{
    Test t ;
    
    public :
        Main ()
        {
            t = Test(10) ;
        }
} ;
*/
// int main ()
// {
//     Main m ;
//     return 0 ;

//     /*
//         OP :-
//         Default
//         Parameterized
//     */
// }



// With Initializer List
/*
class Test
{
    public :
        Test ()     // Constructor
        {
            cout << "Default\n" ;
        }
        Test ( int x ) // Constructor
        {
            cout << "Parameterised\n" ;
        }
} ;

class Main
{
    Test t ;    // Create an object of class 'Test'
    public :
        Main () : t(10) {}
} ;
*/
// int main ()
// {
//     Main m ;
//     return 0 ;

//     /*
//         OP :-
//         Parameterized
//     */
// }


// Shallow Copy
/*
class Test
{
    int *ptr ;  // Pointer of type int

    public :
        Test ( int x ) // Parameterized Constructor
        {
            ptr = new int(x) ;
        }
        void set ( int x )
        {
            *ptr = x ;  // Update the value stored in x
        }
        void print()
        {
            cout << *ptr << endl ;  // Store the value stored in 'ptr'
        }
} ;
*/
// int main ()
// {
//     Test t1(10) , t2(t1) ;  // 2nd one is call to Copy Constructor (default copy constructor)
//     t2.set (20) ;
//     t1.print() ;
//     t2.print() ;

//     return 0 ;

//     /*
//         OP :-
//         20
//         20      // The value gets updated for both t1 and t2, but they should store different 
//                 // Objects, not reference to the same object :(
//     */
// }


// Deep Copy
/*
class Test
{
    int *ptr ;

    public :
        Test ( int x )  // Parameterized Constructor
        {
            ptr = new int(x) ;
        }

        Test ( const Test &t )  // Copy constructor, object of pointer, called by reference
        {
            int val = *(t.ptr) ;    // Get the value stored in the ptr member of object t
            ptr = new int (val) ;
        }

        void set ( int x )
        {
            *ptr = x ;
        }

        void print ()
        {
            cout << *ptr << endl ;
        }
} ;

int main ()
{
    Test t1(10) ;
    Test t2(t1) ;
    t2.set(20) ;    // Update the value in t2

    t1.print() ;    // Both show different values, because both point to different locations
    t2.print() ;    // in memory, unlike in the case of the default copy constructor.

    return 0 ;
}
*/


// Destructor 1
/*
class Test
{
    public :
        Test () { cout << "Constructor Called\n" ; }
        ~Test () { cout << "Destructor Called\n" ; }
} ;

int main ()
{
    Test t1 ;
    // OP :-
    // Constructor Called
    // Destructor Called
}
*/


// Destructor 2

class Test
{
    int x ;
    public :
        Test ( int i ) : x(i)   // Using initializer list
        {
            cout << "Construct " << x << endl ;
        }
        ~Test ()
        {
            cout << "Destroy " << x << endl ;
        }
} ;

int main ()
{
    Test t1 (10) ;
    Test t2 (20) ;

    return 0 ;

    /*
    OP :
        Construct 10
        Construct 20
        Destroy 20
        Destroy 10

        This is because, unless we manually delete an object, by  default, at the end of the 
        program, all objects are destroyed in the reverse of the order in which they were created.
    */
}

/*
    // Write about copy constructors and initalizer lists here
*/