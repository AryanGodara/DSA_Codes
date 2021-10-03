# include <iostream>
# include <deque>

using namespace std ;

void printdeque ( deque <int> dq )
{
    for ( auto &x : dq )
        cout << x << " " ;
    cout << endl << endl ;
}

int main ()
{
    deque <int> d1 = {10,20,30} ;

    d1.push_front(5) ;
    d1.push_back(50) ;

    cout << "After push_front(5) and push_back(50):\n" ;
    printdeque(d1) ;
    cout <<d1.front() << " " << d1.back() << endl << endl ;


    deque <int> dq = {10,15,30,5,12} ;
    printdeque(dq) ;

    auto it = dq.begin() ;
    it++ ;
    dq.insert(it,20) ;
    printdeque(dq) ;

    dq.pop_back() ;
    printdeque(dq) ;

    dq.pop_front() ;
    printdeque(dq) ;

    cout << "Current size is : " << dq.size() << endl << endl ;


    it = dq.begin() ;

    it = dq.insert(it,7) ;
    cout << "After inserting 7: " << *it << endl ;
    printdeque(dq) ;

    it = dq.insert(it,2,3) ;
    cout << "After inserting 2,3: " << *it << endl ;
    printdeque(dq) ;

    it = dq.erase(it+1) ;
    cout << "After erasing it+1: " << *it << endl ;
    printdeque(dq) ;

    return 0 ;
}