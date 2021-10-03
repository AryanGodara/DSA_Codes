# include <bits/stdc++.h>
using namespace std ;

vector<int> searchRange(vector<int>& nums, int target) {
    int idx1 = lower_bound(nums, target);
    int idx2 = lower_bound(nums, target+1)-1;   // Find the first occurence of the element just greater than target, or the lower bound, which will give the first position of the number just greater than target, and subtract 1 from it to find the index of the last element of target.
    if (idx1 < nums.size() && nums[idx1] == target)
        return {idx1, idx2};
    else
        return {-1, -1};
}

int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r) {
        int mid = (r-l)/2+l;
        if (nums[mid] < target)
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}

int main ()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;

    // Find the first and last occurence of an element in a sorted array
    vector <int>  nums = {1,1,2,4,5,5,5,6,7,7,8,99,100} ;
    int target = 5 ;
    vector <int> arr = searchRange(nums,target) ;

    for ( auto &x : arr )
        cout << x << " " ;
    cout << endl ;

    return 0 ;
}