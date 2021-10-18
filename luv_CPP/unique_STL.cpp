# include <bits/stdc++.h>
using namespace std ;

/*
std::unique is used to remove duplicates of any element present consecutively in a range[first, last). 
It performs this task for all the sub-groups present in the range having the same element present 
consecutively.

It does not delete all the duplicate elements, but it removes duplicacy by just replacing those 
elements by the next element present in the sequence which is not duplicate to the current element 
being replaced. All the elements which are replaced are left in an unspecified state.

Another interesting feature of this function is that it does not changes the size of the container 
after deleting the elements, it just returns a pointer pointing to the new end of the container, 
and based upon that we have to resize the container, or remove the garbage elements.
*/

// This function can be used in the following two ways :-


// 1. Comparing elements using ==

// template 
// ForwardIterator unique (ForwardIterator first, ForwardIterator last);

// first: Forward iterator to the first element in the container.
// last: forward iterator to the last element in the container.

// Return Value: It returns an iterator to the element that follows 
// the last element not removed. The range between first and this iterator includes 
// all the elements in the sequence that were not
// duplicates and hence not removed.
/*
int main ()
{
    vector <int> v = { 1 , 1 , 3 , 3 , 3 , 10 , 1 , 3 , 3 , 7 , 7 , 8 } , i ;

    vector <int> :: iterator ip ;

    // Using std::unique

    ip = std::unique( v.begin() , v.end() ) ;   // Returns iterator to the last unique element
    // Now v becomes { 1 3 10 1 3 7 8 * * * * * } , where '*' is undefined

    // Resizing the vector so as to remove the undefined terms
    v.resize ( std::distance(v.begin(),ip) ) ;  // Ig we can use v.resize(ip-v.begin()+1)

    // Displaying the vector after applying std::unique

    for ( ip = v.begin() ; ip != v.end() ; ip++ )
        cout << *ip << " " ;
    cout << endl ;

    // O/P : 1 3 10 1 3 7 8

    return 0 ;

    // Notice that only the duplicates that are clustered together get removed. But if
    // two duplicates aren't contigous, they won't be affected.
    // So, it's preferable to sort the array beforehand.
}
*/


// 2. By comparing using a pre-defined function 

// template 
//  ForwardIterator unique (ForwardIterator first, ForwardIterator last,
//                          BinaryPredicate Pred);

// Here, first and last are the same as previous case.

// Pred: Binary function that accepts two elements 
// in the range as argument, and returns a value convertible to bool. 
// The value returned indicates whether both arguments are considered equivalent
// (if true, they are equivalent and one of them is removed).
// The function shall not modify any of its arguments.
// This can either be a function pointer or a function object.

// Return Value: It returns an iterator to the element that 
// follows the last element not removed.
// The range between first and this iterator includes 
// all the elements in the sequence that were not
// duplicates and hence not removed.

/*
// Define the Predicate BinaryFunction
bool predicate ( char a , char b )
{
    // Check if both the arguments are the same and equal to 'G' then only
    // they are considered same and duplicates are removed
    return a==b && a=='G' ;
}

int main ()
{
    // Declaring a string
    string s = "You arre vvvisiting GGGFGGGG" ;

    // Using std::unique to remove the consecutive G in the word
    auto ip = std::unique ( s.begin() , s.end() , predicate ) ;

    // Displaying the corrected string
    cout << string(s.begin(),ip) ;  // ip is the new s.end()

    // O/P : You are vvvisiting GFG

    return 0 ;

    //Here, we have manipulated the binary function in such a way that only 
    // if two G are passed as arguments, then only they will be considered as 
    // same, and if any other character is present consecutively, then it will 
    // remain unaffected, and will not be removed (like r in arre, v in visiting).
}
*/

// Situations where str::unique can be used?
// Remove all the duplicate elements from a container or just count their number
int main ()
{
    vector<int> v = { 1 , 2 , 3 , 3 , 3 , 10 , 1 , 2 , 3 , 7 , 7 , 8 } ;

    vector<int>::iterator ip ;

    // Sort the array first
    sort(v.begin(),v.end()) ;

    ip = unique( v.begin() , v.end() ) ;

    // Now, resize the vector to remove the duplicate terms
    v.resize( distance( v.begin() , ip ) ) ;

    // There is another way of resising the array
    // We can erase the vector starting from the iterator ip,
    // which is the new v_no_duplicates.end()

    v.erase ( ip , v.end() ) ;
    // OR v.erase ( unique(v.begin(),v.end()) , v.end() )

    for ( auto &x : v )
        cout << x << " " ;
    cout << endl ;

    // If we just want to count the no. of unique elements
    int count = distance ( v.begin() , unique(v.begin(),v.end()) ) ;

    cout << count << endl ;

    return 0 ;
}