# include <bits/stdc++.h>
using namespace std ;

// T = P(log(n))
double sqroot ( int x , int p ) // Precision upto p decimal places
{
    int beg = 0 , end = x , mid = beg + (end-beg)/2 ;
    double root = 0.0 ;
    while ( beg <= end )
    {
        mid = beg + (end-beg)/2 ;

        if ( mid*1LL*mid == x )
            return (double)(mid) ;

        else if ( mid*1LL*mid < x )
        {
            beg = mid+1 ;
            root = mid ;        // The non-decimal part, say z will always satisfy z*z <= x
        }
        else
            end = mid-1 ;   // We can't update root here, as that would mean, making mid*mid>x
    }

    double increment = 1 ;

    for ( int i = 0 ; i < p ; i++ )
    {
        increment /= 10 ;

        while ( root*root <= x )
            root += increment ;
        root -= increment ;    // Remove the last increment for which root^2 > x
    }

    return root ;
}

// Another Method to find the square root of a number
double sqrt_newt_rap ( int n , int p ) // No whose root has to be found,precision (no. of decimal)
{
    double x = n , precision = pow(1,-p) , root ;

    // x = guessed root , and then, root = calculated root
    while ( true )
    {
        root = ( x + (n/x) ) / 2 ;

        if ( abs(root-x) < precision )  // Since we don't update the value of x at this step, we return root, else we could also have just returned x
            break ; // We have found our root
        x = root ;  // Update the value of our guessed root
    }
    return root ;  // The final value of our guessed root
}
int main ()
{
    cout << sqroot(40,3) << endl ;
    cout << sqrt_newt_rap(40,3) << endl ;

    return 0 ;
}