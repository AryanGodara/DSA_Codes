# include <bits/stdc++.h>
using namespace std ;

// A base class type reference or pointer can refer to a derived class object.
/*
class Base {};
class Derived : public Base {};

int main ()
{
    Base *b = new Derived ; // Base class pointer referring to Derived class object
    Derived d ; // Object of Derived class
    Base &b = d ;   // Reference of Base class pointing to an object of derived class

    return 0 ;
}

// Without Virtual Function :-
class Base1
{
    public :
        void print() { cout << "Base\n" ; }
};

class Derived1 : public Base1
{
    public :
        void print() { cout << "Derived\n" ; }
};

// With Virtual Function :-
class Base2
{
    public :
        virtual void print() { cout << "Base\n" ; } // Virtual keyword used
};

class Derived2 : public Base2
{
    public :
        void print() { cout << "Derived\n" ; }
};

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    // For Base , Derived
    Base *b = new Derived ; // Base class pointer referring to Derived class object
    Derived d ; // Object of Derived class
    Base &b = d ;   // Reference of Base class pointing to an object of derived class



    // For Base1 , Derived1 , Virtual Function not Used
    Base1 b1 ;
    b1.print() ;

    Derived1 d1 ;
    d1.print() ;

    Base1 *b_ptr1 = &d1 ;
    b_ptr1 -> print() ;

    cout << endl ;
    
    // For Base2 , Derived2 , Virtual Function Used
    Base2 b2 ;
    b1.print() ;

    Derived2 d2 ;
    d1.print() ;

    Base2 *b_ptr2 = &d2 ;
    b_ptr2 -> print() ;

    return 0 ;
}
*/

/*
Virtual Function in C++ :-
A virtual function is a member function which is declared within a 'base' class and is 
re-defined (Overridden) by a derived class. When you refer to a derived class objects using a
pointer or a reference to the base class, you can call a virtual function for that object and
execute the 'derived class's' version of the function.

1. Virtual functions ensure that the correct function is called for an object, regardless of the
   type of reference (or pointer) used for function call.
2. They are mainly used for 'Runtime Polymorphism'
3. Functions are delcared with 'virtual' keyword in 'base' class.
4. The resolving of function call is done at 'Run-time'
*/

/*
Rules for Virtual Functions :-
1. Virtual functions can't be static.
2. A virtual function can be a 'friend' function of another class.
3. Virtual functions should be accessed using pointer or reference of base class type to 
   achieve 'run time polymorphism'.
4. The prototpye of virtual functions should be the same in the base class as well as the
   derived class.
5. They are always defined in the base class and overridden in a derived class. It's not
   mandatory for the derived class to override (or re-define) the virtual function, in that 
   case, the base class version of the function is used.
6. A class may have a Virtual Destructor'.
7. A class CAN NEVER have a 'Virtual Constructor'.
*/

/*
Explaination of the above program :-
Runtime polymorphism is achieved only through a pointer (ore reference) of base class type.
Also, a base class pointer can point to the objects of base class as well as to the objects of
derived class.
Late binding (Runtime) is done in accordance with the content of pointer ( i.e., the location
pointed to by pointer) and Early binding (Compile time) is done according to the type of
pointer.

NOTE : If we have created a virtual function in the base class and it's being overridden in 
       the derived class, then we don't need virtual keyword in the derived class, functions
       are automatically considered as virtual functions in the derived class.
*/

/*
Working of virtual functions (concepts of VTABLE and VPTR) :-

If a class contains a virtual function, then compiler itself does two things :

1. If object of that class is created, then a virtual pointer (VPTR) is inserted as a data
   member of the class. For each new object created, a new virtual pointer is inserted as a 
   data member of that class.
2. Irrespective of whether object is created or not, a static array of function pointer called
   VTABLE where each cell contains the address of each virtual function contained in that class.

*/

// CPP Program to illustrate workign of virtual functions

class base
{
    public :
        void fun_1 () { cout << "Base-1\n" ; }
        virtual void fun_2 () { cout << "Base-2\n" ; }
        virtual void fun_3 () { cout << "Base-3\n" ; }
        virtual void fun_4 () { cout << "Base-4\n" ; }
};

class derived : public base
{
    public :
        void fun_1 () { cout << "Derived-1\n" ; }
        void fun_2 () { cout << "Derived-2\n" ; }
        void fun_4 ( int x ) { cout << "Derived-4\n" ; }
};

int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    base *ptr ; // Pointer of type 'object of base class'
    derived obj ;   // Objected of derived class
    ptr = &obj ;  // Pointer of base class pointing to object of derived class

    // Early binding because fun_1 is non-virtual in base
    ptr -> fun_1() ;

    // Late binding (RTP)
    ptr -> fun_2() ;

    // Late binding (RTP)
    ptr -> fun_3() ;

    // Late binding (RTP)
    ptr -> fun_4() ;

    // Early binding but this function call is illegal (produces error) because pointer
    // is of the base type, and function is of derived class.

    // ptr -> fun_4(5) ; // Gives error

    // NOTE : fun_4(int) in derived class is different from virtual function fun_4() in base
    // class as prototype of both the functions is different

    // OP :-
    // Base-1
    // Derived-2
    // Base-3
    // Base-4
}

/*
Override Keyword in C++ :-

Function overriding is redefinition of base class function in its derived class with same
signature.
But there are situations when a programmer makes a mistake while overriding that function. So,
to keep track of such an error, C++11 came up with the keyword override. It will make the 
compiler to check the base class to see if there's a virtual function with this exact signature.
And if there isn't, the compiler will show an error.
*/

// A CPP Prgoram without override keyword. Here, programmer makes a mistake and isn't caught
class base1
{
    public :
    // User wants to override this in the derived class
    virtual void func() { cout << "From base1\n" ; }
};

class derived1 : public base1
{
    public :
    // Did a silly mistake by putting an argument 'int a'
    void funct ( int a ) { cout << "From derived1\n" ; }
};
// This Compiles Successfulyy ^^^^^^^^^^^^^^^^^^


// A CPP program that uses override keyword so that any difference in function signature
// is caught during compilation.
class base2
{
    public :
    // User wants to override this in the derived class
    virtual void func() 
    { 
        cout << "From base2\n" ; 
    }
};

class derived2 : public base1
{
    public :
    // Did a silly mistake by putting an argument 'int a'
    void func ( int a ) override                // NOTICE THE OVERRIDE KEYWORD
    { 
        cout << "From derived2\n" ; 
    }
};
// OP : Error ->
// member function declared with 'override' does not override a base class member



/*
Function Overloading vs Function Overriding :-

1. Inheritance :
    Overriding of functionc occurs only when one class is inherited from another class.
    Overloading can occur without inheritance.
2. Function Signature :
    Overloaded function must differ in function signature.
    In overriding, signature must be same.
3. Scope of Function :
    Overriden functions are in different scopes; whereas overloaded function are in same scope.
4. Behavior of Functions :
    Overriding is needed when derived class function has to do some added or different job
    than the base class function. Overloading is used to have same name functions which behave
    differently depending upton the parameters passed to them.
*/