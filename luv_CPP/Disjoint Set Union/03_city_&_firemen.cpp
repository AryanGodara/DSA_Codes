/*
Problem
Fatland is a town with N cities numbered 1, 2, ..., N, connected with 2-way roads. Vincent is a villian who wants to set the entire town ablaze. For each city, there is a certain risk factor E[i] for setting that city ablaze. But once a city c is set ablaze, all cities that can be reached from c will be set ablaze immediately.

The overall risk factor of setting some number of cities ablaze is the sum of the risk factors of setting each of the cities ablaze. Vincent's goal is to set the whole town ablaze with minimal risk by picking some set of cities to set ablaze. Let M be the minimum risk he takes when setting the entire city ablaze. Calculate the number of ways to pick a set of cities to obtain a risk of M.

Input:

The first line contains an integer N, the number of cities in Fatland.

The second line contains N space-separated integers, the i-th integer representing E[i]. (1-based index)

The third line contains an integer K, denoting the number 2-way roads.

Each of the next K lines contains 2 space-separated integers i, j, a road between cities i and j.

Output: Output one integer, W. The number of ways to pick a set of cities to obtain a risk of M, so that the entire town is set ablaze is U. W is the remainder when U is divided by 109+7=1000000007.

Constraints:

1 <= N <= 103

1 <= K <= 103

1 <= E[i] <= 103
*/

# include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 10 ;

int parent[N] ;     // parent[i] = parent of node 'i'
int size[N] ;       // size[i] = no. of elements whose parent is 'i'
int risk[N] ;       // risk[i] = risk of setting city 'i' on fire


void make ( int v ) // Create a new set/tree
{
    parent[v] = v ; 
    // When creating a new group, the single element is also the root of the group
    size[v] = 1 ;
}

int find ( int v )   // Return the parent/root of the group that contains node 'v'
{
    if ( v == parent[v] )   // This is the parent itself
        return v ;
    
    return parent[v] = find(parent[v]) ;    // Path Compression and Recursion

    // If this is not the parent, then we return the parent of the current node, and we also then
    // change the parent of the current node with the its parent, which goes on until, by the end
    // each node in this group, will have a common parent
}

void Union ( int a , int b )    // Join the groups containing node 'a' and node 'b'
                                // Root of one of the groups, gets connected to root of another
                                // This happens irrespective of the parameters of the function
                                // 'union' is a reserved keyword, so we use 'Union' instead
{
    a = find(a) ;
    b = find(b) ;

    if ( a != b )   // We can't join them, if they already belong to the same group
    {
        // We join the smaller tree to the bigger tree.
        if ( size[a] >= size[b] )
        {
            parent[b] = a ;
            size[a] += size[b] ;    // All nodes of 'a' joined to 'b'
        }
        else
        {
            parent[a] = b ;
            size[b] += size[a] ;    // All nodes of 'b' joined to 'a'.
        }
    }
}

bool cmp ( int a , int b )
{
    return ( risk[a] <= risk[b] ) ;
}

int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;

    int n ;
    cin >> n ;
    // We have to find the number of distinct connected componenets

    for ( int i = 1 ; i <= n ; i++ )
    {
        cin >> risk[i] ;
        make(i) ;
    }

    int k ;
    cin >> k ;

    while ( k-- )
    {
        int u , v ;
        cin >> u >> v ;

        Union(u,v) ;
    }


    long long ans = 1 , M = 1e9 + 7;
    unordered_map<int,vector<int>> mp ;

    for ( int i = 1 ; i <= n ; i++ )
        mp[find(i)].push_back(i) ;  // Add all the disjoint sets into vectors

    for ( auto &x: mp )
    {
        // cout << x.first << ": " ;
        // for ( auto &y: x.second )
        //     cout << y << ":" << risk[y] << " " ;
        // cout << endl ;
        sort(x.second.begin(),x.second.end(),cmp) ; // Sort the vector, and find the min values
        int count = 1 ;
        for ( int i = 1 ; i < x.second.size() ; i++ )
            if ( risk[x.second[i]] == risk[x.second[0]] )
                count++ ;
            else
                break ;
        
        ans = ( ans%M * count%M )%M ;
    }

    cout << ans << endl ;

    return 0 ;    
}