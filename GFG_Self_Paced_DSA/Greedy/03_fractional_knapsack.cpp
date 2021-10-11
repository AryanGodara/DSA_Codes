/*
    Everything like the 0_1_knapsack problem (each item can be used only once)
    Only difference is that we can select fractions of items (like half or one-third)
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    Greedy Algorithm Approach :-

    1. Calculate the ratio (value/weight) for every item.
    2. Sort all items in decreasing order of the ratio.
    3. Initialize : res = 0 , curr_cap = given_cap
    4. Do the following for every item 'i' in the sorted array :-
        a. if ( i.weight <= curr_cap )
           :    cur_cap -= i.weight ;   res += i.value
        b. else // This is the last possible item we can add(Which gives us the max value)
           :    res += i.value *cur_cap/i.weight ;      return res
        c. return res ; // If we fill go through the entire list w/o filling the knapsack
*/

bool cmp ( pair<int,int> a , pair<int,int> b )
{
    if ( a.second != b.second )
        return a.second > b.second ;
    return a.first < b.first ;
}

double solve ( vector <int> &val , vector <int> &wt , int W , int n )
{
    // W = max capacity         // n = length of the array

    vector<pair<int,int>> ratio(n) ;

    double res = 0 ;   // The final solution

    for ( int i = 0 ; i < n ; i++ )
    {
        ratio[i].first = i ;    // Current index
        ratio[i].second = val[i]/wt[i] ;
    }

    sort ( ratio.begin() , ratio.end() , cmp ) ;    // Sorted according to their ratios

    for ( auto &x : ratio )  // Going through each item
    {
        if ( wt[x.first] <= W ) // We can add the whole item
        {
            res += val[x.first] ;
            W -= wt[x.first] ;
        }
        else    // This is the last element
        {
            double temp = (double)(W) / wt[x.first] ;
            res += val[x.first]*temp ;
            break ;
        }
    }

    return res ;
}

// Driver Function
int main ()
{
    vector <int> val = { 600 , 500 , 400 } , wt = { 50 , 20 , 30 } ;

    cout << solve ( val , wt , 70  , val.size() ) << endl ;
}