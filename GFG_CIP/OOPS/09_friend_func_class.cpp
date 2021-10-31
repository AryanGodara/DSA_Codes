# include <bits/stdc++.h>
using namespace std ;

// Again, not supported by java lol.
// Friend keyword allows a function or a class, to access everything, even the private
// members of its friend class.

/*
Rules of Friendship :-

1. Friendship is granted, not taken. 
   So, a class will list all of its friends, a random function or a friend can't just make a
   class their friend.

2. Friendship is not mutual -> && <- is required, no such thing as <->

3. Not Transitive and Not Inherited ( No nepotism, no mutal friends lol)

*/

/*****************************************************************************************/

// Example of friend function
class employee1 ;

class printer1
{
    public :
        void print_emp ( const employee1 &e ) ;
};

class employee1
{
    private :
        int id ;
        string name ;
    public :
        friend void printer1 :: print_emp ( const employee1 &e ) ;
        // Tell that the prin_emp function from the class 'printer1' is a 'friend' of this class
        
        employee1 ( int i , string n ) : id(i) , name(n) {} // Constructor, Initialization List
};

void printer1 :: print_emp ( const employee1 &e )   // Defining the function declared above
{
    cout << e.id << " " << e.name << endl ;
    // See, this can access the private members of the 'employee1' class
}

/*****************************************************************************************/

// Example of Friend Class
class employee2 ;

class printer2
{
    public :
        void print_emp ( const employee2 &e ) ;
};

class employee2
{
    private :
        int id ;
        string name ;
    public :
        friend class printer2 ;
        // Tell that the entire class 'printer2' is a 'friend' of this class
        
        employee2 ( int i , string n ) : id(i) , name(n) {} // Constructor, Initialization List
};

void printer2 :: print_emp ( const employee2 &e )   // Defining the function declared above
{
    cout << e.id << " " << e.name << endl ;
    // See, this can access the private members of the 'employee2' class
}

/*****************************************************************************************/

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    // Friend Function
    printer1 p1 ;
    employee1 e1 (101 , "abc") ;
    p1.print_emp(e1) ;


    // Friend Class
    printer2 p2 ;
    employee2 e2 (101 , "abc") ;
    p2.print_emp(e2) ;

    return 0 ;
}