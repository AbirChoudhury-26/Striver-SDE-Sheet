
/*
Steps:

Find all smaller element on left side
     1. Create a new empty stack S and an array LS[]
     2. For every element 'arr[i]' in the input arr[],
          where 'i' goes from 0 to n-1.
        a) while S is nonempty and the top element of 
           S is greater than or equal to 'arr[i]':
           pop S
    
        b) if S is empty:
           'arr[i]' has no preceding smaller value 
            LS[i] = 0 
            
        c) else:
            the nearest smaller value to 'arr[i]' is top
            of stack
              LS[i] = s.top()

        d) push 'arr[i]' onto S   

Find all smaller element on right side
     3. First reverse array arr[]. After reversing the array, 
        right smaller become left smaller.
     4. Create an array RRS[] and repeat steps  1 and 2 to 
        fill RRS (in-place of LS).
         
5. Initialize result as -1 and do following for every element
   arr[i]. In the reversed array right smaller for arr[i] is
   stored at RRS[n-i-1]
      return result = max(result, LS[i]-RRS[n-i-1])
*/
#include<bits/stdc++.h> 
using namespace std; 

// Function to fill left smaller element for every 
// element of arr[0..n-1]. These values are filled 
// in s[0..n-1] 
void leftSmaller(int arr[], int n, int s[]) 
{ 
	// Create an empty stack 
	stack<int>S; 

	// Traverse all array elements 
	// compute nearest smaller elements of every element 
	for (int i=0; i<n; i++) 
	{ 
		// Keep removing top element from S while the top 
		// element is greater than or equal to arr[i] 
		while (!S.empty() && S.top() >= arr[i]) 
			S.pop(); 

		// Store the smaller element of current element 
		if (!S.empty()) 
			s[i] = S.top(); 

		// If all elements in S were greater than arr[i] 
		else
			s[i] = 0; 

		// Push this element 
		S.push(arr[i]); 
	} 
} 

// Function returns maximum difference b/w Left & 
// right smaller element 
int findMaxDiff(int arr[], int n) 
{ 
	int LS[n]; // To store left smaller elements 

	// find left smaller element of every element 
	leftSmaller(arr, n, LS); 

	// find right smaller element of every element 
	// first reverse the array and do the same process 
	int RRS[n]; // To store right smaller elements in 
				// reverse array 
	reverse(arr, arr + n); 
	leftSmaller(arr, n, RRS); 

	// find maximum absolute difference b/w LS & RRS 
	// In the reversed array right smaller for arr[i] is 
	// stored at RRS[n-i-1] 
	int result = -1; 
	for (int i=0 ; i< n ; i++) 
		result = max(result, abs(LS[i] - RRS[n-1-i])); 

	// return maximum difference b/w LS & RRS 
	return result; 
} 

// Driver program 
int main() 
{ 
	int arr[] = {2, 4, 8, 7, 7, 9, 3}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Maximum diff : "
		<< findMaxDiff(arr, n) << endl; 
	return 0; 
} 
