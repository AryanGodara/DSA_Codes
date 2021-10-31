# include <bits/stdc++.h>
using namespace std ;

// Operator Overloading (Not supported in Java, just like multiple inheritance)

class Complex   // Complex Numbers
{
    private :
        int r , i ;
    public :
        Complex ( int r = 0 , int i = 0 )   // Parameterised Constructor
        {
            this -> r = r ;
            this -> i = i ;
        }

        // Returns : Object of class operator
        // Parameter : Object of class Operator
        Complex operator + ( const Complex &c )
        {
            Complex ans ;   // New Object Defined, for storing the answer
            ans.r = this->r + c.r ;
            ans.i = this->i + c.i ;
            return ans ;
        }

        void print ()
        {
            cout << this->r << " + j" << this->i << endl ;
        }
};

int main ()
{
    Complex c1(2,3) , c2(3,4) ;
    auto sum = c1 + c2 ;
    sum.print() ;

    return 0 ;
}

/*
GFG : Operator Overloading
*&#$^)*#@&%@*)#&$^@#%&)@#*&$#@$(*&)
*/