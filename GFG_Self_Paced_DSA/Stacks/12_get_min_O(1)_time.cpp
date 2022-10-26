# include <bits/stdc++.h>
using namespace std ;

struct MyStack {
    stack <int> ms ;
    stack <int> as ;

    void push ( int x )
    {
        if ( ms.empty() )   // This was the first element pushed to empty stack
        {
            ms.push(x);
            as.push(x);

            return ;
        }

        ms.push(x) ;

        if ( as.top() >= ms.top() ) // Found a smaller element
            as.push(x) ;
    }

    void pop ()
    {
        if ( as.top() == ms.top() )
            as.pop() ;  // We lost the current minimum element
        
        ms.pop() ;
    }

    int top () { return ms.top() ; }

    int getMin () { return as.top() ; }
};

int main ()
{
    MyStack s ;

    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop() ;

    cout << "Minimum Element from Stack: " << s.getMin() << endl ;

    return 0 ;
}