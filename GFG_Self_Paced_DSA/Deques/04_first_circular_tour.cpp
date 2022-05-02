//? Consider an arrangement where n petrol pumps are arranged in a circular manner. We need to
//? find hte first petrol pump from where we can visit all petrol pumps and come back to the
//? petrol pump without ever going out of petrol

# include <bits/stdc++.h>
using namespace std ;

//* A petrol pump has petrol, and distance to next petrol pump
class petrolPump {
    public:
        int petrol, distance ;
};

//TODO: The function returns starting point if there's a possible solution, else, it returns -1
int printTour ( petrolPump arr[] , int n )
{
    int start = 0 , end = 1 ;

    int cur_petrol = arr[start].petrol - arr[start].distance ;  // Leftover petrol after trip

    //TODO: Run a loop while all petrol pumps aren't visited. And we have reached the first
    //TODO: petrol pump again with 0 or more petrol

    while ( end != start || cur_petrol < 0 )
    {
        // If current petrol amount of petrol in truck becomes less than 0, then remove the
        // starting petrol pump from tour
        
        while ( cur_petrol < 0 && start != end )
        {
            // Remove starting petrol pump. Change Start
            cur_petrol -= arr[start].petrol - arr[start].distance ;
            start = (start+1) % n ;

            // If 0 is being considered as start again, then there is no possible solution
            if ( start == 0 )
                return -1 ;
        }

        cur_petrol += arr[end].petrol - arr[end].distance ;

        end = (end+1) % n ;

    }

    // Return the Starting Point
    return start ;
}

int main ()
{
    petrolPump arr[] = { {6,4} , {3,6} , {7,3} } ;

    int n = sizeof(arr)/sizeof(arr[0]) ;
    int start = printTour(arr,n) ;

    ( start == -1 ) ? cout << "No Solution\n" : cout << "Start = " << start << endl ;

    return 0 ;
}