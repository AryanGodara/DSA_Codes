# include <bits/stdc++.h>
using namespace std ;

class Solution
{
   
    public :
    // Function to fill the array elements into a hash table
    // using Linear Probing to handle collisions
    vector<int> linearProbing ( int hashSize , int arr[] , int len )
    {
        vector <int> hash (hashSize,-1) ;
        // Store -1 at all the indices of the hash table

        // Iterating over the Array
        for ( int i = 0 ; i < len ; i++ )
        {
            // if the value of hash table at index (arr[i]%hashSize) is -1
            // which means empty, then, we insert arr[i] at that place
            if ( hash[arr[i]%hashSize] == -1 )
                hash[arr[i]%hashSize] = arr[i] ;
            
            // Else we move linearly from the filled position to 
            // find an index with -1 in hash table
            else
            {
                int counter = 0 ;
                int k = (arr[i])%hashSize ;
                int flag = 0 ;

                // Using a loop which runs until we find an index with -1

                while ( counter < hashSize && hash[k] != -1 )
                {
                    if ( hash[k] == arr[i] )    // Already Exists
                    {
                        flag = 1 ;
                        break ;
                    }
                    k = (k+1)%hashSize ;
                    counter++ ;
                }

                if ( flag )
                    continue ;  // We didn't insert this element
                // if we find a position where arr[i] can be inserted, then we insert the element
                if ( counter < hashSize)
                    hash[k] = arr[i] ;
            }
        }
        // Returning the hash table
        return hash ;
    }
} ;