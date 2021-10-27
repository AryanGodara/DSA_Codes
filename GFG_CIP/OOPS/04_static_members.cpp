# include <bits/stdc++.h>
using namespace std ;

// Static Member
class Player1
{
   
    public :
        static int count ;  // Static Variable

        Player1 () { count ++ ; }   // Constructor
        ~Player1 () { count -- ; }  //  Destructor

};

int Player1 :: count = 0 ;   // Static member have to be initialized outside the class

/*
int main () // For Static Variable
{
    Player1 p1 ; // 1st object created
    
    cout << Player1::count << endl ; // OP : 1
    // Instead of an object, static variables are directly attached to the class itself

    Player1 p2 ;    // 2nd object created
    cout << Player1 :: count << endl ;  // OP : 2

    return 0 ;
}
*/

// Static Member Function
class Player2
{
    
    public :
        static int count ;  // Static Variable

        Player2 () { count ++ ; }   // Constructor
        ~Player2 () { count -- ; }  //  Destructor

        static int getCount () { return count ; }
        // Static function to interact with static variables.

};

int Player2 :: count = 0 ;

int main () // For static member function
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    Player2 p1 , p2 ;   // 2 objects created for the class

    cout << Player2 :: getCount() << endl ; // OP = 2

    return 0 ;
}

/*
Static Keyword in C++

Static keyword has different meanings when used with different types. We can use it with :-
1. Static Variable : Variables in a function, Variables in a class.
2. Static Members of Class : Class objects and Functions in a class.

*/


// Static Variables :-
/*
1. Static Variables in a Function
When a variable is declared as static, space for it 'gets allocated for the lietime of the 
program'. Even if the function is called multiple times, space for the static variable is
allocated only once and the value of variable in the previous call carried through the next
function call. 
This is useful for implementing coroutines in C/C++, or any other application
where previous state of function needs to be stored.

*/

// CPP Program to demonstrate the use of static  variables in a function
/*
void demo1 ()
{
    static int count = 0 ;
    cout << count << " " ;

    count++ ;   // Value is updated and will be carried to next function calls
}

int main ()
{
    for ( int i = 0 ; i < 5 ; i++ )
        demo1 () ;
    
    // OP : 0 1 2 3 4
}
You see that the variable count is not getting initialized for every time the function is called.

*/

/*
2. Static Variables in a Class

As the variables declared as static are initialized only once as they're allocated spcae in
separate static storage so, the static variables 'in a class are shared by the objects'. This
can't be multiple copies of same static variables for different objects. 
Also because of this reason, static variables can't be initialized using constructors.

*/

// Static Members of CLass

/*
1. Class objects as static
Just like variables, objects also when declared as static have a scope till the lifetime of
program.
*/
/*
class GFG
{
    
    int i ;
    
    public :
        GFG () { i = 0 ; cout << "Inside Constructor\n" ; }
        ~GFG () { i = 0 ; cout << "Iniside Destructor\n" ; }

};

int main ()
{
    int x = 0 ;
    
    if ( x == 0 )
        GFG obj ;
    cout << "End of Main\n" ;

    // OP :-
    // Inside Constructor
    // Inside Destructor
    // End of Main
}

In the above program, the object is declared inside the if block as non-static. So, the scope
of variables is inside the if block only. So, when the object is created the constructor is
invoked as the control of if blcok gets over, the destructor is invokes as the scope of object 
is inside the if block, only where it's declared.

Now, let's see what happens, when we declare the object as static.

*/

// CPP program to illustrate class objects as static
/*
class GFG
{
    
    int i = 0 ;

    public :
        GFG () { i = 0 ; cout << "Inside Constructor\n" ; }
        ~GFG () { i = 0 ; cout << "Iniside Destructor\n" ; }

};

int main ()
{
    int x = 0 ;
    if ( x == 0 )
        static GFG obj ;
    cout << "End of Main\n" ;

    // OP :-
    // Inside Constructor
    // End of Main
    // Inside Destructor
}

You can cleary see the change in output. Now the destructor is invoked after the end of main.
This happened because the scope of static object is throughout the lifetime of the program.

*/

/*
2. Static Functions in a Class

Just like static data memberss or static variables inside the class, static member functions 
also don't depend on object of class. We're allowed to invoke a static member function using
the object and the '.' operator, but it's recommended to invoke them using hte class name and
the scope resolution operator.
'Static member functions are allowed to access only the static data members or other static
member functions', they can't access the non-static members of the class.

// We've already discussed an example function above.
*/