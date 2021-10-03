// The C++ STL offers a built-in class named stack for implementing the stack data structure easily
// and efficiently. This class provides almost all functions needed to perform the standard stack
// operations like push() , pop() , peek() , remove() , etc.
# include <bits/stdc++.h>
using namespace std ;

// Program to demonstrate the working of STL stack
void showstack ( stack <int> s )
{
    while ( ! s.empty() )
    {
        cout << s.top() << " " ;
        s.pop() ;
    }
    cout << endl ;
}
int main ()
{
    stack <int> s ;
    s.push(10) ;
    s.push(30) ;
    s.push(20) ;
    s.push(5) ;
    s.push(1) ;

    cout << "The stack is :\n" ;
    showstack(s) ;

    return 0 ;
}

/*
The Stack is a linear data structure, which follows a particular order in which the operations are
performeed. The order may be LIFO or FILO.

Mainly, the following three basic operations are performed in the stack :-
1. Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition
2. Pop: Removes an item from the stack. The items are popped in the reversed order in which they
        were pushed. If the stack is empty, then it is said to be an Underflow condition.
3. Peek or Top: Returns the top element of the stack.

4. isEmpty: Returns true is the stack is empty, else false
*/

// Implementation of Stack using Arrays :-

// Implementation of Stack using LLists :-

// Pros: The LL implementation of stack can either grow or shrink according to the needs at runtime.
// Cons: Requires extra memory due to involvement of pointers.

/*
Applications of stack:
1. Stack can be used to check for the balancing of parenthesis in an expression.
2. Infix ot Postfix/Prefix conversion
3. Redo-undo features at many places such as editors, photoshop, etc.
4. Forward and backward feature in web browsers.
    And many more...
*/