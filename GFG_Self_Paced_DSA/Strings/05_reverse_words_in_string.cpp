# include <bits/stdc++.h>
using namespace std ;

void reverse(char str[],int low, int high) //? Custom reverse function
{
    while(low<=high){
        swap(str[low],str[high]);
        low++;
        high--;
    }
}

//? The main reversing function
void reverseWords(char str[],int n)
{
    int start=0;
    for(int end=0;end<n;end++){
        if(str[end]==' '){
            reverse(str,start,end-1);   //* Reverse characters, after the last ' ' space
            start=end+1;
        }
    }
    reverse(str,start,n-1);
    reverse(str,0,n-1);
}