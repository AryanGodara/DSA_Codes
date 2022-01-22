//? This Problem discusses the Topological Sorting using a DFS Based Algorithm

# include <bits/stdc++.h>
using namespace std ;

/*
    1. Create an empty stack, st
    2. For every vertex u, do the following :
        if ( u is not visited )
            DFS(u,st)
    3. while ( st is not empty )
        pop an item from st and print it

    DFS(u,st)
        1. Mark u as visited
        2. For every adjancent v of u
            if v is not visited
                DFS(v,st)
        3. Push u to st
*/