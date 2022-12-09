// Alien Dictionary : Topological sort

/*
Given a sorted dictionary in an alien language having N words and k starting alphabets of the standard alphabet,
find the order of characters in the alien language.

Note : Many orders may be possible for a particular test case, thus you may return any valid order.
*/

/*
? Code Example :
N = 5 , k = 4
Dict = { "baa" , "abcd" , "abca" , "cab", "cad" }

* Answer
In the alien language, the corret alphabetical order is : b -> d -> a -> c

So, the task is to form some sort of DAG, then use topological sort or DFS to get the order of alphabets.
And any alphabets that are non-connected components (solo nodes without any edges), can be placed anywhere we want.
*/

/*
2 cases where the given order is illogical -> order is not possible

a. We get a cyclic graph (cyclic logic for the ascending order)
b. We get two strings, eg.: abcd and abc, but abcd is placed before abc, which is completely illogical.
*/

# include <bits/stdc++.h>
using namespace std ;

int main()
{
    int n , k ;
    cin >> n >> k ;

    vector <vector<int>> dict(n) ;

    for ( int i = 0 ; i < n ; i++ )
    {
        string s ;
        cin >> s ;

        vector <int> cur ;

        for ( auto &c : s )
            cur.push_back(c-'a') ;  // Convert string to numerical array

        dict[i] = cur ;
    }

    // Now, for each directed 
    vector <vector<int>> g(n,vector<int>()) ;
}