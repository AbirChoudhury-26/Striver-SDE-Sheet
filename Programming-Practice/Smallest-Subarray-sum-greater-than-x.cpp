# include <iostream>
using namespace std;

// Returns length of smallest subarray with sum greater than x.
// If there is no subarray with given sum, then returns n+1
int smallestSubWithSum(int arr[], int n, int x)
{
	// Initialize length of smallest subarray as n+1
	int min_len = n + 1;

	// Pick every element as starting point
	for (int start=0; start<n; start++)
	{
		// Initialize sum starting with current start
		int curr_sum = arr[start];

		// If first element itself is greater
		if (curr_sum > x) return 1;

		// Try different ending points for current start
		for (int end=start+1; end<n; end++)
		{
			// add last element to current sum
			curr_sum += arr[end];

			// If sum becomes more than x and length of
			// this subarray is smaller than current smallest
			// length, update the smallest length (or result)
			if (curr_sum > x && (end - start + 1) < min_len)
				min_len = (end - start + 1);
		}
	}
	return min_len;
}

/* Driver program to test above function */
int main()
{
	int arr1[] = {1, 4, 45, 6, 10, 19};
	int x = 51;
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	int res1 = smallestSubWithSum(arr1, n1, x);
	(res1 == n1+1)? cout << "Not possible\n" :
					cout << res1 << endl;

	int arr2[] = {1, 10, 5, 2, 7};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	x = 9;
	int res2 = smallestSubWithSum(arr2, n2, x);
	(res2 == n2+1)? cout << "Not possible\n" :
					cout << res2 << endl;

	int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
	int n3 = sizeof(arr3)/sizeof(arr3[0]);
	x = 280;
	int res3 = smallestSubWithSum(arr3, n3, x);
	(res3 == n3+1)? cout << "Not possible\n" :
					cout << res3 << endl;

	return 0;
}

// Binary Search Method

// O(n log(n) solution for finding smallest subarray with
// sum greater than x
#include <bits/stdc++.h>
using namespace std;

int smallestSubArrayLen(int target, vector<int>& nums)
{
	// Get the length of the input vector
	int n = nums.size();
	// If the vector is empty, return 0
	if (n == 0)
		return 0;
	// Initialize the minimum subarray length to INT_MAX-1
	int ans = INT_MAX - 1;
	// Create a new vector "sums" with size n+1, initialized
	// to all zeros
	vector<int> sums(n + 1, 0);
	// Compute the running sum of nums and store it in
	// "sums"
	for (int i = 1; i <= n; i++)
		sums[i] = sums[i - 1] + nums[i - 1];
	// Iterate through each starting index i
	for (int i = 1; i <= n; i++) {
		// Calculate the target sum for the subarray
		// starting at index i
		int to_find = target + sums[i - 1];
		// Find the first element in "sums" that is >=
		// to_find
		auto bound = lower_bound(sums.begin(), sums.end(),
								to_find);
		// If such an element is found and it is not equal
		// to to_find itself
		if (bound != sums.end() && *bound != to_find) {
			// Compute the length of the subarray and update
			// ans if necessary
			int len = bound - (sums.begin() + i - 1);
			ans = min(ans, len);
		}
	}
	// Return ans if it was updated, otherwise return 0
	return (ans != INT_MAX - 1) ? ans : 0;
}


int main()
{
	vector<int> arr1 = { 1, 4, 45, 6, 10, 19 };
	int target1 = 51;
	cout << "Length of Smallest Subarray :"
		<< smallestSubArrayLen(target1, arr1) << endl;

	vector<int> arr2 = { 1, 10, 5, 2, 7 };
	int target2 = 9;
	cout << "Length of Smallest Subarray :"
		<< smallestSubArrayLen(target2, arr2) << endl;

	vector<int> arr3 = { 1, 1, 1, 1, 1, 1, 1, 1 };
	int target3 = 11;
	cout << "Length of Smallest Subarray :"
		<< smallestSubArrayLen(target3, arr3) << endl;

	vector<int> arr4
		= { 1, 11, 100, 1, 0, 200, 3, 2, 1, 250 };
	int target4 = 280;
	cout << "Length of Smallest Subarray :"
		<< smallestSubArrayLen(target4, arr4) << endl;

	return 0;
}

