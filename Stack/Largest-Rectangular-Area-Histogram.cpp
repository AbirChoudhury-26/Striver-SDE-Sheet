// C++ program to find maximum rectangular area in linear time


/* Steps:
Create an empty stack.
Start from the first bar, and do the following for every bar hist[i] where ‘i‘ varies from 0 to n-1
If the stack is empty or hist[i] is higher than the bar at top of the stack, then push ‘i‘ to stack. 
If this bar is smaller than the top of the stack, then keep removing the top of the stack while the top of the stack is greater. 
Let the removed bar be hist[tp]. Calculate the area of the rectangle with hist[tp] as the smallest bar. 
For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i‘ (current index).

*/
#include <bits/stdc++.h> 
using namespace std; 

int getMaxArea(int hist[], int n) 
{ 
	// Create an empty stack. The stack holds indexes 
	// of hist[] array. The bars stored in stack are 
	// always in increasing order of their heights. 
	stack<int> s; 

	int max_area = 0; // Initialize max area 
	int tp; // To store top of stack 
	int area_with_top; // To store area with top bar 
					// as the smallest bar 

	// Run through all bars of given histogram 
	int i = 0; 
	while (i < n) { 
		// If this bar is higher than the bar on top 
		// stack, push it to stack 
		if (s.empty() || hist[s.top()] <= hist[i]) 
			s.push(i++); 

		// If this bar is lower than top of stack, 
		// then calculate area of rectangle with stack 
		// top as the smallest (or minimum height) bar. 
		// 'i' is 'right index' for the top and element 
		// before top in stack is 'left index' 
		else { 
			tp = s.top(); // store the top index 
			s.pop(); // pop the top 

			// Calculate the area with hist[tp] stack 
			// as smallest bar 
			area_with_top 
				= hist[tp] 
				* (s.empty() ? i : i - s.top() - 1); 

			// update max area, if needed 
			if (max_area < area_with_top) 
				max_area = area_with_top; 
		} 
	} 

	// Now pop the remaining bars from stack and calculate 
	// area with every popped bar as the smallest bar 
	while (s.empty() == false) { 
		tp = s.top(); 
		s.pop(); 
		area_with_top 
			= hist[tp] * (s.empty() ? i : i - s.top() - 1); 

		if (max_area < area_with_top) 
			max_area = area_with_top; 
	} 

	return max_area; 
} 

// Driver code 
int main() 
{ 
	int hist[] = { 6, 2, 5, 4, 5, 1, 6 }; 
	int n = sizeof(hist) / sizeof(hist[0]); 

	// Function call 
	cout << "Maximum area is " << getMaxArea(hist, n); 
	return 0; 
}


// Using  next and the previous smaller element:

/* Steps:

First, we will take two arrays left_smaller[] and right_smaller[] and initialize them with -1 and n respectively
For every element, we will store the index of the previous smaller and next smaller element in left_smaller[] and right_smaller[] arrays respectively
Now for every element, we will calculate the area by taking this ith element as the smallest in the range left_smaller[i] and right_smaller[i] and multiplying it with the difference of left_smaller[i] and right_smaller[i]
We can find the maximum of all the areas calculated in step 3 to get the desired maximum area

*/