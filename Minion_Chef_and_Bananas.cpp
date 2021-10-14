# include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 5 ;

long long int n , h ;   // To avoid parameters

vector <long long int> arr(N) ; // Piles of bananas

bool predicate ( int x )
{
    int hrs = h ;   // Hours left
    
    for ( int i = 0 ; i < n ; i++ )
    {
        double temp = (double)(arr[i]) / x ;
        hrs -= ceil(temp) ;
    }

    return hrs>=0 ;
}

// Driver Function
int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    int T ;
    cin >> T ;

    while (T--)
    {
        cin >> n >> h ;

        for ( int i = 0 ; i < n ; i++ )
            cin >> arr[i] ;
        
        long long beg = 0 , end = 1e9 ; // Max possible value of bananas in a pile

        while ( end - beg > 1 )
        {
            int mid = beg + (end-beg)/2 ;

            if ( !predicate(mid) )  // Not able to finish
                beg = mid+1 ;
            else
                end = mid ; // This is a possible solution
        }

        // Since, it has to be the min value of k, just print beg
        if ( predicate(beg) )
            cout << beg << endl ;
        else
            cout << end << endl ;
    }

    return 0 ;
}