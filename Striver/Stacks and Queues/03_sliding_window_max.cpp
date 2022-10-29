# include <bits/stdc++.h>
using namespace std ;

vector <int> arr = {1,3,-1,3,5,3,6,7};

int main()
{
    deque<int> dq ;
    // Pushfront, Pushback, Popfront, Popback

    // Maintain size of dq as k

    int n = arr.size() , k = 3 ;

    // Logic
    /*
    1. Store elements in deque in decreasing order from front to back.
    2. If the element at either end are more than k distance away from the current element, pop them.
    3. If the element is greater than the greatest element, place it at front, and popback.
    3.1. Else, keep popping from back, for all elements smaller than the current element
    4. For each step, print the front element of the deque
    */

    for ( int i = 0 ; i < n ; i++ ) // For each, print the value of max of the last k elements
    {
        if ( dq.empty() )
            dq.push_back(i) ;

        // Else, clean deque
        while ( !dq.empty() && dq.front() < i-k+1 )
                dq.pop_front();

        if ( arr[i] > arr[dq.front()] )
        {
            dq.push_front(i);
            dq.pop_back();
        }
        else
        {
            while ( !dq.empty() && arr[dq.back()] < arr[i] )
                dq.pop_back();
            dq.push_back(i);
        }

        // Last step
        if ( i >= k-1 )
        {
            cout << arr[dq.front()] << endl ;
        }
    }
}

class Solution {
public:
int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() ;
        vector<vector<bool>> rotten(m, vector<bool>(n,0));
        vector<vector<bool>> visited(m, vector<bool>(n,0));
        
        queue<pair<int,int>> q ;
        
        bool flag = 0 ;
        int freshcount = 0 ;
        
        for ( int i = 0 ; i < m ; i++ )
        {
            for ( int j = 0 ; j < n ; j++ )
            {
                if (grid[i][j] != 0)
                    flag = true ;
             
                if (grid[i][j] == 1)
                    freshcount++ ;
                
                if ( grid[i][j] == 2 )
                {
                    rotten[i][j] = true ;
                    q.push({i,j});
                }
            }
        }
        if (!q.size())
        {
            // No rotten tomatoes, 
            // Only works if the entire grid is empty
            return flag ? 0 : -1 ;
        }
        return solve(grid , q , m , n , freshcount , rotten, visited);
    }

    int solve(
        vector<vector<int>>&grid ,
        queue<pair<int,int>> &q ,
        int m , int n , int freshcount ,
        vector<vector<bool>>&r ,
        vector<vector<bool>>&v
    )
    {
        // Apply DFS here.
        // From each element in the queue, travel to all possible fresh tomatoes.
        int time = 0 ;  // Time elapsed in rotting of oranges.
        queue <pair<int,int>> temp ;
        
        while ( !q.empty() )
        {
            // First, 1 minute elapses
            time++ ;
            
            // Remove all elements currently in the queue, and rot the elements 
            // adjacent to them, and them add them to the queue.
            while(!q.empty())
            {
                pair<int,int> p = q.front();
                q.pop();
                
                int i = p.first , j = p.second;
                
                if (v[i][j])
                    continue ;
                v[i][j] = true ;
                
                if ( i+1 < m && grid[i+1][j]==1 && !v[i+1][j]){
                    temp.push({i+1,j});
                    freshcount--;
                    r[i+1][j] = true;
                }
                if ( j+1 < n && grid[i][j+1]==1 && !v[i][j+1]){
                    temp.push({i,j+1});
                    freshcount--;
                    r[i+1][j] = true;
                }
                if ( i-1 < 0 && grid[i-1][j]==1 && !v[i-1][j]){
                    temp.push({i-1,j});
                    freshcount--;
                    r[i+1][j] = true;
                }
                if ( j-1 < 0 && grid[i][j-1]==1 && !v[i][j-1]){
                    temp.push({i,j-1});
                    freshcount--;
                    r[i+1][j] = true;
                }
            }
            // Now, current queue is empty (1 layer removed)   
            // Second layer is in the temp queue
            // All the oranges have been marked as rotten
            q = temp ;  // Replace q with temp ;
        }
        
        if ( freshcount )   // Couldn't rot all the oranges
            return 0 ;
        
        return time ;
    }
};