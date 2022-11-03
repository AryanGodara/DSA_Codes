# include <bits/stdc++.h>
using namespace std ;

// For aabb
/*
First do partition as a|abb
Now since a is pallindrome, call function recursively for abb
-> a| ->
    a|bb ->
    a|a| ->
        b|b| ---> a|a|b|b
        bb| --->  a|a|bb
    a|a|b *** Not a pallindrome, break
*/

bool isPallindrome( string &arr , int s , int e )
{
    while (s<e)
        if ( arr[s++] != arr[e--] )
            return false ;
    
    return true ;
}

void solve ( vector<vector<string>> &ret , string &arr , vector<string> &cur , int i , int n )
{
    // Base Case
    if (i == n)
    {
        ret.push_back(cur);
        return ;
    }

    // Recursion
    for ( int j = i ; j < n ; j++ )
    {
        if ( isPallindrome(arr,i,j) )
        {
            cur.push_back(arr.substr(i,j-i+1));
            solve(ret,arr,cur,j+1,n);
            cur.pop_back();
        }
    }
}

vector<vector<string>> pallindrome_partitioning ( string arr , int n )
{
    vector<vector<string>> ret ;
    vector<string> cur ;

    solve(ret,arr,cur,0,n);

    return ret ;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);

    ios_base::sync_with_stdio(false);

    string arr = "aabb" ;
    vector<vector<string>> ret = pallindrome_partitioning(arr,arr.size());

    for ( auto &x: ret )
    {
        for ( auto &y: x )
            cout << y << " | " ;
        cout << endl ;
    }
    return 0; 
}