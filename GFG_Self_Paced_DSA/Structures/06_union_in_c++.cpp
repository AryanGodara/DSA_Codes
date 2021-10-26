# include <bits/stdc++.h>
using namespace std ;

/*
    Union is used to create a user-defined data type like structures and classes.
    They're syntactically similar to structures and classes.

Similarities between Structure and Union

1. Both are user-defined data types used to store data of different types as a single unit.
2. Their members can be objects of any type, including other structures and unions or arrays. 
   A member can also consist of a bit field.
3. Both structures and unions support only assignment = and sizeof operators. The two structures 
   or unions in the assignment must have the same members and member types.
4. A structure or a union can be passed by value to functions and returned by value by functions. 
   The argument must have the same type as the function parameter. A structure or union is passed 
   by value just like a scalar variable as a corresponding parameter.
5. ‘.’ operator is used for accessing members.

How are unions different from structures ?
    1. When a variable is associated with a union, the compiler allocates teh memory by
       considering the size of the largest memory. So, size of union is equal to the size of
       the largest member.
    2. Memory allocated, is shared by the individual members of the union.
    3. Altering the value of the member will alter other member values
    4. One one member can be accessed at a time
    5. Only the first member of a union can be initialized.


One major use of Unions :-
Type punning is the possibility of a programming language intentionally subvert the type system 
to treat a type as a different type. One typical way to do type punning in C++ is to read the 
member of a union with a different type from the one with which it was written.
*/

union Test
{
    int x , y ; // 4 byte each
    char w ;    // 1 byte
    double z ;  // 8 bytes
} ;

/*
We can use it to know how a variable is stored in different data types inside the system
Let's look at the examples below
*/

union Test1
{
    int x ;
    float y ;
} ;

union Test2
{
    int x ;
    char bin[4] ;
} ;


/*
    Another Application of Unions :-
    Using anonymous union to use one type for multiple reaons
*/

// A Node structure that can be used for both a Doubly Linked List, and a Binary Tree
struct Node
{
    int data ;

    union
    {
        struct
        {
            Node *left , *right ;   // Binary Tree
        } ;
        struct
        {
            Node *prev , *next ;    // Doubly Linked List
        } ;
    } ;

    Node ( int x )  // Constructor
    {
        data = x ;
    }

} ;

void makeDLL ()
{
    Node *head = new Node(1) ;
    head -> next = new Node(2) ;
    auto tail = head -> next ;
    tail -> prev = head ;
    tail -> next = NULL ;

    auto i = head ;
    while ( i != NULL ) 
    {
        cout << i->data << " " ;
        i = i->next ;
    }
}

void makeBT ()
{
    Node *root = new Node(1) ;
    root -> left = new Node(2) ;
    root -> right = new Node(3) ;

    queue <Node*> q ;
    q.push(root) ;

    while ( !q.empty() )
    {
        auto t = q.front() ;
        q.pop() ;

        cout << t->data << " " ;

        if ( t->next != NULL )
            q.push(t->left) ;
        if ( t->next != NULL )
            q.push(t->right) ;
    }
}

// Driver Function
int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    // Basics :-
    Test t ;
    t.x = 10 ;
    cout << t.x << " " << t.y << endl ;
    t.y = 20 ;
    cout << t.x << " " << t.y << endl ;
    
    cout << sizeof(t) << endl ; // OP : 8   ; Equal to the largest data type

    // Type punning :-
    Test1 t1 ;
    t.y = 1.1 ;
    cout << endl << "t1.x = " << t1.x << endl << endl ; // Value changes on each run

    Test2 t2 ;
    t2.x = 512 ;

    cout << (int)t2.bin[0] << " " << (int)t2.bin[1] << " " << (int)t2.bin[2] << " "
         << (int)t2.bin[3] << endl ;

    // Anonymous Union Node
    cout << endl ;

    makeDLL() ;
    cout << endl ;

    makeBT() ;
    cout << endl ;

    return 0 ;
}