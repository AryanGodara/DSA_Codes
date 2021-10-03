# include <bits/stdc++.h>
using namespace std ;

void printBinary ( int num )
{
    for ( int i = 0 ; i < 10 ; i++ )
        cout << ( (num>>i) & (1) ) << " " ;
    for ( int i = 10 ; i <= 30 ; i++ )
        cout << ( (num>>i) & (1) ) << "  " ;
    // The comparison has to be at one's digit, else ans might change
    cout << endl ;
    cout << "The number of set bits are : " << __builtin_popcount(num) << endl ;
}

int main ()
{

    int n , maximum = 0 ; // n = no. of workers
    cin >> n ;

    vector <int> masks(n,0) ;  
        // To store the days on which each worker works
    
    // vector <int> ar[n] ; stores an array of vectors, each element is an array of size n

    for ( int i = 0 ; i < n ; i++ )
    {
        int num_days ;
        cin >> num_days ;
        int mask = 0 ;      // Initially the worker works for 0 days
        for ( int j = 0 ; j < num_days ; j++ )// Now, we find out the days
        {
            int day ;   // Which day they work on
            cin >> day ;
            mask = mask | (1<<day) ;
        }
        masks[i] = mask ;
    }

    // Printing the masks
    for ( int j = 0 ; j < n ; j++ )
    {
        for ( int i = 0 ; i < 31 ; i++ )
            cout << i << " " ;
        cout << endl ;

        printBinary(masks[j]) ;
        cout << endl ;
    }

    // Solving the question 
    for ( int i = 0 ; i < n ; i++ )
    {
        for ( int j = 0 ; j < n ; j++ )
        {
            if ( i==j )
                continue ;

            int intersection = masks[i] & masks[j] ;
            int current = __builtin_popcount(intersection) ;
            maximum = max(maximum,current) ;

            cout << "The intersection of " <<i<<" and "<<j<<" is : " << current << endl ;
            cout << "And the maximum intersection is : " << maximum << endl << endl ;
        }
    }
    cout << maximum << endl ;

    // Bit Masking BIT + MASK 
/*
    Suppose there are 4 types of fruits
    Apple : 0 Orange : 1 Banana : 2 Lichi : 3
    Each person has a mixed combination of fruits
    1. 2,3 ; 2. 0,1,2 ; 3. 1,3 ;

    We have to find the common fruits between two people
    We then have to find the intersection of the two sets, and the best time complexity for
    the intersection of two sorted arrays is : O(n), instead of O(n^2), by the two pointer approach.

    // We can represent the fruits it binary form : 0101 ie, orange and lichi are present
    so, then we take the bitwise AND of the two persons, and the set bits are the intersection
    1. 2,3  =  1100 = 12
    2. 0,1,2 = 0111 = 7
    3. 1,3  =  1010 = 10

    For the & operation, we have O(1), instead of O(1) for the normal algorithm

    // Now, instead of using arrays to store the fruits for each person,we can simply store an int
    // No, need to store it as 1100, when 12 will always be equivalent to that
    // Now, to find the common fruits : no. = noofsetbits((a^&))
    For 1. and 2. 
*/

    return 0 ;
}