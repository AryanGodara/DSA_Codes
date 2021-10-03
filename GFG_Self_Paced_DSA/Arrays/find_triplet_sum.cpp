# include <bits/stdc++.h>
using namespace std ;

// Given a sorted array and a sum, find if there is a triplet with the given sum
// Simple solution is, run a O(n) loop through the array, as long as the element is less than the
// sum, and run the findpair_func for sum = sum-arr[i], and modify the program to ignore the i^th
// element, this approach will take a n * nlogn = O(n^2log(n)) time

// For triplets or beyond, sorting still takes O(nlogn). So it remains less than O(n^2logn)
// So we prefer two pointers over hashing for triplets and beyond, as we don't require extra space

vector <int> twoptr ( vector <int> arr , int sum , int ignore_index )
{
    int lptr = 0 , rptr = arr.size()-1 ;

    vector <int> ret ;

    while ( lptr < rptr )
    {
        if ( lptr == ignore_index )         // Extra cases to accomodate for the triplet
        {
            lptr++ ;
            continue ;
        }
        else if ( rptr == ignore_index )    // Extra cases to accomodate for the triplet
        {
            rptr-- ;
            continue ;
        }

        if ( arr[lptr] + arr[rptr] < sum )
            lptr++ ;
        else if ( arr[lptr] + arr[rptr] > sum )
            rptr-- ;
        else
        {
            ret.push_back(lptr) ;
            ret.push_back(rptr) ;
            break ;
        }
    }
    if ( lptr >= rptr )
    {
        ret.push_back(-1) ;
    }
    return ret ;
}

vector <int> triplet_finder ( vector<int> arr , int sum )
{
    vector <int> ret ;
    for ( int i = 0 ; i < arr.size() && arr[i] < sum ; i++ )
    {
        ret = twoptr(arr,sum-arr[i],i) ;
        if ( ret.size() == 1 )
        {
            arr.pop_back() ;
            continue ;
        }
        else // We found the solution
        {
            ret.push_back(i) ;
            break ;     // Forgetting to put this, just broke the program lol
        }
    }
    return ret ;
}

int main ()
{
    vector <int> arr = { 2 , 3 , 4 , 5 , 8 , 9 , 20 , 40 } ;
    vector<int> prin = triplet_finder(arr,30) ;

    for ( auto &element : prin )
        cout << element << " " ;

    cout << endl ;

    return 0 ;
}