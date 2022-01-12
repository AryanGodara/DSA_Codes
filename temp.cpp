#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5 ;

vector <bool> isPrime (N,true) ;

struct Node{
    int data ;
    Node *left , *right ;

    Node (int x)
    {
        data = x ;
        left = right = NULL ;
    }
};

int main() 
{
    ios_base :: sync_with_stdio (false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;


    Node *root = new Node(5) ;
    root->left = new Node(2) , root->right = new Node(7);
    root->left->right = new Node(3) , root->left->right->left = new Node(4);
    root->right->right = new Node(8);

    queue <Node *> q ;
    q.push(root);
    vector <int> ret ;

    while ( !q.empty() )
    {
        auto cur = q.front() ;
        q.pop() ;

        ret.push_back(cur->data);

        if ( cur->left )
            q.push(cur->left);
        if ( cur->right )
            q.push(cur->right);
    }

    for ( auto &x : ret )
        cout << x << " " ;

	return 0;
}