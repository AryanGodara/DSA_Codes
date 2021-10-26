# include <bits/stdc++.h>
using namespace std ;

struct Point
{
    int x , y ;
} ;

// A function that takes a structure variable, as an argument
void print ( Point p )  // Passed by value, doesn't make any change to the original object vars
{
    cout << endl << p.x << " " << p.y << endl ;
}

void print_with_reference ( Point p )   // Passed by reference
{
    cout << endl << p.x << " " << p.y << endl ;
}

// But what if we accidentally make changes to the original variables?
// For that, we can use the 'const' keyword, to turn the variables into constants, for the func
void print_with_const ( const Point p )
{
    cout << endl << p.x << " " << p.y << endl ;
}

// Using pointers instead of objects
void print_with_pointer ( Point *p ) // * converts p into a pointer
{
    cout << endl << p->x << " " << p->y << endl ;   // Arrow operator is required for pointers
}

// Driver Function
int main ()
{
    Point p = {10 , 20} ;
    Point *ptr = &p ;   // A pointer of type 'Struct Point' called 'ptr', pointing to object 'p'

    cout << ptr->x << " " ; // Istead of ., we use the arrow '->' operator when using pointers

    ptr->x = 30 ;   // Changing value of x using the pointer, changes the actual value, not a copy
    
    cout << p.x << "\n\n";   // We can access it using object as well as pointers


    // Now, we look at an array of pointers
    Point arr[5] ;  // An array of size '5', of type 'struct Point'
    for ( int i = 0 ; i < 5 ; i++ )
    {
        arr[i].x = i+1 , arr[i].y = (i+1)*10 ;
    }

    for ( int i = 0 ; i < 5 ; i++ )
        cout << arr[i].x << " " << arr[i].y << endl ;

    print(arr[0]) ; // Passing structure object as parameter

    // But in this way, we are creating a copy of all the structure objects, which consumes extra
    // time and space, so instead we can either pass pointers, or pass objects by reference

    print_with_reference(arr[0]) ;
    print_with_const(arr[0]) ;
    print_with_pointer(&p) ;    // Converting p to a pointer, before sending it as an argument

    return 0 ;
}