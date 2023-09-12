// C program to check if an
// Array is sorted or not

#include <stdio.h>

// Function that returns true if array is
// sorted in non-decreasing order.
int arraySortedOrNot(int arr[], int n)
{
	// Array has one or no element
	if (n == 0 || n == 1)
		return 1;

	for (int i = 1; i < n; i++) {
		// Unsorted pair found
		if (arr[i - 1] > arr[i])
			return 0;
	}

	// No unsorted pair found
	return 1;
}

// Driver code
int main()
{
	int arr[] = { 20, 23, 23, 45, 78, 88 };
	int n = sizeof(arr) / sizeof(arr[0]);

	if (arraySortedOrNot(arr, n))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
