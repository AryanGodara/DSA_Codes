# include <bits/stdc++.h>
using namespace std ;

vector<vector<int>> visited (200 , vector<int> (200,false) ) ;

bool is_safe ( vector<vector<int>> &g , int i , int j , int m , int n , int pi , int pj )
{
    return ( i>=0 && j>=0 && i<m && j<n && !visited[i][j] ) ;
}

int dfs ( vector <vector<int>>&g , int i , int j , int m , int n , int pi , int pj )
{
    if ( !is_safe(g,i,j,m,n,pi,pj) )
        return 0 ;
    
    if ( g[i][j] <= g[pi][pj] )
        return 0 ;
    
    visited[i][j] = true ;
    
    // Calling dffs on the neighbours
    int ans = 0 ;
    if ( is_safe ( g,i+1,j,m,n,i,j ))
        ans  = max ( ans , dfs(g,i+1,j,m,n,i,j) ) ;
    if ( is_safe ( g,i-1,j,m,n,i,j ))
        ans  = max ( ans , dfs(g,i-1,j,m,n,i,j) ) ;
    if ( is_safe ( g,i,j+1,m,n,i,j ))
        ans  = max ( ans , dfs(g,i,j+1,m,n,i,j) ) ;
    if ( is_safe ( g,i,j-1,m,n,i,j ))
        ans  = max ( ans , dfs(g,i,j-1,m,n,i,j) ) ;

    visited[i][j] = false ;
    
    return ans + 1 ;
}

int longestIncreasingPath(vector<vector<int>>& matrix) 
{
    int m = matrix.size() , n = matrix[0].size() , ans = 1 ;
            
    for ( int i = 0 ; i < m ; i++ )
        for ( int j = 0 ; j < n ; j++ )
            ans = max ( ans , dfs(matrix,i,j,m,n,-1,-1) ) ;
    
    return ans ;
}

int main ()
{
    vector <vector<int>> g = {
        {5,6,9},
        {4,7,8},
        {3,2,1}
    };

    cout << longestIncreasingPath(g) << endl ;
}