//  Naive Approach


// #include <bits/stdc++.h>
// using namespace std;

// void printMaxOfMin(int arr[], int n)
// {
// 	// Consider all windows of different
// 	// sizes starting from size 1
// 	for (int k = 1; k <= n; k++) {
// 		// Initialize max of min for
// 		// current window size k
// 		int maxOfMin = INT_MIN;

// 		// Traverse through all windows
// 		// of current size k
// 		for (int i = 0; i <= n - k; i++) {
// 			// Find minimum of current window
// 			int min = arr[i];
// 			for (int j = 1; j < k; j++) {
// 				if (arr[i + j] < min)
// 					min = arr[i + j];
// 			}

// 			// Update maxOfMin if required
// 			if (min > maxOfMin)
// 				maxOfMin = min;
// 		}

// 		// Print max of min for current
// 		// window size
// 		cout << maxOfMin << " ";
// 	}
// }

// // Driver program
// int main()
// {
// 	int arr[] = { 10, 20, 30, 50, 10, 70, 30 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	printMaxOfMin(arr, n);
// 	return 0;
// }


// Using Stack

/*
Steps to follow:

Initialize a stack s.
Create two arrays, left and right of size N + 1 to store the next smaller and the previous smaller elements.
Traverse a loop on i from 0 till N
Assign left[i] = -1 and right[i] = N
Traverse a loop on i from 0 till N
Pop the elements from s while the current element is not greater than the element at top of stack s.
If the stack is not empty
Update left[i] = s.top()
Push current index in stack s
Empty the stack s.
Traverse a loop on i from N – 1 till 0
Pop the elements from s while the current element is not greater than the element at top of stack s.
If the stack is not empty
Update right[i] = s.top()
Push current index in stack s
Initialize an array ans of size N + 1 with 0.
Traverse a loop on i from 0 till N
Initialize len = left[i] – right[i] + 1
Update ans[len] = max(ans[len], arr[i])
Traverse a loop on i from N – 1 till 0
Update ans[i] = max(ans[i], ans[i + 1])
Print ans array. 
*/

// An efficient C++ program to find
// maximum of all minimums of
// windows of different sizes
#include <iostream>
#include <stack>
using namespace std;

void printMaxOfMin(int arr[], int n)
{
	// Used to find previous and next smaller
	stack<int> s;

	// Arrays to store previous and next smaller
	int left[n + 1];
	int right[n + 1];

	// Initialize elements of left[] and right[]
	for (int i = 0; i < n; i++) {
		left[i] = -1;
		right[i] = n;
	}

	// Fill elements of left[] using logic discussed on

	for (int i = 0; i < n; i++) {
		while (!s.empty() && arr[s.top()] >= arr[i])
			s.pop();

		if (!s.empty())
			left[i] = s.top();

		s.push(i);
	}

	// Empty the stack as stack is
	// going to be used for right[]
	while (!s.empty())
		s.pop();

	// Fill elements of right[] using same logic
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && arr[s.top()] >= arr[i])
			s.pop();

		if (!s.empty())
			right[i] = s.top();

		s.push(i);
	}

	// Create and initialize answer array
	int ans[n + 1];
	for (int i = 0; i <= n; i++)
		ans[i] = 0;

	// Fill answer array by comparing minimums of all
	// lengths computed using left[] and right[]
	for (int i = 0; i < n; i++) {
		// length of the interval
		int len = right[i] - left[i] - 1;

		// arr[i] is a possible answer for this length
		// 'len' interval, check if arr[i] is more than
		// max for 'len'
		ans[len] = max(ans[len], arr[i]);
	}

	// Some entries in ans[] may not be filled yet. Fill
	// them by taking values from right side of ans[]
	for (int i = n - 1; i >= 1; i--)
		ans[i] = max(ans[i], ans[i + 1]);

	// Print the result
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
}

// Driver program
int main()
{
	int arr[] = { 10, 20, 30, 50, 10, 70, 30 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printMaxOfMin(arr, n);
	return 0;
}
