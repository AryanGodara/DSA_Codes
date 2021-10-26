# include <iostream>
using namespace std ;

// Since classes can do almost anything that functions can do in C++, and structures are included
// in C++, due to its backwards compatibility with C, so they're kind of redundant here in C++.

class Point1
{
    int x , y ; // A class has all the members as private (by default)
} ;

struct Point2
{
    int m , n ;
} ;

struct Point    // Advanced structure with constructors
{
    int x , y ; // Public by default

    Point ( int a , int b ) // Constructor
    {
        x = a ;
        y = b ;
    }

    void print()    // Member function
    {
        cout << x << " " << y << endl ;
    }
} ;


// Inheritance comparison
class Base1
{
    public :
        int a ;
} ;
class Derived1 : Base1 {} ; // Private inheritance by default

struct Base2
{
    int b ;
} ;
struct Derived2 : Base2 {} ;    // Public inheritance by default


// Driver Function
int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Point1 p1 ;
    // p1.x = 10 ;  // Invalid operations, as x and y are private members of the class Point1
    // cout << p1.x << endl ;   // Same error

    Point2 p2 ;
    p2.m = 20 , p2.n = 40 ; // Perfectly valid, as members are public by default in structures

    // But we can add private to structures, and public to classes as well.
    // Structure can do anything classes can, like having constructors and destructors.

    // Since structures and classes are interchangeable, when do we use which?
    // As a general practice, we use structures when we only want to bundle multiple items
    // together, ie., create a composite data type. And probably also want to have related  
    // functions bundled together in the same thing.
    // But, when we care about object oriented programming , data hiding , etc., we use classes.

    // Another difference between them is that in the case of inheritance, default for struct is
    // public, while the default for class is private, though they can be changed to anything.
    
    Derived1 d1 ;
    // d1.a = 20 ;   // Gives error, as now, 'a' is private in the derived class

    Derived2 d2 ;
    d2.b = 30 ;     // Doesn't give any error.
}