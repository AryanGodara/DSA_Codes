# include <bits/stdc++.h>
using namespace std ;

//? Implement two stacks inside a single array

//? Divide the space in two halves
struct TwoStacks {
    int *arr ;
    int cap , top1 , top2 ;

    TwoStacks ( int n )
    {
        cap = n ;   // Stacks start from the middle, and extend outwards towards left and right extremes
        arr = new int[n] ;
        top1 = n/2 + 1 ;
        top2 = n/2 ;
    }

    void push1 ( int x )
    {
        if ( top1>0 )
            arr[--top1] = x ;
        else
            cout << "Stack Overflow by element : " << x << endl ;
    }

    void push2 ( int x )
    {
        if ( top2 < cap-1 )
            arr[++top2] = x ;
        else
            cout << "Stack Overflow by element : " << x << endl ;
    }

    int pop1 ()
    {
        if ( top1 <= cap/2 )
            return arr[top1++] ;    // Remove element(so move forward) (stack if from left (top) to right)
        else
            cout << "Stack Overflow\n" ;
        
        exit(1) ;
    }

    int pop2()
    {
        if ( top2 >= cap/2 + 1 )
            return arr[top2--] ;
        else
            cout << "Stack Overflow\n" ;
        
        exit(1) ;
    }
};

//? A space efficient implementation
struct TwoStcks {
    int *arr ;
    int cap , top1 , top2 ;

    TwoStcks ( int n )
    {
        cap = n ;
        arr = new int[n] ;
        top1 = -1 , top2 = cap ;    // Stacks start from extreme left, and extreme right (and inward)
    }

    void push1 ( int x )
    {
        if ( top1 < top2-1 ) // There is still space to add one here
            arr[++top1] = x ;
        else
            cout << "Stack Overflow\n" ;
        
        exit(1) ;
    }

    void push2( int x )
    {
        if ( top1 < top2-1 ) // There is still space to add one here
            arr[--top2] = x ;
        else
            cout << "Stack Overflow\n" ;
        
        exit(1) ;
    }

    int pop1 ()
    {
        if ( top1 >= 0 ) // Elements are present in stack 1
            return arr[top1--] ;
        else
            "Stack Underflow\n" ;
        
        exit(1) ;
    }

    int pop2 ()
    {
        if ( top2 < cap ) // Elements are present in stack 2
            return arr[top2++] ;
        else
            cout << "Stack Underflow\n" ;
        
        exit(1) ;
    }
};

//? Driver Function
int main() 
{ 
    //* First Implementation
    TwoStacks ts(5) ;
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is: " << ts.pop1() << endl; 
    ts.push2(40); 
    cout << "Popped element from stack2 is: " << ts.pop2() << endl; 

    //* Second Implementation
    TwoStcks ts2(5); 
    ts2.push1(5); 
    ts2.push2(10); 
    ts2.push2(15); 
    ts2.push1(11); 
    ts2.push2(7); 
    cout << "Popped element from stack1 is "<<ts2.pop1(); 
    ts2.push2(40); 
    cout << "\nPopped element from stack2 is "<< ts2.pop2(); 

    return 0; 
}