# include <bits/stdc++.h>
using namespace std ;

// By default, we use a max_heap, but a min_heap can also be used

/* Also, make some notes from GFG_Text  

Applications :-
    Dijkstra's Algorithm
    Prim Algorithm
    Huffman Algorithm
    Heap Sort
    And any other place heap is used
*/

/*
int main ()
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;

    // Using Max Heap
    priority_queue <int> pq1 ;
    pq1.push(10) ;
    pq1.push(15) ;
    pq1.push(5) ;

    cout << pq1.size() << " " << pq1.top() << endl ;
    while ( ! pq1.empty() )
    {
        cout << pq1.top() << " " ;
        pq1.pop() ;
    }

    // Using Min Heap
    priority_queue < int , vector<int> , greater<int> > pq2 ;
    pq2.push(10) ;
    pq2.push(15) ;
    pq2.push(5) ;

    cout << pq2.size() << " " << pq2.top() << endl ;
    while ( ! pq2.empty() )
    {
        cout << pq2.top() << " " ;
        pq1.pop() ;
    }

    // Implementing using an existing vector, or an array
    // This method is faster, 
    vector <int> arr = { 10 , 5 , 15 } ;

    priority_queue <int> pq ( arr.begin() , arr.end() ) ; // Automatically gets sorted // O(N)
    while ( ! pq.empty() )
    {
        cout << pq.top() << " " ;
        pq.pop() ;
    }

    // If we want to utilize normal priority queue as a max_heap, we can store each element
    // as its negative (additive inverse), so their order will get reversed, and whenever
    // you want to use or print those elements, multiply them with -1 again, to retreive the
    // original elements.

    return 0 ;
}
*/

// Using priority queue for user defined data types
// Eg.: Sorting people according to their heights

struct Person
{
    int age ;
    float ht ;

    Person ( int a , float h )  // Constructor
    {
        age = a ;
        ht = h ;
    }
};

struct cmp {
    bool operator () ( Person const &p1 , Person const &p2 ) // Operator Overloading
    {
        p1.ht <= p2.ht ;
    }
};

int main ()
{
    priority_queue < Person , vector<Person> , cmp > pq ;
}