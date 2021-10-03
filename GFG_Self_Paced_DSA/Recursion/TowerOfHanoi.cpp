// Towers of Hanoi
/*
    Rules :-
    1. Only move one disk at a time
    2. No larger disk can be placed over a smaller one
    3. Only the top disk of a tower can be moved.
*/
# include <bits/stdc++.h>
using namespace std ;

void TOH ( int n , char A , char B , char C )// Disks , Source , Auxillary , Destination
{
    if ( n==1)  // Base case, simply move the smallest (1) plate from A to C.
    {
        cout << "Move 1 from " << A << " to " << C << endl ;
        return ;
    }

    // Recursion
    TOH (n-1 , A , C , B) ;
    // Move the top n-1 disks from A to B, using C as the auxillary

    cout << "Move " << n << " from " << A << " to " << C << endl ;
    // Move the bottom most disk from A to C

    TOH (n-1 , B , A , C ) ;
    // move those n-1 disks from B to C, using A as auxillary
}

int main ()
{
    TOH(3,'A','B','C') ;
    return 0 ;
}
/*
    T(n) = 2T(n-1) + 1
        = 2(2T(n-2) + 1)
        = 4T(n-2) + 2 = n - "2" , 2^2 , +1*2
        n-n = 0 , 2^n + 2n = n(2^n-1 + 1)
    = 2^n - 1
*/