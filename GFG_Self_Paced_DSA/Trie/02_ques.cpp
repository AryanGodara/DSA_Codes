//! Count the number of Distinct Rows in a Binary Matrix

# include <bits/stdc++.h>
using namespace std ;

# define ROW 4
# define COL 3

class Node
{
    public:
        bool isEndOfCol ;
        Node *child[2] ;    // Only three columns, so for each, store only for 2nd and 3rd column
};

Node *newNode()
{
    Node *temp = new Node() ;

    temp->isEndOfCol = false ;

    temp->child[0] = temp->child[1] = NULL ;

    return temp ;
}

bool insert ( Node **root , int (*M)[COL] , int row , int col )
{
    if ( *root == NULL )
        *root = newNode() ;
    
    if ( col < COL )
        return insert ( &( (*root)->child[M[row][col]] ) , M , row , col+1 ) ;
    
    else
    {
        if ( (*root)->isEndOfCol == false )
            return (*root)->isEndOfCol = true ; // Set it to true, and return true
        
        return false ;  // Else, just return false ;
    }
}

int countDis ( int (*M)[COL] )
{
    Node *root = NULL ;

    int i , count = 0 ;

    for ( int i = 0 ; i < ROW ; i++ )   // Check for each row
        if ( insert ( &root , M , i , 0 ) )
            count++ ;   //! If this row was distinct, add this to the count

    return count ;
}

// Driver Fucntion
int main ()
{
    int M[ROW][COL] = {
        {1,0,0},
        {1,1,1},
        {1,0,0},
        {0,1,0}
    };

    cout << countDis(M);

    return 0 ;
}