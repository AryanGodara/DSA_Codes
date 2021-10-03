// Tail Recursion

# include <bits/stdc++.h>
using namespace std ;

void func1 ( int n )    // Tail recursion
{
    if ( n == 0 )
        return ;
    cout << n << " " ;
    func1(n-1) ;
}

void func2 ( int n )    // Not tail recursion :p
{
    if ( n == 0 )
        return ;
    func2(n-1) ;
    cout << n << " " ;
}

void tailrecurfunc2 ( int n , int k )
{
    if ( n == 0 )
        return ;
    cout << k ;
    tailrecurfunc2(n-1,k+1) ; // k starts with the value 1, so that it still prints in ascending order
}

int tail_recur_fact ( int n , int k )   // k = 1, in the first call
{
    if ( n == 0 || n == 1 )
        return k ;
    
    return tail_recur_fact(n-1,k*n ) ;

    // Normally, we would write return n*fact(n-1), which is not a simple return statement
}

// A recursive function is called tailed recursive if the parent function has nothing left to do
// when the child function is finished.
// In other words, the last line in the recursive function is the recursive call.

// eg.: Quicksort is tail recursive while mergesort isn't. That's why quicksort is faster.


// Writing Base cases in Recursive Function

int fact ( int n )
{
    // The base cases are the cases, where the function can't be further brocken down into subproblems
    if ( n <= 1 )
        return 1 ;

    return n * fact(n-1) ;
}

// If the base case isn't exhaustive, we'll get a segmentation error.

int fib_normal ( int n )
{
    if ( n <= 0 )
        return 0 ;
    
    if ( n == 1 )
        return 1 ;
    
    // OR, to combine both, just write
    if ( n <= 1 )
        return n ;  // Just make sure that n is never less than 0.

    return fib_normal(n-1) + fib_normal(n-2) ;
}

int getnatsum ( int n )
{
    if ( n == 0 )
        return 0 ;

    return n + getnatsum(n-1) ;
}

bool pallindrome_check_normal ( string s )
{
    if ( s.length() <= 1 )
        return true ;
    
    if ( s[0] == s[s.length()-1] )
        return pallindrome_check_normal( s.substr(1,s.length()-2) ) ;
    return false ;
}

int sum_of_digits ( int n )
{
    if ( n <= 0 )
        return 0 ;

    return n%10 + sum_of_digits(n/10) ;
}

// Rope Cutting Problem
// We are given a rope of length n. Our task is to cut this rope into the maximum no. of pieces
// such that every piece has length = a , b or c.

int max_cuts ( int n , int a , int b , int c )
{
    if ( n == 0 )   // We have successfully cut the entire rope
        return 0 ;
    
    if ( n < 0 )
        return -1 ; // This permutation failed

    int res = max( max( max_cuts(n-a,a,b,c) , max_cuts(n-b,a,b,c) ) , max_cuts(n-c,a,b,c) ) ;

    if ( res == -1 )
        return -1 ;
    return 1 + res ;
}

void generate_subsets ( string str , int i , int n , string res ) // Initially i = 0 , res = ""
{
    // Base Case
    if ( i == n )
    {
        cout << res << endl ;
        return ;
    }

    // Call this function for a string already containing str[0], ans for substring of str
    generate_subsets( str[0] + str.substr(1) , i+1 , n , res + str[0] ) ;// We include this character
    
    // Call this function for a string not containing str[0], ans for substring of str
    generate_subsets(str.substr(1) , i+1 , n , res ) ;            // We ignore this character
}

void subset_sum_recur ( string str , int i , int n , int res )   // initially, res = 0 , i = 0 
{
    // Base Case
    if ( i == n )
    {
        cout << res << endl ;
        return ;
    }   

    subset_sum_recur(str.substr(1) , i+1 , n , res + (str[0]-'0') ) ; // Adding this value
    subset_sum_recur(str.substr(1) , i+1 , n , res ) ;  // Not adding this value
}

void all_permutations ( string str , int cur , int n )   // initially, cur = 0 , res = ""
{
    // Base Case
    if ( cur == n-1 )
    {
        cout << str << endl ;   // Print the resultant string
        return ;
    }

    // Now from this position, we have take every possible element
    for ( int i = cur ; i < n ; i++ )
    {
        swap(str[cur],str[i]) ;
        all_permutations(str , cur+1 , n) ;
        swap(str[cur],str[i]) ;
        // Takes A,B,C,D at each step. But also make sure that there aren't any repititions
    }
}

int main ()
{
    all_permutations("ABC" , 0 , 3 ) ;
}

// int main ()
// {
//     generate_subsets("ABCD" , 0 , 4 , "" ) ;
//     subset_sum_recur("1234" , 0 , 4 , 0 ) ;

//     return 0 ;
// }