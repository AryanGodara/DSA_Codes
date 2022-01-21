#include <bits/stdc++.h>

using namespace std;

// function to count subarrays with
// equal number of 1's and 0's
int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
	// 'um' implemented as hash table to store
	// frequency of values obtained through
	// cumulative sum
	unordered_map<int, int> um;
	int curr_sum = 0;

	// Traverse original array and compute cumulative
	// sum and increase count by 1 for this sum
	// in 'um'. Adds '-1' when arr[i] == 0
	for (int i = 0; i < n; i++) {
		curr_sum += (arr[i] == 0) ? -1 : arr[i] ;	// 0: -1 , 1: 1 (So, sum of equal 0 and 1 == 0)
		um[curr_sum]++;
	}

	int count = 0;
	// traverse the hash table 'um'
	for (auto itr = um.begin(); itr != um.end(); itr++) {

		// If there are more than one prefix subarrays
		// with a particular sum
		if (itr->second > 1)
			count += ((itr->second * (itr->second - 1)) / 2);
	}

	// add the subarrays starting from 1st element and
	// have equal number of 1's and 0's
	if (um.find(0) != um.end())
		count += um[0];

	// required count of subarrays
	return count;
}

// Driver program to test above
int main()
{
	int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Count = " << countSubarrWithEqualZeroAndOne(arr, n);
	return 0;
}

/*
1.Consider all 0's as -1 
2.Create a hash table that holds the count of each sum[i] value, where 
  sum[i]=sum(arr[0]+...+arr[i]) , for i = 0 to n-1
3.Now start calculating cumulative sum and then we get increment count by 1
  for that sum represented as index in the hash table. Sub-array by each pair
  of positions with same value of cumulative sum constitute a continuous range
  with equal number of 1's and 0's.
4.Now traverse the hash table and get the frequency of each element in the hash table.
  Let frequency be denoted as freq. For each freq > 1 we can choose any two pair of
  indices of sub-array by (freq*(freq-1))/2 no. of ways. Do the same for all freq and 
  sum up the result that will be the number of possible all possible sub-arrays containing
  equal number of 1's and 0's.
5.Also add freq of the sum 0 in the hash table to the final result.
*/