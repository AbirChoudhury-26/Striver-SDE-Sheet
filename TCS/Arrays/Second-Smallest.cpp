// C++ program to find smallest and
// second smallest element in array
#include <bits/stdc++.h>
using namespace std;




int main()
{
	int arr[] = {12, 13, 1, 10, 34, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	int smallest = INT_MAX;
	// traversing the array to find
	// smallest element.
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
		}
	}
	cout << "smallest element is: " << smallest << endl;

	int second_smallest = INT_MAX;

	// traversing the array to find second smallest element
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < second_smallest && arr[i] > smallest)
		{
			second_smallest = arr[i];
		}
	}
	cout << "second smallest element is: " << second_smallest << endl;
	return 0;
}





