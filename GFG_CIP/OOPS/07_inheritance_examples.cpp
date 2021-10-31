# include <bits/stdc++.h>
using namespace std ;


// Multiple Inheritance : Inherits from one or more classes

class A
{
    public :
        int x ;
        A () { cout << "Constructor of A\n" ; }
};

class B : virtual public A
{};

class C : virtual public A
{};

class D : public B , public C
{};

class Base1
{
    protected :
        int x = 1 ;
    public :
        Base1 ( int a ) : x(a)
        {
            cout << "Base1\n" ;
        }
};

class Derived1 : public Base1
{
    private :
        int y ;
    public :
        Derived1 ( int a , int b ) : Base1(a) , y(b) 
        {
            cout << "Derived1\n" ;
        }
        void print ()
        {
            cout << x << " " << y << endl ;
        }
};

int main ()
{
    // For example
    Derived1 d1 (10,20) ;
    d1.print() ;

    // For multiple inheritance
    D d ;
    cout << d.x << endl ;

    // We use virutal keyword, because in this case, two classes : B and C, are deriving from
    // class A, and both of those classes, are base for class D. So, when we construct an object
    // of D, it will lead to two separate calls to constructor of class A, and this causes the
    // Object of class D, to end up with two copies of 'x', from class A. 
    // This leads to compiler errors, as now, 'd.x' is ambiguous, as we don't know which of
    // the two copies is being called here.
    // To avoid this, 'virtual' keyword is used.

    return 0 ;
}


// This doesn't Work, because, in derived class, x becomes private
class Base2
{
    public :
        int x ;

        Base2 ( int a ) : x(a)
        {
            cout << "Base1\n" ;
        }
};

class Derived2 : public Base2
{
    private :
        int y ;
    public :
        Derived2 ( int a , int b ) : Base2(a) , y(b) 
        {
            cout << "Derived2\n" ;
        }
        void print ()
        {
            cout << x << " " << y << endl ;
        }
};

// int main ()
// {
//     Derived2 d2 ( 10 , 20 ) ;

//     d2.print() ;

//     // cout << d.x << endl ;   // Illegal, as x is now 'private' in 'derived2
// }

