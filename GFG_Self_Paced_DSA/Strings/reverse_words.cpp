// reverse the order of words in this string
# include <bits/stdc++.h>
using namespace std ;

// Update the existing space : Space Complexity = O(1)

/*
    Naive Approach
    1. Create a Stack
    2. Push the words one by one to the stack
    3. Pop words from the stack, and append them to the output
*/

/*
void reverse(char str[],int low, int high){
    while(low<=high){
        swap(str[low],str[high]);
        low++;
        high--;
    }
}
*/

void rev_words ( string &str , int n )
{
    // First reverse the words, then reverse the entire string

    int beg = 0 ;
    for ( int end = 0 ; end < n ; end++ )
    {
        if ( str[end] == ' ' )
        {
            reverse(str.begin()+beg,str.begin()+end) ;
            beg = end+1 ;   // Start form the next word
        }
    }
    reverse(str.begin()+beg,str.end()) ;    // Reverse the last word
    reverse (str.begin(),str.end()) ;
}

int main ()
{
    string str = "bryan is a good boy" ;
    int n = str.length() ;

    rev_words(str,n) ;

    cout << str << endl ;

    return 0 ;
}