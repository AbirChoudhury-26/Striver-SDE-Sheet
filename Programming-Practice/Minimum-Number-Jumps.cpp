// // C++ program to find Minimum 
// // number of jumps to reach end 
// #include <bits/stdc++.h> 
// using namespace std; 

// // Function to return the minimum number 
// // of jumps to reach arr[h] from arr[l] 
// int minJumps(int arr[], int l,int h) 
// { 

// 	// Base case: when source and destination are same 
// 	if (h == l) 
// 		return 0; 

// 	// When nothing is reachable from the given source 
// 	if (arr[l] == 0) 
// 		return INT_MAX; 

// 	// Traverse through all the points 
// 	// reachable from arr[l] 
// 	// Recursively, get the minimum number 
// 	// of jumps needed to reach arr[h] from 
// 	// these reachable points 
// 	int min = INT_MAX; 
// 	for (int i = l + 1; i <= h && i <= l + arr[l]; i++) { 
// 		int jumps = minJumps(arr, i, h); 
// 		if (jumps != INT_MAX && jumps + 1 < min) 
// 			min = jumps + 1; 
// 	} 

// 	return min; 
// } 

// // Driver Code 
// int main() 
// { 
// 	int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 }; 
// 	int n = sizeof(arr) / sizeof(arr[0]); 
// 	cout << "Minimum number of jumps to"; 
// 	cout << " reach the end is " << minJumps(arr, 0,n-1); 
// 	return 0; 
// } 

 

// Method-2

// Using Memoization

#include <bits/stdc++.h> 
using namespace std; 

int jump(vector<int>& nums, int idx, int end, vector<int>& memo) { 
		
		//we reached the end. No jumps to make further 
		if (idx == end) 
			return 0; 
		
		if (memo[idx] != -1) 
			return memo[idx]; 
		
		int min_jumps = INT_MAX - 1; 
		
		//we will try to make all possible jumps from current index 
		//and select the minimum of those 
		//It does not matter if we try from 1 to nums[idx] 
		//or from nums[idx] to 1 
		for (int j = nums[idx]; j >= 1; --j) { 
			
			//If we make this jump 'j' distance away from idx 
			//do we overshoot? 
			//if we land within the nums, we will test further 
			if (idx + j <= end) { 
				
				//Make a jump to idx + j index and explore further 
				//then update min_jumps with the minimum jumps 
				//we made to reach end while trying all possible 
				//nums[idx] jumps from current index. 
				min_jumps = std::min(min_jumps, 1 + jump(nums, idx + j, end, memo)); 
			} 
		} 
		
		return memo[idx] = min_jumps; 
	} 
	
	//Memoization 
	int minJumps(vector<int>& nums) { 
		vector<int> memo(nums.size(), -1); 
		return jump(nums, 0, nums.size() - 1, memo); 
	} 


int main() 
{ 
	int n = 11; 
	vector<int> arr{ 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 }; 
	cout << minJumps(arr) << endl; 

	return 0; 
} 



