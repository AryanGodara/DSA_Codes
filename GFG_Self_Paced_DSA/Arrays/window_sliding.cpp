// Window sliding Technique :-
/*
    Find the subarray with the given sum
*/

# include <bits/stdc++.h>
using namespace std ; 

// Returns trus if there is a subarray of arr[] with a sum = 'sum'. Also, prints the result

bool subarraysum ( vector <int> arr , int n , int sum )
{
    // Initialise cur_sum as value of first element, and starting point at 0
    int cur_sum = arr[0] , start = 0 , i ;

    // Add elements one by one to cur_sum and if the cur_sum exceeds the sum, then remove starting element

    for ( i = 1 ; i < n ; i++ )
    {
        // If cur_sum exceeds the sum, then remove the starting elements
        while ( cur_sum > sum && start < i-1 )
        {
            cur_sum -= arr[start] ;
            start++ ;   // By the final call, start we be get a value <= i
        }

        // If cur_sum becomes equal to sum, then return true
        if ( cur_sum == sum )
        {
            cout << "Sum found between indexes " << start << " and " << i-1 << "\n" ;
            return true ;
        }

        // For the normal call, add this element to cur_sum
        if ( i < n )
            cur_sum += arr[i] ;
    }

    // If we reach here, then no subarray was found
    cout << "No subarray found" ;
    return false ;
}

// Driver program to test the above function

int main ()
{

    vector <int> arr = {15,2,4,8,9,5,10,23} ;
    int sum = 23 , n = arr.size() ;

    subarraysum(arr,n,sum) ;

    return 0 ;
}