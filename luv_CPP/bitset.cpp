# include <bits/stdc++.h>
using namespace std ;

int main ()
{
    // bitset <2> arr ;
    // arr[0] = 50 , arr[1] = 1 ;
    // cout << arr << endl ;
    // for ( int i = 0 ; i < 2 ; i++)
    //     cout << arr[i] << " " ;

    
    
    // Integer to bitset and vice-versa
    // bitset <4> a_int(13) ;   // Bitset to store the value of 8 in binary form
    // cout << a_int << endl ; // Printing the bitset

    // int n = (int) a_int.to_ulong() ; // Convert to unsigned long int, so for int we typecast (int)
    // cout << n << endl ;

    
    
    // // String to bitset
    // string str = "1010110100" ;
    // // Size of bitset '10 here' should be a const no., and can't be a var, like in vectors

    // bitset<10> arr (str) ;  // String to bitset , size of bitset can even be greater than 1000
    // cout << arr << endl ;
    // string new_str = arr.to_string() ;  // Bitset to string
    // cout << new_str << endl ;



    // // Counting the number of set bits in a bitset
    // cout << arr.count() << endl ;   // Counts set bits just like __builtin_popcount() ;



    // // Some Basic Operations :-

    // bitset <4> a (string("0101")) ;
    // bitset <4> b (string("1010")) ;

    // cout << (a&b) << endl ;
    // cout << (a|b) << endl ;
    // cout << (a^b) << endl ;
    // cout << (~a) << endl ;
    // cout << (a<<1) << endl ;    // Size remains same, even after leftshifting
    // cout << (b>>1) << endl ;    // Size remains same, even after rightshifting



    string str1 = "1010110100" ;
    istringstream stream(str1) ;
    bitset<2> s1 ;
    bitset<6> s2 ;
    stream >> s1 ;              // Starts copying form the MSB (LHS), so the LSBs are neglected
    cout << s1 << endl ;    // 10
    stream >> s2 ;
    cout << s2 << endl ;    // 101101

    cout << endl ;

    // Checking if there's atleast one set bit inside a set
    cout << boolalpha << s1.any() << endl ;
    // Cheking if none of the bits are set (Opp to any() )
    cout << boolalpha << s1.none() << endl ;
    // Check if all bits are set
    cout << boolalpha << s1.all() << endl ;

    cout << endl ;

    // Flips all or any particular bit
    bitset <4> s (string("1010")) ;
    cout << s.flip() << endl ;  // 0101
    cout << s << endl ;         // 0101     // These changes are made to the original bitset
    cout << s.flip(1) << endl ; // 0111 // Flips s[1] , or the '2nd' bit from the RHS

    cout << endl ;

    // Reset all or any particular bits
    cout << s.reset(2) << endl ;    // 0011
    cout << s.reset() << endl ;     // 0000
    cout << s << endl ;     // 0000 // The changes made are permanenet

    cout << endl ;

    // Set all or any particular bit
    bitset <4> a (string("1010")) ;
    cout << a.set(0) << endl ;  // 1011
    cout << a.set() << endl ;   // 1111
    cout << a << endl ;         // 1111 // All changes are final

    return 0 ;
}