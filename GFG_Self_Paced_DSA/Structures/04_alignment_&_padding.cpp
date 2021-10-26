# include <bits/stdc++.h>
using namespace std ;

/*
    Data Types ( including int , float , double , ... ) have alignment requirements.
    A structure has alignment requirements same as its larger member's requirements.

    Data types that take only 1 bit, have no alignment requirements. But ones that take larger
    space do.

    So, all data types, other than 'char', have alignment requirements.
*/

struct s1
{
    char c1 ;
    double d1 ;
    char c2 ;
} ;

struct s2
{
    char c1 ;
    char c2 ;
    double d1 ;
} ;

struct s3
{
    double d3 ;
    char c1 ;
    char c2 ;
} ;

// Compilers like GCC, provide an option to specify, that compiler can do compact representation
struct s4
{
    double d1 ;
    char c1 ;
    char c2 ;
} __attribute__((packed)) ;


// Driver Function
int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    cout << sizeof(s1) << " " << sizeof(s2) << endl ;

    // This output depends on the machine, my machine currently, is Intel Architecture 64 bit
    // So, the output is 24 16

    cout << sizeof(s1) << " " << sizeof(s2) << " " << sizeof(s3) << endl ; // OP : 24 16 16

    // To save space, it's best to either declare the members in their increasing order of sizes,
    // or in their decreasing order. But never mixed.

    /*
        Reasons for Allignment :-

        ( Memory is byte addressible, but CPU read memory in the form of words )
        ( This is done to reduce the no. of CPU cycles to access the data)
        1. Physical memory is accessed in the form of word
        ( 4 bytes in a 32 bit machine, and 8 bytes in a 64 bit machine[word size = 8])

        2. Without alignment, it is ineffiicent ot store variables that span across multiple words.
    */

    cout << sizeof(s4) << endl ;    // OP : 10

    return 0 ;
}