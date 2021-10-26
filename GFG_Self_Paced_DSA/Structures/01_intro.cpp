# include <bits/stdc++.h>
using namespace std ;

struct point
{
    int x , y ;
} ;

// Example of typedef
typedef struct Point2
{
    int x , y ;
} P ;

struct Student
{
    int rollno ;
    string name , address ;
} ;

int main ()
{
    struct point p ;    // Writing 'struct' is necessary is C, but not in C++
    point p2 ;  // Perfectly valid in CPP

    // In CPP, we sometimes use typedef with structures, the purpose is to avoid typing this
    // amount of code for initializing the objects.
    P p1 ;
    p1.x = 10 , p1.y = 20 ;
    printf(" %d , %d \n" , p1.x , p1.y ) ;

    // Initializing the members using curly brackets
    Student s = { 101 , "ABC" , "Delhi" } ;
    cout << s.rollno << " " << s.name << " " << s.address << endl ;

    // Designated initialization of Structure members
    Student s1 = { .rollno = 100 , .address = "DELHI" } ;   
    // We can't change the order of initialization in CPP, but, we can skip initializations
    cout << s1.name << " " << s1.rollno << " " << s1.address << endl ;
    // For the uninitialized values, like 'name' in the aboe line, the variables are initialized to
    // their default values, like int to 0 , char to '' , string to "" , double to 0.0
    // But this default value initialization only happens, once we've initialized at least one
    // member variable of the struct, otherwise, all the variables will store some random values.

    return 0 ;
}

/*

    // Add two Complex Numbers using Structures
    struct Complex
    {
        int real , imag ;
    } ;

    // Driver Function
    int main ()
    {
        ios::sybc_with_stdio(false) ;
        cin.tie(NULL) ;
        
        Complex n1 , n2 , n3 ;
        
        cin >> n1.real >> n1.imag ;
        cin >> n2.real >> n2.imag ;

        n3.real = n1.real + n2.real ;
        n3.imag = n1.imag = n2.imag ;

        cout << n3.real << " + i" << n3.imag << endl ;

        return 0 ;
    }

*/