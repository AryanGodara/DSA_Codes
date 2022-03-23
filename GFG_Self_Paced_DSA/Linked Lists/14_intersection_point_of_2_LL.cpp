# include <bits/stdc++.h>
using namespace std ;

struct Node {
    int data ;
    Node *next ;

    Node ( int x )
    {
        data = x ;
        next = NULL ;
    }
};

// O(2N) Naive solution, is to use hashing to store the values of one LL in the hash,
// And then simply merge the values

//* Returns 'data' of the node where h1 and h2 intersect (Y shap conenction)
int getIntersection_hash ( Node *h1 , Node *h2 )
{
    unordered_set <Node *> s ;

    Node *cur = h1 ;
    while ( cur != NULL )
    {
        s.insert(cur) ;
        cur = cur->next ;
    }
    
    cur = h2 ;

    while ( cur != NULL )
    {
        if ( s.find(cur) != s.end() )
            return cur->data ;
        cur = cur->next ;
    }

    return -1 ;
}

//? Method 2
// 1. Count nodes in both the lists, say, c1 and c2
// 2. Traverse the bigger list abs(c1-c2) times
// 3. Traverse both teh lists simultaneously until we see a common node.
// 4. This is the common node, return it

int get_count ( Node *head )
{
    Node *cur = head ;

    int ret = 0 ;
    while ( cur != NULL )
    {
        ret++ ;
        cur = cur->next ;
    }

    return ret ;
}

int get_intersection_efficient ( Node *h1 , Node *h2 )
{
    Node *cur1 = h1 , *cur2 = h2 ;

    int c1 = get_count(h1) , c2 = get_count(h2) , d = abs(c1-c2) ;

    if ( c1 > c2 )  // Traverse the longer array
    {
        for ( int i = 0 ; i < d ; i++ )
        {
            if ( cur1 == NULL )
                return -1 ;
            cur1 = cur1->next ;
        }

        while ( cur1 != NULL && cur2 != NULL )
        {
            if ( cur1 == cur2 )
                return cur1->data ;

            cur1 = cur1->next ;
            cur2 = cur2->next ;
        }
    }
    else
    {
        for ( int i = 0 ; i < d ; i++ )
        {
            if ( cur2 == NULL )
                return -1 ;
            cur2 = cur2->next ;
        }

        while ( cur1 != NULL && cur2 != NULL )
        {
            if ( cur1 == cur2 )
                return cur1->data ;

            cur1 = cur1->next ;
            cur2 = cur2->next ;
        }
    }
    
}