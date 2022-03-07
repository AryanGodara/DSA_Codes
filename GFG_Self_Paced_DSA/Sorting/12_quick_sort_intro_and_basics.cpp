/*
* Divide and Conquer Algorithm
* 
* O(N^2)
* Despite this, it's considered to be faster than mergesort, because of the following :-
* 1. In-place sorting algo
* 2. Cache-friendly
* 3. Average case is O(NlogN)
* 4. Tail Recursive
* 
* Parition is the key function (naive, lomuto, or hoare) (stable, not stable, not stable)
*/

/*
* But since lomuto always selects the last element, and hoare always selects the first element
* they both will lead to worst case if the array is already sorted.
* So, to avoid this worst input case, we choose a "random" element of the array to be a pivot
* Therefore, let pivot = arr[k] where k belongs to [l,h].
* 
* Now, for lomuto swap(arr[k],arr[h])
* And, for hoare swap(arr[k],arr[l])
* 
* Then, we can continue like earlier, with no more changes required in the code
*/

/*
* The space complexity of quicksort can be calculated according to the maximum worst case
* height of the recursion tree, which happens to give us : O(N)
* 
* The worst case time complexity of quicksort is O(N^2), which happens when in each recursive
* call, the pivot element (after partiion) ends up being the first or the last element, so
* we have to call recursive quicksort for O(1) + O(N-1).
* 
* The best case time complexity is when the pivot in each recursive case, turns out to be the
* median of the partitioned array, and in that case T(N) = T(N/2) + T(N/2). And thus,
* Time complexity = O(NlogN)
*/