// Given an arr[] of n numbers. The task is to print only those
// numbers whose digits are only from the set {1,2,3}

# include <bits/stdc++.h>
using namespace std ;
map <int,int> mp ;
// mp holds 1 to those numbers which consist of only 1,2 andd 3 as digits only

void findAll ()
{
    int num = 1 , num2 , j = 1 ;
    vector<int> a ;

    // Storing 1,2 and 3 in the list
    a.push_back(j) ;    // j == 1
    a.push_back(j+1) ;
    a.push_back(j+2) ;

    // The idea is to store 1 as value in a map for all numbers between 1 and 1000000
    // which only have 1,2 and 3 as digits.
    // We can then easily check for the required numbers from the map
    mp[1] = 1 ;
    mp[2] = 1 ;
    mp[3] = 1 ;

    j = 0 ;     // Value changed from 1 to zero

    // Using a loop in which we keep on multiplying the number in list with 10
    // and add 1,2 and 3 to it and store them in the list one by one thus numbers
    // with only 1,2 and 3 as digits are stored in the list
    // This process continues till the number is less than or equal to 1000000

    while ( num <= 1000000 )
    {
        // storing the number from list in num2 ;
        num2 = a[j++] ;
        // Stores a[0], and then increments j to 1, and so on

        // multiply number with 10 and adding 1 we store it in the list
        // only if it's less than or equal to 1000000
        if ( num2*10 + 1 <= 1000000 )
        {
            a.push_back(num2*10 + 1 ) ;
            // Updating the value in the map
            mp[num2*10 + 1 ] ;
        }

        // multiply number with 10 and adding 2 we store it in the list
        // only if it's less than or equal to 1000000
        if ( num2*10 + 2 <= 1000000 )
        {
            a.push_back(num2*10 + 2 ) ;
            // Updating the value in the map
            mp[num2*10 + 2 ] ;
        }

        // multiply number with 10 and adding 3 we store it in the list
        // only if it's less than or equal to 1000000
        if ( num2*10 + 3 <= 1000000 )
        {
            a.push_back(num2*10 + 3 ) ;
            // Updating the value in the map
            mp[num2*10 + 3 ] ;
        }

        // Updating num which controls the loop
        num = num2 ;
    }

}

int main ()
{
    ios_base :: sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    findAll() ; // Find all such numbers whose digits are from the set {1,2,3}

    int T ; 
    cin >> T ;  // Number of testcases

    while ( T-- )
    {
        int n , flag = 0 ;
        cin >> n ;

        int arr[n] ;

        for ( int i = 0 ; i < n ; i++ )
            cin >> arr[i] ;

        sort(arr,arr+n) ;

        for ( int i = 0 ; i < n ; i++ )
        {
            if ( mp[arr[i]])
            {
                cout << arr[i] << " " ;
                flag = 1 ;
            }
        }
        if ( !flag )    // Not even a single such number was found
                cout << "-1" ;
        
        cout << endl ;
    }

    return 0 ;
}