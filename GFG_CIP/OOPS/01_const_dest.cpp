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
A copy constructor is a member function that initializes an object using another object of the 
same class. A copy constructor has the following general function prototype:
    Class_Name ( const Class_Name &old_obj_name ) ;

When is a copy constructor called ?
    1. When an object of the class is returned by value.
    2. When an object of the class is passed (to a function) by value as an argument.
    3. When an object is constructed based on another object of the same class.
    4. When the compiler generates a temporary object.
It's, however, not guaranteed that a copy constructor will be called in all these cases, because
the C++ Standard allows the compiler to optimize the copy away in certain cases.

*/

/*
When is a user-defined copy constructor needed?
If we don't define our own copy constructor, the C++ compiler creates a default copy constructor
for each class which does a member-wise copy between objects. The compiler created copy constructor
works fine in general.
We need to define our own copy constructor only if an object has pointers or any runtime allocation
of the resource like filehandle, a network connection, etc.

The default copy constructor only does shallow copy.
Deep copy is possible only with user defined copy constructor. In user defined CC, we make sure 
that pointers (or references) of copied object point to new memory locations.


Copy Constructor vs Assignment Ooperator :-
    Myclass t1 , t2 ;   // Assume we already created the respective class

Copy constructor is called when a new object is created from an existing object, as a copy of the
existing object. Eg.: Myclass t3 = t1 ;
Assignment operator is called when an already initialized object is assigned a new value from
another existing object. Eg.: t2 = t1 ; // t2 was already initialized above.

*/

/*
Can we make copy constructor private ?
Yes, a copy constructor can be made private. When we make a copy constructor in a class, objects
of that class become non-copyable. This is particularly useful when our class has pointers or
dynamically allocated resources. In such situations, we can either write our own copy constructors
or make a private copy constructor so that users get compiler errors rather than surprises
at runtime.

*/


// Initializer List

/*
Iniitalizer List is used in initializing the data members of a class. The list of members to be
initialized is indicated with constructor as a comma-separated list followed by a colon.
*/

//There are situations where initialization of data members inside constructor doesn't work and
// InitializerList must be used. Following are such cases :-

/*
1. For initialization of non-static const data members :
const data members must be initialized using Initializer List. In the following example, 't' is
a const dadta member of Test class and is initailzed using Initializer List. 
Reason for initializing the const data member in intializer list is because no memory is allocated
separately for const data member, it's folded in the symbol table due to which we need to 
initialize it in the initializer list.
Also, it's a Parameterised constructor and we don't need to call the assignment operator which
means we are avoiding on extra operation.
*/
/*
class Test
{
    const int t ;

    public :
        Test ( int t ) : t(t) {} // Initializer list must be used
        int getT() { return t ; }
};

int main ()
{
    Test t1(10) ;
    cout << t1.getT() ;
    return 0 ;

    // OP : 10
}
*/

/*
2. For initialization of reference members:
Reference members must be initialized using Initializer List. In the following example, "t" is a 
reference member of Test class and is initialized using Initializer List.
*/
/*
class Test
{
    int &t ;
    public :
        Test ( int &t ) : t(t) {}
        int getT() { return t ; }
};

int main ()
{
    int x = 20 ;
    Test t1(x) ;
    cout << t1.getT() << endl ;
    x = 30 ;
    cout << t1.getT() << endl ;
    return 0 ;

    // OP : 20
    // OP : 30
}
*/

/*
4. For initalization of member objects which don't have default constructor.
In the following example, an object 'a' of class 'A' is data member of class 'B', and 'A' doesn't
have default constructor. Initializer List must be used to initialize 'a'
*/
/*
class A
{
    int i ;
    public :
        A ( int ) ;
};

A :: A ( int arg )
{
    i = arg ;
    cout << "A's Constructor called: Value of i: " << i << endl ;
}

// Class B contains object of A
class B
{
    A a ;   // Variable of type 'object of class A'
    public :
    B (int) ;
};

B :: B (int x) : a(x)
{
    cout << "B's Constructor called";
}

int main ()
{
    B obj(10) ;
    return 0 ;

    // OUTPUT :-
    // A's Constructor called: Value of i: 10
    // B's Constructor called
}

If class A had both default and parameterized constructors, then Initializer List is not must if
we want ot initialize 'a' using default constructor, but it's must to initialize 'a' using
parameterized constructor.
*/

/*
4. For initialization of base class members
List point 3, the parameterized constructor of the base class can only be called using I List
*/
/*
class A
{
    int i ;
    public :
        A (int) ;
};
A :: A ( int arg )
{
    i = arg ;
    cout << "A's Constructor called: Value of i:" << i << endl ;
}

// Class B derived from A
class B: A
{
    public :
        B (int) ;
};
B :: B ( int x ) : A(x) 
{
    cout << "B's Constructor called" ;
}

int main ()
{
    B obj (10) ;
    return 0 ;
}
*/

/*
When constructor's parameter name is same as data member
If constructor's parameter name is same as data member name, then the data member must be 
initialized either using 'this' pointer or Initializer List.
*/

/*
6. For performance reasons :
It's better to ititialize all class variables in Initializer List instead of assigning values
inside body.

*/