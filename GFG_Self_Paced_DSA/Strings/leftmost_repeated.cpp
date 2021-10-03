// Leftmost repeating element
# include <bits/stdc++.h>
using namespace std ;

int leftrep ( const string &str , int n )
{
	vector<int> findex(256,-1) ;

	int res = INT_MAX ;

	for ( int i = 0 ; i  < n ; i++ )
	{
		int fi = findex[str[i]] ;

		if ( fi == -1 )
			findex[str[i]] = i ;	// Store the first occurence
		else
			res = min(res,fi) ;
		// If it's the repeat occurence the make it the result
		// But in case we find an even lower index, we use the min 
		// function to return the correct answer
	}
	return (res == INT_MAX ) ? -1 : res ;
}

// Better solution, we traverse from the right side
int betterleftrep ( const string &str , int n )
{
    int res = -1 ;

    vector <bool> visited (256,false) ;
    // Stores all the ASCII values

    for ( int i = n-1 ; i >=0 ; i-- )
    {
        if ( visited[str[i]] )  // Repeated char now
            res = i ;
        // Since this is the current leftmost element,
        // we don't have to worry about using a min or a max
        // function, since this is the current answer upto now.
        else
            visited[str[i]] = true ;
    }
    return res ;
    
}

int main ()
{
	string str = "abccb" ;
	cout << leftrep(str,5) << endl ;
	cout << betterleftrep(str,5) << endl ;

	return 0 ;
}