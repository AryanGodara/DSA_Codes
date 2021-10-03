# include <bits/stdc++.h>
using namespace std ;

// Given a number K and a string str, of digits denoted by a positive integer, build the largest
// number possible by performing swap operations on the digits of str, atmost K times

class Solution
{
    public:
    //Function to compare two strings and updating res
    //which stores the string with larger number.
    void match(string& str, string& res)
    {
        for(int i=0; i<str.size(); i++)
        {
            if( res[i] > str[i] )
                return;
            //if str[i] is greater, we update res as str or store
            //the larger value in res.
            if( res[i] < str[i] )
            {
                res = str;
                return;
            }
        }
    }

    public:
    //Function to set highest possible digits at given index.
    void setDigit( string& str , int index , string& res , int k )
    {
        // base case
        if(k==0 || index==str.size()-1) // No more swapping operations are possible
        {
            match(str,res);
            return;
        }
        
        int maxDigit = 0 ;
        
        //finding maximum digit for placing at given index.
        for(int i=index; i<str.size(); i++)
            maxDigit = max( maxDigit, str[i]-'0' );
        
        
        // swapping isn't needed in this case.
        if( str[index]-'0' == maxDigit )
        {
            setDigit(str, index+1, res, k);
            return;
        }
        
        for(int i=index+1; i<str.size(); i++)
        {
            // if max digit is found at current index.
            if( str[i]-'0' == maxDigit )
            {
                //swapping to get the maximum digit at required index.
                swap( str[index] , str[i] );
                
                //calling recursive function to set the next digit.
                setDigit(str, index+1, res, k-1);
                
                // backtracking
                swap( str[index] , str[i] );
            }
        }
    }

    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        string res = str ;
        setDigit(str, 0, res, k) ;      // First call to the recursive function
        
        //returning the result.
        cout << "str = " << str << endl << "res = " ;
        return res ;
    }

};


// Driver Code
int main ()
{

    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int t , k ;
    string str ;

    cin >> t ;

    while ( t-- )
    {
        cin >> k >> str ;
        Solution ob ;
        cout << ob.findMaximumNum(str,k) << endl; 

        return 0 ;
    }
}



/*
                // Submitted solution on gfg
class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(string & str, int k, string & max_string,int index){
        if(k == 0){
            return;
        }
        char curr_char = str[index];  
        for(int i = index+1; i < str.length(); ++i) {
            if(str[i] > curr_char) {
                curr_char = str[i]; 
            }
        }
        if(curr_char != str[index]) {
            k--; 
        }    
        for(int i = index; i < str.length(); ++i) {
            if(str[i] == curr_char) {
                swap(str[i], str[index]); 
                max_string = max(max_string, str); 
                solve(str, k, max_string, index+1); 
                swap(str[i], str[index]); 
            }
        }
    }
    
    
    string findMaximumNum(string str, int k)
    {
        int index = 0;  
        string max_string = "";
        solve(str, k, max_string,index); 
        return max_string == "" ? str : max_string; 
    }
};
*/

// Efficient Algorithm :-

/*
Approach :-
The above approach traverses the whole string at each recursive call, which is highly inefficient
and unnecessary. Also, pre-computing the maximum digit after the current at a recursive call avoids
unnecessary exchanges with each digit. It can be observed to make the maximum string, the maximum
digit is shifted to the front. So, instead of trying all pairs, try only those pairs where one of
the elements is the maximum digit which is not yet swapped to the front.
There is an improvement by 27580 microseconds for each case.

Algorithm :-

1. Create a global variable which will store the maximum string or number.
2. Define a recursive function that takes the string as a number, the value of k, and the current 
   index.
3. Find the index of the maximum element in the range current to end
4. If the index of the maximum element is not equal to the current index then decrement the value
   of k.
5. Run a loop from the current index to the end of the array.
6. If the i'th digit is equal to the maximum element.
7. Swap the i'th element and the element at the current index and check if the string is now maximum
   and update the maximum string.
8. Call the function recursively with parameters : str and k.
9. Now again swap back the i'th element and the current element.

Complexity Analysis :-

Time Complexity : O(n^k)
    For every recursive call, n recursive calls is generated until the value of k is 0. So total
    recursive calls are O(n^k)
Space Complexity : O(n)
    The space required to store the resultant maximum string.
*/