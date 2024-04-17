/* Steps:

Create an array of pairs arrPos to store the input array elements along with their index
Sort arrPos and run a loop for i [0, N]
If the current element is already visited or it is at its correct position then continue
Else calculate the cycle size from the current element using a while loop
Declare an integer j equal to i and in the while loop set j equal to the index of arrPos[j] and increase cycle size while the element at jth position is not visited
Increase the answer by the size of the current cycle – 1

*/

#include <bits/stdc++.h> 
using namespace std; 

// Function returns the 
// minimum number of swaps 
// required to sort the array 
int minSwaps(int arr[], int n) 
{ 
	// Create an array of 
	// pairs where first 
	// element is array element 
	// and second element 
	// is position of first element 
	pair<int, int> arrPos[n]; 
	for (int i = 0; i < n; i++) { 
		arrPos[i].first = arr[i]; 
		arrPos[i].second = i; 
	} 

	// Sort the array by array 
	// element values to 
	// get right position of 
	// every element as second 
	// element of pair. 
	sort(arrPos, arrPos + n); 

	// To keep track of visited elements. 
	// Initialize 
	// all elements as not visited or false. 
	vector<bool> vis(n, false); 

	// Initialize result 
	int ans = 0; 

	// Traverse array elements 
	for (int i = 0; i < n; i++) { 
		// already swapped and corrected or 
		// already present at correct pos 
		if (vis[i] || arrPos[i].second == i) 
			continue; 

		// find out the number of node in 
		// this cycle and add in ans 
		int cycle_size = 0; 
		int j = i; 
		while (!vis[j]) { 
			vis[j] = 1; 

			// move to next node 
			j = arrPos[j].second; 
			cycle_size++; 
		} 

		// Update answer by adding current cycle. 
		if (cycle_size > 0) { 
			ans += (cycle_size - 1); 
		} 
	} 

	// Return result 
	return ans; 
} 

int main() 
{ 
	int arr[] = { 1, 5, 4, 3, 2 }; 
	int n = (sizeof(arr) / sizeof(int)); 
	cout << minSwaps(arr, n); 
	return 0; 
}


/* Greedy Approach */

/* Steps:

Create a new array and copy the elements of the input array
Sort the new array and declare a variable ans equal to 0
Run a for loop to traverse the elements
If the current element in the sorted array is not equal to the one in the input array then increase the ans by 1
And swap the current element, with the required element at this index
Return ans 

*/

#include <bits/stdc++.h> 
using namespace std; 

void swap(vector<int>& arr, int i, int j) 
{ 
	int temp = arr[i]; 
	arr[i] = arr[j]; 
	arr[j] = temp; 
} 

int indexOf(vector<int>& arr, int ele) 
{ 
	for (int i = 0; i < arr.size(); i++) { 
		if (arr[i] == ele) { 
			return i; 
		} 
	} 
	return -1; 
} 

// Return the minimum number 
// of swaps required to sort the array 
int minSwaps(vector<int> arr, int N) 
{ 
	int ans = 0; 
	vector<int> temp(arr.begin(), arr.end()); 
	sort(temp.begin(), temp.end()); 

	for (int i = 0; i < N; i++) { 

		// This is checking whether 
		// the current element is 
		// at the right place or not 
		if (arr[i] != temp[i]) { 
			ans++; 

			// Swap the current element 
			// with the right index 
			// so that arr[0] to arr[i] is sorted 
			swap(arr, i, indexOf(arr, temp[i])); 
		} 
	} 
	return ans; 
} 

int main() 
{ 

	vector<int> a 
		= { 101, 758, 315, 730, 472, 619, 460, 479 }; 

	int n = a.size(); 

	// Output will be 5 
	cout << minSwaps(a, n); 
} 


