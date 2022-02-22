# include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 10 ;

bool dp[205][20005] ;        // dp[i][cur] :- array upto i'th element ; cur sum

bool func ( int i , int sum , vector <int> &nums )
{
    // Base Cases
    
    if ( sum < 0 )
        return false ;
    else if ( sum == 0 )
        return true ;
    else if ( i < 0 )
        return false ;
    
    if ( dp[i][sum] != -1 )
        return dp[i][sum] ;

    // Recursion

    // Don't consider the current (i'th) element
    bool ret = func(i-1,sum,nums);

    // Consider the current (i'th) element
    ret |= func(i-1,sum-nums[i],nums);

    return dp[i][sum] = ret ;
}

bool canPartition ( vector <int> &nums )
{
    int sum = accumulate(nums.begin(),nums.end(),0);
    if ( sum & 1 )
        return false ;
    else
        sum >>= 1 ;          // The target sum = half of sum of all elements of the array

    memset(dp,-1,sizeof(dp));

    return func(nums.size()-1 , sum , nums) ;
}


int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
}