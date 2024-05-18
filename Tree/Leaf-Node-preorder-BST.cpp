/* Simple Approach(Recursion based):

The idea is to use two min and max variables and taking i (index in input array), the index for given preorder array, and recursively creating root node and correspondingly checking if left and right are existing or not. 
This method returns boolean variable, and if both left and right are false it simply means that left and right are null hence it must be a leaf node so print it right there and return back true as root at that index existed.
*/

#include<bits/stdc++.h>
using namespace std;


bool isLeaf(int pre[], int &i, int n,int min, int max)
{ 
	if (i >= n) 
		return false;
	
	if (pre[i] > min && pre[i] < max) {
		i++;
		
		bool left = isLeaf(pre, i, n, min, pre[i-1]);
		bool right = isLeaf(pre, i, n, pre[i-1], max);
		
		if (!left && !right) 
			cout << pre[i-1] << " ";
			
		return true;
	}
	return false;
}

void printLeaves(int preorder[], int n)
{
	int i = 0; 
	isLeaf(preorder, i, n, INT_MIN, INT_MAX);
}

// Driver code
int main()
{
	int preorder[] = { 890, 325, 290, 530, 965 };
	int n = sizeof(preorder)/sizeof(preorder[0]);
	printLeaves(preorder, n); 
	return 0;
}
