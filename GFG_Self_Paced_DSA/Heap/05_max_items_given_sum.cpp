// Buy Maximum Items with given sum

# include <bits/stdc++.h>
using namespace std ;


int main ()
{
    vector <int> cost = { 1 , 12 , 5 , 111 , 200 } ;
    int sum = 10 ;      // OP = 2
    int n = 5 ; // Size of array

    priority_queue < int , vector<int> , greater<int> > pq ;    // Min Heap

    int res = 0 ;

    for ( int i = 0 ; i < n ; i++ )
        pq.push(cost[i]) ;

    for ( int i = 0 ; i < n ; i++ )
    {
        if ( pq.top() < sum )   // We can include this min possible item in the solution
        {
            sum -= pq.top() ;
            pq.pop() ;
            res++ ; // No. of items that we can fit has increased by 1
        }
        else
            break ;
    }

    cout << res << endl ;

    return 0 ;
}