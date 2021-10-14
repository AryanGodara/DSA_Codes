# include <bits/stdc++.h>
using namespace std ;

int bin_search ( vector <int> & arr , int beg , int end , int x )
{
    // Base Case
    if ( beg > end )
        return -1 ;
    int mid = beg + (end-beg)/2 ;

    if ( arr[mid] == x )
        return mid ;
    else if ( arr[mid] > x )
        return bin_search(arr,beg,mid-1,x) ;
    else
        return bin_search(arr,mid+1,end,x) ;
}

double eps = 1e-6 ;     // Epsilon (vvery small value, MTL) = 10 ^ -6

double multiply ( double x , int n )
{
    double ans = 1 ;
    for ( int i = 0 ; i < n ; i++ )
        ans *= x ;
    return ans ;
}

int main ()
{
    ios_base :: sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    // Find the n'th root of a number, precice upto epsilon

    double x ;
    cin >> x ;
    int n ;
    cin >> n ;
    double beg = 1 , end = x , mid ;

    while ( end - beg > eps )
    {
        mid = (beg+end)/2 ;

        if ( multiply(mid,n) < x )
            beg = mid ;
        else
            end = mid ;
    }

    // At this point, both these values are almost same.
    cout << setprecision(7) << beg << " " << end << endl ;    // Upto 3 decimal places

    return 0 ;
}