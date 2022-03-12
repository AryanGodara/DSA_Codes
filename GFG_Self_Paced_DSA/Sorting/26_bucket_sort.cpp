# include <bits/stdc++.h>
using namespace std ;

void bucket_sort ( int arr[] , int n , int k )
{
    int max_val = arr[0] ;
    for ( int i = 1 ; i < n ; i++ )
        max_val = max ( max_val , arr[i] ) ;
    
    max_val++ ; // Now, all values in the array are less than max_val

    vector <int> bkt[k] ;   // Array of type vector<int>

    for ( int i = 0 ; i < n ; i++ )
    {
        int bi = ( k * arr[i] ) / max_val ;

        bkt[bi].push_back(arr[i]) ;
    }

    for ( int i = 0 ; i < k ; i++ )
        sort( bkt[i].begin() , bkt[i].end() ) ;
    

    //? Place all elements from matrix 'bucket' back to array 'arr'
    int index = 0 ;
    for ( int i = 0 ; i < k ; i++ )
        for ( int j = 0 ; j < bkt[i].size() ; j++ )
            arr[index++] = bkt[i][j] ;
}

int main ()
{
    int arr[] = {30,40,10,80,5,12,70} ;
    int n = sizeof(arr)/sizeof(arr[0]) , k = 4 ;

    bucket_sort(arr,n,k) ;

    for ( int i = 0 ; i < n ; i++ )
        cout << arr[i] << " " ;
    cout << endl ;

    return 0 ;
}