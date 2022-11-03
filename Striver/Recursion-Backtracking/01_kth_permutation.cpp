# include <bits/stdc++.h>
using namespace std ;

// For [1,2,3,4,...,n], return the k'th permutation.

// Eg.: k = 17 , vector = [1,2,3,4]
/*
Total 4! permutations, in computer stored from [0,16].
Thus, we take k-1 = 16th permutation

1 -> [2,3,4] : 3! permutations [0-5]


2 -> [1,3,4] : 3! permutations [6-11]


3 -> [1,2,4] : 3! permutations [12-17]
16th permutation lies here (16/3!)

Now -> We need to find 16!6 = 4th permutation ::> in [2,3,4] k = 4
    1 -> [2,3] [0-1]
    2 -> [1,4] [2-3]
    4 -> [1,2] [4-6]
        The 4th permutation lies here.
        4%2! = 0. Therefore, the 0th permutation for [1,2] => 1,2

Hence, we get [3,4,1,2]

4 -> [1,2,3] : 3! permutations [18-23]
*/

// Basically, in each step, take k-1, find the starting element of subarray, move to next index
// stop in k = 0

int fact ( int n )
{
    int ans = 1 ;
    for ( int i = 1 ; i <= n ; i++ )
        ans *= i ;
    
    return ans ;
}

vector<int> k_th_permutation ( vector <int> arr , int n , int k )
{
    k = k-1 ;
    int fac = fact(n-1) ;
    vector <int> ret ;

    while(true)
    {
        ret.push_back(arr[k/fac]);

        arr.erase(arr.begin()+ k/fac);

        if (!arr.size())
            break ;
        
        k %= fac ;
        fac /= arr.size();
    }

    return ret ;
}

void print_permutations ( vector <int> &arr , vector<vector<int>> &res , int n , int i)
{
    // Base Case
    if ( i == n )
    {
        res.push_back(arr); 
        return ;
    }

    // Recursion
    for ( int j = i ; j < n ; j++ )
    {
        swap(arr[i],arr[j]);
        print_permutations(arr,res,n,i+1);
        swap(arr[i],arr[j]);
    }
}

int main()
{
    vector <int> arr = {1,2,3,4};
    int k = 17 ;

    vector <int> ret = k_th_permutation(arr,arr.size(),k) ;

    for ( auto &x: ret )
        cout << x << " " ;
    cout << endl ;

    // vector<vector<int>> res ;
    // print_permutations(arr,res,arr.size(),0);
    // for ( auto &x: res)
    // {
    //     for ( auto &y: x )
    //         cout << y << " " ;
    //     cout << endl ;
    // }

    return 0 ;
}