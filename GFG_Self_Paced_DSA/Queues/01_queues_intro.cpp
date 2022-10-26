/*
Like Stack data structur, Queue is also a linear data structure that follows a particular order in
which the operations are performed. The order if FIFO.

Operations on Queues :-
1. Enqueue: Adds an item to the queue. If the queue is full, then it's said to be an overflow condition
2. Dequeue: Removes item from queue. If the queue is empty, then it's said to be an underflow condition
3. Front: Get the front item from queue
4. Rear: Get the last item from queue
*/

// Array implementation of queue
/*
For implementing it, we need to keep track of two indices, fron and rear. We enqueue an item in the
rear and dequeue an item from the front. 
If we simply increment front and rear indices, then there may be problems, the front may reach the
end of the array. The solution to this problem is to increase fron tand rear circular manner.
*/
/*
    Example :-
Array = queue[N]
front = 0 , rear = n-1
n = 5.

Operation 1 : enqueue(5)
front = 0 , rear = (n-1 + 1)%n = 0
Queue contains [5]

Operation 2 : enqueue(10)
front = 0 , rear = (0 + 1)%n = 1
Queue contains [5,10]

Operation 3 : enqueue(15)
front = 0 , rear = (1 + 1)%n = 2
Queue contains [5,10,15]

Operation 4 : deque() 
front = (front+1)%n = (0+1)%n = 1 , rear = 2
Queue contains [10,15]
*/


// Array Implementation of Queue in C++ :

# include <bits/stdc++.h>
using namespace std ;

// A structure to represent a queue
class Queue
{
    public:
        int front , rear , size ;
        unsigned capacity ;
        int* array ;
} ;


// Function to create a queue of given capacity, it initializes the size of the queue as 0
Queue* createQueue ( unsigned capacity )
{
    Queue* queue = new Queue() ;
    queue -> capacity = capacity ;
    queue -> front = queue-> size = 0 ;
    queue -> rear = capacity - 1 ;      // This is important, see the enqueue
    queue -> array = new int[(queue->capacity * sizeof(int))] ;

    return queue ;      // Returns the newly formed queue
}

// Queue is full when size becomes equal to the capacity
int isFull ( Queue* queue )
{
    return ( queue -> size == queue -> capacity ) ;
}

// Queue is empty when size becomes zero
int isEmpty ( Queue* queue )
{
    return ( queue -> size == 0 ) ;
}

// Fucntion to add an item to the queue, it changes rear and size
void enqueue ( Queue* queue , int item )
{
    if ( isFull(queue) )
        return ;
    
    queue -> rear = ( queue -> rear + 1 ) % queue -> capacity ;
    queue -> array[queue->rear] = item ;
    queue -> size = queue -> size + 1 ;
    cout << item << " enqueued to the queue" << endl ;
}

// Function to remove an itme from the queue, it changegs front and size
int dequeue ( Queue* queue )
{
    if ( isEmpty(queue) )
        return INT_MIN ;
    
    int item = queue -> array[queue->front] ;
    queue -> front = (queue -> front + 1 ) % queue -> capacity ;
    queue -> size = queue -> size - 1 ;
    return item ;
}

// Function to get front of the queue
int front ( Queue* queue )
{
    if ( isEmpty(queue) )
        return INT_MIN ;
    return queue -> array[queue->front] ;
}

// Function to return the rear of queue
int rear ( Queue* queue )
{
    if ( isEmpty(queue) )
        return INT_MIN ;
    return queue -> array[queue -> rear] ;
}


// Driver Code

int main ()
{
    Queue* queue = createQueue ( 1000 ) ;

    enqueue ( queue , 10 ) ;
    enqueue ( queue , 20 ) ;
    enqueue ( queue , 30 ) ;
    enqueue ( queue , 40 ) ;

    cout << dequeue(queue) << " dequeued from queue" << endl ;
    
    cout << "Front item is : " << front(queue) << endl ;
    cout << "Rear item is : " << rear(queue) << endl ;

    return 0 ;
}