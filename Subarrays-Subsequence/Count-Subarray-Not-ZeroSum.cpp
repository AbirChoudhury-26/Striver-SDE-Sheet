// C++ program to Count the no of subarray
// which do not contain any subarray
// whose sum of elements is equal to zero
#include <bits/stdc++.h>
using namespace std;

// Function that print the number of
// subarrays which do not contain any subarray
// whose elements sum is equal to 0
void numberOfSubarrays(int arr[], int N)
{
	//To store final answer
	int count=0;
	
//Find all subarray
for(int i=0;i<N;i++){
	for(int j=i;j<N;j++){
		
		//Boolean variable to tell whether its any subarray
		//have sum is equal to zero or not
		bool val=true;
		
		//Find all subarray of this subarray
		for(int m=i;m<=j;m++){
			//To store sum of all elements of subarray
			int sum=0;
			for(int n=m;n<=j;n++){
				sum+=arr[n];
				if(sum==0){
					val=false;
					break;
				}
			}
			
			if(val==false){break;}
		}
		if(val==true){count++;}
	} 
}
//Print final answer
cout<<count<<endl;
}

// Driver Code
int main()
{
	int arr[] = { 2, 4, -6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	numberOfSubarrays(arr, size);
	return 0;
}
