# include <bits/stdc++.h>
using namespace std ;

bool equal ( vector <int> a , vector<int> b )
{
    for ( int i = 0 ; i < 26 ; i++ )
        if ( a[i] != b[i] )
            return false ;
    return true ;
}

// Using unordered_map or simply, an array of length 26
bool checkInclusion_1 ( string s1 , string s2 )
{
    if ( s1.length() > s2.length() )
        return false ;

    vector <int> s1_map(26,0) ;

    for ( int i = 0 ; i < s1.length() ; i++ )
        s1_map[s1[i]-'a']++ ;

    for ( int i = 0 ; i <= s2.length()-s1.length() ; i++ )
    {
        vector <int> s2_map (26,0) ;

        for ( int j = 0 ; j < s1.length() ; j++ )
            s2_map[s2[i+j]-'a']++ ;
        
        if ( equal(s1_map,s2_map) )
            return true ;
    }

    return false ;
}

// Using Sliding Window
bool checkInclusion_2 ( string s1 , string s2 )
{
    if ( s1.length() > s2.length() )
        return false ;

    vector <int> s1_map(26,0) , s2_map(26,0) ;

    for ( int i = 0 ; i < s1.length() ; i++ )
    {
        s1_map[s1[i]-'a']++ ;
        s2_map[s2[i]-'a']++ ;
    }

    for ( int i = 0 ; i < s2.length() - s1.length() ; i++ )
    {
        if ( equal(s1_map,s2_map) )
            return true ;
        s2_map[s2[i + s1.length()] -'a']++ ; // Add the character at the pos, right after 'i'
        s2_map[s2[i]-'a']-- ;   // Remove the character before the new 'first' character
    }

    return equal(s1_map,s2_map) ;
}

// Using Sliding Window (Optimized/Efficient)
bool checkInclusion_3 ( string s1 , string s2 )
{
    if ( s1.length() > s2.length() )
        return false ;

    vector <int> s1_map(26,0) , s2_map(26,0) ;

    for ( int i = 0 ; i < s1.length() ; i++ )
    {
        s1_map[s1[i]-'a']++ ;
        s2_map[s2[i]-'a']++ ;
    }

    int count = 0 ;

    for ( int i = 0 ; i < 26 ; i++ )
        if ( s1_map[i] == s2_map[i] )
            count++ ;
        
    for ( int i = 0 ; i < s2.length() - s1.length() ; i++ )
    {
        int r= s2[i+s1.length()] -'a' , l = s2[i]-'a' ;
        
        if ( count == 26 )
            return true ;

        s2_map[r]++ ;

        if ( s2_map[r] == s1_map[r] )
            count++ ;   // We gained a new element that is matching in frequence
        else if ( s2_map[r] == s1_map[r]+1 )
            count-- ;   // We lost one element that was previously matching in frequency
        
        s2_map[l]-- ;   // We lost one frequency of this removed element

        if ( s2_map[l] == s1_map[l] )   
            count++ ;   // This made their frequencies equal
        else if ( s2_map[l] == s1_map[l] -1 )
            count-- ;   // We lost an element that was previously matching in frequency
    }

    return (count == 26) ;    // All the character frequencies should match
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    string a1 = "ab" , a2 = "eidbaooo" ;
    string b1 = "ab" , b2 = "eidboaoo" ;

    cout << boolalpha << checkInclusion_1(a1,a2) << endl ;
    cout << boolalpha << checkInclusion_1(b1,b2) << endl ;
    
    cout << endl ;

    cout << boolalpha << checkInclusion_2(a1,a2) << endl ;
    cout << boolalpha << checkInclusion_2(b1,b2) << endl ;
    
    cout << endl ;

    cout << boolalpha << checkInclusion_3(a1,a2) << endl ;
    cout << boolalpha << checkInclusion_3(b1,b2) << endl ;
    
    return 0 ;
}