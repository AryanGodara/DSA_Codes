# include <bits/stdc++.h>
using namespace std ;

string fractionToDecimal ( int numerator , int denominator )
{
    if ( !numerator )
        return "0" ;
    
    string res = "" ;

    // "+" or "-"   // If the answer is -ve, append the '-' sign to the front of the answer
    res.append( (numerator>0 ^ denominator>0) ? "-" : "" ) ;

    long num = abs((long)numerator) , den = abs((long)denominator) ;

    // Integral part
    res.append(to_string(num/den) ) ;

    num %= den ;    // This is the remainder

    if ( !num ) // If there's no remainder, then there's no fractional part
        return res ;

    // Fractional Part
    res.append(".") ;   // Decimal point

    unordered_map <long,int> mp ;

    while ( num )   // While we don't get the remainder = 0
    {
        num *= 10 ;
        res.append(to_string(num/den) ) ;
        num %= den ;    // Update the remainder

        if ( mp.find(num) != mp.end() ) // This remainder has repeated, loop found
        {
            //int index = res.find(num) ; // First position, before which we place '('
            int index = mp[num] ;   // Stores the length of the string upto this point
            res.insert( index , "(" ) ;
            res.append(")") ;
            break ;
        }
        else    // First occurence
            mp.insert( {num,res.length()} ) ;
    }

    return res ;
}


// Driver Function
int main ()
{
    int num , den ;
    cin >> num >> den ;

    cout << fractionToDecimal(num,den) << endl ;

    return 0 ;
}