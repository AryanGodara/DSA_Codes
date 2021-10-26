# include <bits/stdc++.h>
using namespace std ;

/*
References in C++ :-
When a variable is declared as a reference, it becomes an alternative name for an existing variable.
A variable can be declared as a refernce by putting '&' in the declaration.

*/
/*
int main ()
{
    int x = 10 ;

    int &ref = x ;  // 'ref' is reference to x

    // Value of x is now changed to 20
    ref = 20 ;
    cout << x << endl ; // OP = 20

    // Value of x is nwo changed to 30
    x = 30 ;
    cout << ref << endl ;   // OP = 30

    return 0 ;
}
*/

/*
Application of references :-

1. Modify the passed parameters in a function , eg: swap two numbers: int swap (int &a , int &b){}

2.Avoiding a copy of large structure , for(auto &x: arr ) OR void func (vector<int> &arr )

*/

/*
References vs Pointer :-

Both references and pointers are can be used to change local variables of one function inside
another function. Both of them can also be used to save copying of big objects when passed as
arguments to functions or return from functions, to get efficiency gain. Despite the above 
similarities, there are the following differences between references and pointers.

1. A pointer can be declared as void, but a reference can never be void. For example
    int a = 10 ;
    void *aa = &a ; // Perfectly valid initialization of a pointer
    void &ar = a ;  // Invalid

2. The pointer variable has n-levels/multiple levels of indirection ie. single-pointer , 
   double-pointer, triple-pointer. Whereas, the reference variable has only one/single level of
   indirection. 

The following code reveals the mentioned points:
3. Referenc variable can't be updated
4. Reference variable is an internal pointer
5. Declaration of Reference varaible is preceded with '&' symbbol (but don't read it as 'address of')

*/

int main ()
{
    int i = 10 ;        // Simple or ordinary variable
    int *p = &i ;       // Single pointer
    int **pt = &p ;     // Double pointer
    int ***ptr = &pt ;  // Triple pointer

    // All the above pointers differ in the value they store or point to.
    cout << "i=" << i << " p=" << p << " pt=" << pt << " ptr=" << ptr << "\n" ;

    int a = 5 ;
    int &S = a ;
    int &S0 = S ;
    int &S1 = S0 ;

    // All the above references don't differ in their values as they all refer to the same variable.
    cout << "a=" << a << " S=" << S << " S0=" << S0 << " S1=" << S1 << "\n" ;

    return 0 ;
}

/*

References are less powerful than pointers :-

1. Once a reference is created, it can't be later made to reference another object; it can't be
   reset. This is often done with pointer.
2. Refereces can't be NULL. Pointer are often made NULL to indicate that they aren't pointing to
   any valid thing.
3. A reference must be initialized when declared. There is no such restrictino with poniter.

Due to the above Limitations, references in C++ can't be used for implementing data structures 
like linked lists, treess , etc. 

In Java, references don't have the above restriction and can be used to implement all data structs.
Reference being more power in Java is the main reason Java doesn't need pointers.

*/

/*
References are safer and easier to use :-

1. Safer : Since reference must be initialized, wild references like wild pointers are unlikey to
   exist. It's still possible to have refereces that don't point to a valid location.

2. Easier to Use : References don't need dereferencing operator to acces the value. They can be 
   used liek normal variables. '&' operator is only needed at the time of declaration. Also, 
   members of an oobject reference can be accessed with the dot '.' operator, unlike pointers where
   arrow operator '->' is needed to access members.

Together with the above reasons, there are a few places like the copy constructor argument where
pointer can't be used. Reference must be used to pass the arguments in the copy constructor. Simply,
references must be used for overloading some operators like ++.

*/