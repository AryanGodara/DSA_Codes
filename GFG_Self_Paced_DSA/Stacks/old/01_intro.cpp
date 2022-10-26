//? Array implementation of Stack in C++

# include <bits/stdc++.h>
using namespace std ;

//? Using Array
struct MyStack {
    int *arr ;
    int cap , top ;

    MyStack ( int c )
    {
        cap = c , top = -1 ;
        arr = new int[cap] ;
    }

    void push ( int x )
    {
        if ( top == cap-1 )
            cout << "Stack is full\n" ;
        else
            arr[++top] = x ;
    }

    int pop ()
    {
        if ( top == -1 )
            cout << "Stack is empty\n" ;
        else
            return arr[top--] ;
    }

    int peek ()
    {
        if ( top == -1 )
            cout << "Stack is empty\n" ;
        else
            return arr[top] ;
    }

    int size ()
    {
        return top+1 ;
    }

    bool isEmpty()
    {
        return top == -1 ;
    }
};


//? Using Vector
struct MyStackV {
    vector <int> v ;

    void push ( int x )
    {
        v.push_back(x) ;
    }

    int pop ()
    {
        int res = v.back() ;
        v.pop_back() ;
        return res ;
    }

    int peek ()
    {
        return v.back() ;
    }

    int size ()
    {
        return v.size() ;
    }

    bool isEmpty ()
    {
        return v.empty() ;
    }
};


//? Driver Function
int main()
{
    MyStack s(5);
    
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
  
    return 0; 
}