// Merge k sorted arrays

# include <bits/stdc++.h>
using namespace std ;

// Super Efficient Code

struct triplet
{
    int val , apos , vpos ; // its value , position of its array, its position in the array

    triplet ( int v , int ap , int vp ) // Constructor
    {
        val = v , apos = ap , vpos = vp ;
    }
};

struct my_cmp       // Custom Comparator for sorting in the heap
{
    bool operator () ( triplet &t1 , triplet &t2 )
    {
        return t2.val > t2.val ;    // greater<int> for this structure
    }
};

vector <int> merge_k_sorted ( vector < vector<int> > & arr )
{
    // k = Number of arrays     // n = max no of elements in any array

    vector <int> res ;

    priority_queue < triplet , vector<triplet> , my_cmp > pq ;

    for ( int i = 0 ; i < arr.size() ; i++ )
    {
        triplet t ( arr[i][0] , i , 0 ) ;
        pq.push(t) ;
    }

    while ( !pq.empty() )
    {
        cout << pq.top().val << " " ;
        pq.pop() ;
    }

    while ( !pq.empty() )
    {
        triplet cur = pq.top() ;    pq.pop() ;

        res.push_back ( cur.val ) ;

        int ap = cur.apos , vp = cur.vpos ;

        if ( vp+1 < arr[ap].size() )   // This wasn't the last element in its array
        {
            triplet t ( arr[ap][vp+1] , ap , vp+1 ) ;
            pq.push(t) ;
        }
    }

    return res ;
}

// Efficient Code T = O ( n . k^2 )

// Simple function to merge two arrays
vector <int> merge ( vector <int> arr1 , vector <int> arr2 )
{
    int i = 0 , j = 0 ;
    vector <int> arr ;  // Resultant array

    while ( i < arr1.size() && j < arr2.size() )
    {
        if ( arr1[i] < arr2[j] )
            arr.push_back ( arr1[i++] ) ;
        else
            arr.push_back ( arr2[j++] ) ;
    }

    while ( i < arr1.size() )
        arr.push_back ( arr1[i++] ) ;
    while ( j < arr2.size() )
        arr.push_back ( arr2[j++] ) ;

    return arr ;
}

// Primary Function for the 'Efficient Approach'
vector <int> naive_merge_k_arrays ( vector < vector<int> > &arr )
{
    vector <int> res = arr[0] ; // Taking two arrays at a time, merge them together.

    for ( int i = 1 ; i < arr.size() ; i++ )
        res = merge ( res , arr[i] ) ;

    return res ;
}

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    vector < vector<int> > arr = { { 10 , 20 , 30 } , { 1 , 15 } , { 5 , 9 , 11 , 18 } } ;

    vector <int> res1 = merge_k_sorted ( arr ) ;

    for ( auto &x : res1 )
        cout << x << " " ;
    cout << endl ;

    vector <int> res2 = naive_merge_k_arrays ( arr ) ;

    for ( auto &x : res2 )
        cout << x << " " ;
    cout << endl ;
}