/*
    Unbound Knapsack :-
    Since in this case, we can use each item multiple no. of times. So, the only thing that's
    chaning is the value of 'max weight'. So, in this case, we'll use a 1D dp array.
    So, dp[i] = max val that we can obtain in a bag of maximum weight 'i'
    When the cap of the bag is '0', dp[0] = 0. Since we can't store any item in this
*/

# include <bits/stdc++.h>
using namespace std ;

/*
    Approach :-
    1. Make an array dp[W+1].
    2. Now, we'll iterate through the dp array and the items and we fill a value in dp array's 
       i'th position only if the weight of the weight of the (i-1)'th item is less than the value
       of 'i' which is the current capacity of the bag.
    3. So, the remaining bag capacity will be rbagc = cap - weight[i-1]. Also the remaining bag
       value i.e., the max cost of the bag after inserting element of weight = -weight[i-1]
       is rbagc = dp[rbagc].
    4. The total max cost of inserting the item with weight = weight[i-1] will be rbagv+price[i-1]
*/

int unbound_knapsack ( vector<int> val , vector<int> wt , int W , int n ) // T = O(n*W)
{
    vector <int> dp(W+1) ;  // Auxiliary Space = O(W), better than the method in the prev file.
    dp[0] = 0 ;

    for ( int bag_cap = 1 ; bag_cap <= W ; bag_cap++ )
    {
        dp[bag_cap] = 0 ;   // Initially initialise it to zero
        // Now traverse the entire object array
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( wt[i] <= bag_cap ) // So, we can use this object
            {
                int rbagc = bag_cap - wt[i] ; // Remaining bag capacity, after adding this object
                int rbagv = dp[rbagc] ; // OR dp[bag_cap - wt[i] ] ;
                int tbagv = rbagv + val[i] ;    // The current val, after we include this item

                dp[bag_cap] = max ( dp[bag_cap] , tbagv) ;

                // OR dp[cur] = max(dp[cur] , val[i] + dp[cur-wt[i]]) ;
                // There's no need to have so many variables.
                // We're just going through each item in the array, and checking including which
                // one will give us the maximum value for this cur value of 'max_wt' = 'bag_cap'
            }
        }
    }

    return dp[W] ;
}

int main ()
{
    vector <int> val1 = {15,14,10,5,30} , wt1 = {2,5,1,3,4} ;
    vector <int> val2 = {10,40,30,50} , wt2 = {5,4,6,3} ;

    cout << unbound_knapsack(val1,wt1,6,5) << endl ;
    cout << unbound_knapsack(val2,wt2,10,4) << endl ;

    return 0 ;
}