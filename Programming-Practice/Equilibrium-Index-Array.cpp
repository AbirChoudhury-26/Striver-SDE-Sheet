/* The equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes. */

//  Method-1

// Naive Approach: 

/*Steps to solve the problem:

1. iterate through i=1 to n:

      *declare a leftsum variable to zero.

      *iterate through 0 till i and add arr[i] to leftsum.

      *declare a rightsum variable to zero.

      *iterate through i+1 till n and add arr[i] to rightsum.

      *check if leftsum is equal to rightsum than return arr[i].

2. return -1 in case of no point.*/

// C++ program to find equilibrium
// index of an array
// #include <bits/stdc++.h>
// using namespace std;

// int equilibrium(int arr[], int n)
// {
// 	int i, j;
// 	int leftsum, rightsum;

// 	/* Check for indexes one by one until
// 	an equilibrium index is found */
// 	for (i = 0; i < n; ++i) {

// 		/* get left sum */
// 		leftsum = 0;
// 		for (j = 0; j < i; j++)
// 			leftsum += arr[j];

// 		/* get right sum */
// 		rightsum = 0;
// 		for (j = i + 1; j < n; j++)
// 			rightsum += arr[j];

// 		/* if leftsum and rightsum
// 		are same, then we are done */
// 		if (leftsum == rightsum)
// 			return i;
// 	}

// 	/* return -1 if no equilibrium
// 	index is found */
// 	return -1;
// }

// // Driver code
// int main()
// {
// 	int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
// 	int arr_size = sizeof(arr) / sizeof(arr[0]);

// 	// Function call
// 	cout << equilibrium(arr, arr_size);
// 	return 0;
// }



// Method-2

// Using Array Sum Property


// C++ program to find equilibrium
// index of an array
#include <bits/stdc++.h>
using namespace std;

int equilibrium(int arr[], int n)
{
	int sum = 0; // initialize sum of whole array
	int leftsum = 0; // initialize leftsum

	/* Find sum of the whole array */
	for (int i = 0; i < n; ++i)
		sum += arr[i];

	for (int i = 0; i < n; ++i) {
		sum -= arr[i]; // sum is now right sum for index i

		if (leftsum == sum)
			return i;

		leftsum += arr[i];
	}

	/* If no equilibrium index found, then return 0 */
	return -1;
}

// Driver code
int main()
{
	int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "First equilibrium index is "
		<< equilibrium(arr, arr_size);
	return 0;
}


