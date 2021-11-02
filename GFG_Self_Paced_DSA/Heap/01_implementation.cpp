# include <bits/stdc++.h>
using namespace std ;

// A class used to define a custom min heap
class min_heap
{
        int *arr ;
        int size , capacity ;

    public :
        min_heap ( int c )  // Constructor
        {
            size = 0 , capacity = c ;
            arr = new int[c] ;
        }

        int left ( int i )  { return (2*i + 1) ; }
        int right ( int i )  { return (2*i + 2) ; }
        int parent ( int i )  { return (i-1)/2 ; }

        void insert ( int x )
        {
            if ( size == capacity ) // If the array is already full, return
                return ;

            size++ ;    // Else, increment the size of the array, as one more element is added

            arr[size-1] = x ; // 1st Place the new element, at the very last position

            // Now check, if it satisfies the min heap condition which states that, all the
            // children of a node should be greater than it. And unless it satisfies this
            // value, keep swapping this new element with its parent element

            for ( int i = size-1 ; i != 0 && arr[parent(i)] > arr[i] ; )
            {
                swap ( arr[parent(i)] , arr[i] ) ;
                i = parent(i) ; // Update the cur value of i, after swapping
            }
        }

        void min_heapify ( int i )
        {
            int lt = left(i) , rt = right(i) , smallest = i ;

            // Find the minimum of : cur node , its left child , and its right child
            if ( lt < size && arr[lt] < arr[smallest] )
                smallest = lt ;
            if ( rt < size && arr[rt] < arr[smallest] )
                smallest = rt ;
            
            if ( smallest != i )
            {
                swap ( arr[i] , arr[smallest] ) ;
                min_heapify ( smallest ) ;
            }
        }

        int extract_min ()
        {
            if ( size <= 0 )
                return INT_MAX ;    // Return inf, if the heap is empty
            
            if ( size == 1 )
            {
                //size-- ;
                //return ( arr[0] ) ;    // return arr[0] , and then do size--
                return ( arr[size-- -1] ) ;
            }
            swap ( arr[0] , arr[size-1] ) ; // Swap the first and last element
            size-- ;    // Now, remove the last element 
            min_heapify (0) ;   // Now place the last element at its correct position in heap

            return arr[size] ; // Return the smallest element, which was placed at arr[size-1]
            // But then we did size--, so now, it's position is arr[size]
        }

        void decrease_key ( int i , int x )
        {
            arr[i] = x ;

            while ( i != 0 && arr[parent(i)] > arr[i] )
            {
                swap ( arr[i] , arr[parent(i)] ) ;
                i = parent(i) ;
            }
        }

        void delete_key ( int i )
        {
            decrease_key ( i , INT_MIN ) ;
            extract_min() ;
        }

        void build_heap ()
        {
            for ( int i = (size-2)/2 ; i >= 0 ; i-- )
                min_heapify(i) ;
        }
};

// Driver Function
int main ()
{
    ios_base :: sync_with_stdio (false) ;

    cin.tie(NULL) ;
    cout.tie(NULL) ;

    // Implementation
    min_heap h (11) ;       // 11 == size of the array

    // Insertion
    h.insert(3) ;
    h.insert(2) ;
    h.insert(15) ;
    h.insert(20) ;

    min_heap h1 (12) ;

    // Heapify and Extract_min
    // Min heapify : Given a binary heap, with one possible violation, fix the heap.
    // Extract_min : Remove the lowest element(root), and modify the remaining min_heap, such
    // that it remains a valid min heap.
    cout << h.extract_min() << endl ;

    // Decrease_key : Insert the given element, at the given position, and then, rearrage it
    // such that it goes to its correct position in the min heap
    h.decrease_key ( 2 , 1 ) ;

    // Delete_key : Delete the key at the given position, and rearrage the remaining elements
    // We can just do a decrease_key, with the inserted element being INT_MIN, that way,
    // it will go to the root node, from where we can perform an extract_min in order to remove
    // it from the min heap.
    h.delete_key ( 1 ) ;

    // build_heap : Given a random array, rearrange its elements to form a min_heap
    h.build_heap() ;

    return 0 ;
}