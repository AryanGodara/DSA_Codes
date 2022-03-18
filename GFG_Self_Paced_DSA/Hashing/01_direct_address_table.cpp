# include <bits/stdc++.h>
using namespace std ;

//? Imagine a situatinos where your have 1000 keys with values from (0 to 999), how would you
//? implement following in O(1) time :- 1. Search 2. Insert 3. Delete

struct DAT {
    int table[1000] = {0} ;

    void insert ( int i ) { table[i] = 1 ; }
    void del ( int i ) { table[i] = 0 ; }
    int search ( int i ) { return table[i] ; }
};

// void insert ( DAT *dat , int i )
// {
//     dat->table[i] = 1 ;
// }

// void del ( DAT *dat , int i )
// {
//     dat->table[i] = 0 ;
// }

// int search ( DAT *dat , int i )
// {
//     return dat->table[i] ;
// }

//? Driver Function
int main ()
{
    DAT dat ;

    dat.insert(10) ;
    dat.insert(20) ;
    dat.insert(119) ;

    cout << dat.search(10) << endl ;
    cout << dat.search(20) << endl ;
    dat.del(119) ;
    cout << dat.search(119) << endl ;

    return 0 ;
}