/*
* 

? ALGORITHM :-

* 1. Create an empty queue q.
* 
* 2. Find all rotten oranges and enqueue them to q. Also enqueue a delimiter to indicate the 
*    beginning of next time frame.
* 
* 3. While q is NOT empty, do the following :-
*    a) Do following while delimiter is not reached.
*       (i) Dequeue an orange from queue, rot all the adjacent oranges. While rotting the
*           adjacent, make sure that the time frame is incremented only once. And the time
*           frame is not incremented if there are no adjacent oranges.
*    b) Dequeue the old delimiter and enqueue a new delimiter. The oranges rotten in the
*       previous time fram lie between the two delimiters.

* 
*/

//? C++ Program to find the minimum nummber of time required to rot all oranges.

/*
* Description: Given a matrix of dimension m*n where each cell in the matrix can have values
* 0,1 or 2, which has the following meaning :-

* 0: Empty cell
* 1: Cells having fresh oranges
* 2: Cells having rotten oranges

TODO: We have to determine what is the minimum time required so that all the oranges become rotten.
! If it's impossible to rot every orange, then simply return -1 ;
*/

# include <bits/stdc++.h>
using namespace std ;

# define C 5
# define R 3

//? Function to check if the current 'cell' is a delimiter
bool isDelim ( pair<int,int> p )
{
    return p.first != -1 && p.second != -1 ;
}

//? Function to check whether the current cell is a valid cell in the matrix
bool isValid ( int x , int y )
{
    return x>=0 && y>=0 && x<R && y<C ;
}

//? Function to check if there are any unrotten oranges left in the matrix
bool checkAll ( int arr[R][C] )
{
    for ( int i = 0 ; i < R ; i++ )
        for ( int j = 0 ; j < C ; j++ )
            if ( arr[i][j] == 1 )   // Unrotten orange
                return true ;
    
    return false ;
}

//? The primary logic function, to count the minimum time required to rot all the oranges
int rotOranges ( int arr[R][C] )
{
    // Create a queue of cells
    queue <pair<int,int>> q ;

    int ans = 0 ;
    pair<int,int> temp ;

    // Store all the cells having rotten oranges in first time frame
    for ( int i = 0 ; i < R ; i++ )
    {
        for ( int j = 0 ; j < C ; j++ )
        {
            if ( arr[i][j] == 2 )
            {
                temp.first = i , temp.second = j ;
                q.push(temp);
            }
        }
    }

    // Separate these rotten oranges from the oranges which will rotten ue to the oranges in first 
    // time frame using deliter which is (-1,-1)
    temp.first = -1 , temp.second = -1 ;
    q.push(temp) ;

    // Process the grid while there are rotten oranges in the queue
    while ( !q.empty() )
    {
        // This flag is used to determine whether even a single fresh orange gets rotten due to 
        // rotten oranges in current time frame, so we can increase the count of the required time
        bool flag = false ;

        // Process all the rotten oranges in current time frame
        while ( !isDelim(q.front()) )
        {
            temp = q.front() ;

            // Check right adjacent cell that if it can be rotten, increase count and set the flag
            if ( isValid(temp.first + 1, temp.second) && arr[temp.first + 1][temp.second] == 1 )
            {
                // If this is the first orange to get rotten, increase rotten and set the flag
                if ( !flag )
                    ans++ , flag = true ;
                
                // Make the orange rotten
                arr[temp.first + 1][temp.second] = 2 ;

                // Push the adjacent orange to Queue
                temp.first ++ ;

                q.push(temp) ;

                temp.first -- ; // Move back to the current cell
            }

            // Check left adjacent cell that if it can be rotten, increase count and set the flag
            if ( isValid(temp.first - 1, temp.second) && arr[temp.first - 1][temp.second] == 1 )
            {
                // If this is the first orange to get rotten, increase rotten and set the flag
                if ( !flag )
                    ans++ , flag = true ;
                
                // Make the orange rotten
                arr[temp.first - 1][temp.second] = 2 ;

                // Push the adjacent orange to Queue
                temp.first ++ ;

                q.push(temp) ;

                temp.first -- ; // Move back to the current cell
            }

            // Check top adjacent cell that if it can be rotten, increase count and set the flag
            if ( isValid(temp.first , temp.second - 1 ) && arr[temp.first][temp.second - 1] == 1 )
            {
                // If this is the first orange to get rotten, increase rotten and set the flag
                if ( !flag )
                    ans++ , flag = true ;
                
                // Make the orange rotten
                arr[temp.first][temp.second - 1] = 2 ;

                // Push the adjacent orange to Queue
                temp.first ++ ;

                q.push(temp) ;

                temp.first -- ; // Move back to the current cell
            }

            // Check bottom adjacent cell that if it can be rotten, increase count and set the flag
            if ( isValid(temp.first, temp.second + 1) && arr[temp.first][temp.second + 1] == 1 )
            {
                // If this is the first orange to get rotten, increase rotten and set the flag
                if ( !flag )
                    ans++ , flag = true ;
                
                // Make the orange rotten
                arr[temp.first][temp.second + 1] = 2 ;

                // Push the adjacent orange to Queue
                temp.first ++ ;

                q.push(temp) ;

                temp.first -- ; // Move back to the current cell
            }

            q.pop() ;
        }

        q.pop() ;   // Pop the delimiter

        // If oranges were rotten in current frame than separate the rotten oranges using delimiter
        // for the next frame for processing
        if ( !q.empty() )
        {
            temp.first = -1 , temp.second = -1 ;
            q.push(temp) ;
        }

        // If Queue was empty than no rotten oranges left to process so exit
    }

    // Return -1 if all oranges couldn't rot, otherwise -1
    return ( checkAll(arr) ? -1 : ans ) ;
}

//? Driver Function
int main ()
{
    int arr1 [R][C] = {
        {2,1,0,2,1},
        {1,0,1,2,1},
        {1,0,0,2,1}
    };

    int arr2 [R][C] = {
        {2,1,0,2,1},
        {0,0,1,2,1},
        {1,0,0,2,1}
    };

    cout << rotOranges(arr1) << endl ;
    cout << rotOranges(arr2) << endl ;

    return 0 ;
}