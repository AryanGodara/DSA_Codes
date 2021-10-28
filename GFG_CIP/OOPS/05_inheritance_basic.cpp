# include <bits/stdc++.h>
using namespace std ;

class Person
{
    protected :
        string name ;
        int id ;
    
    public :
        Person ( string n , int i )
        {
            name = n ;
            id = i ;
        }
};

class Student : public Person
{
    private :
        int marks ;

    public :
        Student ( string n , int i , int m ) : Person (n,i) , marks(m) {} // Initializer List
        void print () { cout << name << " " << id << " " << marks << "\n" ; }
};

int main ()
{
    Student s  ( "Rahul" , 1001 , 88 ) ;
    s.print() ;

    return 0 ;
    // OP : Rahul 1001 88
}