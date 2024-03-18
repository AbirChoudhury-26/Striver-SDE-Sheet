// // C++ program to print largest contiguous array sum
// #include <bits/stdc++.h>
// using namespace std;

// int maxSubArraySum(int a[], int size)
// {
// 	int max_so_far = INT_MIN, max_ending_here = 0;

// 	for (int i = 0; i < size; i++) {
// 		max_ending_here = max_ending_here + a[i];
// 		if (max_so_far < max_ending_here)
// 			max_so_far = max_ending_here;

// 		if (max_ending_here < 0)
// 			max_ending_here = 0;
// 	}
// 	return max_so_far;
// }

// // Driver Code
// int main()
// {
// 	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
// 	int n = sizeof(a) / sizeof(a[0]);

// 	// Function Call
// 	int max_sum = maxSubArraySum(a, n);
// 	cout << "Maximum contiguous sum is " << max_sum;
// 	return 0;
// }


// Steps:

/*
Initialize the variables max_so_far = INT_MIN and max_ending_here = 0
Run a for loop from 0 to N-1 and for each index i: 
Add the arr[i] to max_ending_here.
If  max_so_far is less than max_ending_here then update max_so_far  to max_ending_here.
If max_ending_here < 0 then update max_ending_here = 0
Return max_so_far
*/



// C++ program to print largest contiguous array sum

#include <climits>
#include <iostream>
using namespace std;

void maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0,
		start = 0, end = 0, s = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here += a[i];

		if (max_so_far < max_ending_here) {
			max_so_far = max_ending_here;
			start = s;
			end = i;
		}

		if (max_ending_here < 0) {
			max_ending_here = 0;
			s = i + 1;
		}
	}
	cout << "Maximum contiguous sum is " << max_so_far
		<< endl;
	cout << "Starting index " << start << endl
		<< "Ending index " << end << endl;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);
	maxSubArraySum(a, n);
	return 0;
}
