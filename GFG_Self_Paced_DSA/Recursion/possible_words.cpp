# include <bits/stdc++.h>
using namespace std ;

vector<string> nums = { "0" , "1" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz" } ;

void possibleUtil ( vector<int> &a , vector<string> &res , int i = 0 ,  string cur = "" )
{
    // Base case
    if ( i == a.size() )
    {
        res.push_back(cur) ;
        return ;
    }
    int index = a[i] ;
    // cout << "a[i] = " << index << endl ;
    
    for ( int j = 0 ; j < nums[index].size() ; j++ )
    {
        // cout << nums[index][j] << endl ;
        possibleUtil(a,res,i+1,cur + nums[index][j]) ;
        // possibleUtil(a,res,i+1,cur) ;
    }
    
}

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector <string> res ;
        vector <int> arr ;
        
        for ( int i = 0 ; i < N ; i++ )
            arr.push_back(a[i]) ;
        possibleUtil ( arr , res ) ;
        
        return res ;
    }
};

int main ()
{
    int T ;
    cin >> T ;

    while ( T-- )
    {
        int n ;
        cin >> n ;

        int a[n] ;
        
        for ( int i = 0 ; i < n ; i++ )
            cin >> a[i] ;
        
        Solution obj ;

        vector <string> res = obj.possibleWords(a,n) ;

        for ( string i : res )
            cout << i << " " ;
        cout << endl ;
    }

    return 0 ;
}