# include <bits/stdc++.h>
using namespace std ;

//! Naive Approach O(N^2), checking for each character
int nonRep_naive(string &str) 
{
    for(int i=0;i<str.length();i++){
        bool flag=false;
        for(int j=0;j<str.length();j++){
            if(i!=j&&str[i]==str[j]){
                flag=true;
                break;
            }
        }
        if(flag==false)return i;
    }
    return -1;
}

//? Better Approach O(N), but still uses O(256) auxillary space
const int CHAR=256;
int nonRep_1(string &str) 
{
    int count[CHAR]={0};
    for(int i=0;i<str.length();i++){
        count[str[i]]++;
    }
    for(int i=0;i<str.length();i++){
        if(count[str[i]]==1)return i;
    }
    return -1;
}

//* Efficient Approach O(N) time , O(256) space
int nonRep(string &str, int n ) 
{
    vector <int> fi (CHAR,-1) ; // Stores the first location
    // fi == -1 : hasn't occured in the array yet
    // fi == -2 : has already been repeated in the array
    //? Both of these cases mean that this character is definitely not the solution
    
    for( int i = 0 ; i < n ; i++ )
    {
        if ( fi[str[i]] == -1 ) // This is the first appearance
            fi[str[i]] = i ;
        else
            fi[str[i]] = -2 ;
    }

    int res = INT_MAX ;

    for(int i=0;i<CHAR;i++)
        if( fi[i] >= 0 )    // Has only occured once (so, it may be a solution)
            res = min ( res , fi[i] ) ;

    return (res==INT_MAX) ? -1 : res ;
}
