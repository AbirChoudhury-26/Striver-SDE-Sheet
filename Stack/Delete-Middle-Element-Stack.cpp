// // C++ code to delete middle of a stack
// // without using additional data structure.
// #include<bits/stdc++.h>
// using namespace std;

// // Deletes middle of stack of size
// // n. Curr is current item number
// 	void deleteMid_util(stack<char>&s, int sizeOfStack, int current)
// 	{
// 		//if current pointer is half of the size of stack then we 
// 		//are accessing the middle element of stack.
// 		if(current==sizeOfStack/2)
// 		{
// 			s.pop();
// 			return;
// 		}
		
// 		//storing the top element in a variable and popping it.
// 		int x = s.top();
// 		s.pop();
// 		current+=1;

// 		//calling the function recursively.
// 		deleteMid_util(s,sizeOfStack,current);
		
// 		//pushing the elements (except middle element) back 
// 		//into stack after recursion calls.
// 		s.push(x);
// 	}
// 	void deleteMid(stack<char>&s, int sizeOfStack)
// 	{
// 		deleteMid_util(s,sizeOfStack,0);
// 	}

// //Driver function to test above functions
// int main()
// {
// 	stack<char> st;

// 	//push elements into the stack
// 	st.push('1');
// 	st.push('2');
// 	st.push('3');
// 	st.push('4');
// 	st.push('5');
// 	st.push('6');
// 	st.push('7');

// 	deleteMid(st, st.size());

// 	// Printing stack after deletion
// 	// of middle.
// 	while (!st.empty())
// 	{
// 		char p=st.top();
// 		st.pop();
// 		cout << p << " ";
// 	}
// 	return 0;
// }


// C++ code to delete middle of a stack
// without using additional data structure.
// #include<bits/stdc++.h>
// using namespace std;

// // Deletes middle of stack of size
// // n. Curr is current item number
// 	void deleteMid_util(stack<char>&s, int sizeOfStack, int current)
// 	{
// 		//if current pointer is half of the size of stack then we 
// 		//are accessing the middle element of stack.
// 		if(current==sizeOfStack/2)
// 		{
// 			s.pop();
// 			return;
// 		}
		
// 		//storing the top element in a variable and popping it.
// 		int x = s.top();
// 		s.pop();
// 		current+=1;

// 		//calling the function recursively.
// 		deleteMid_util(s,sizeOfStack,current);
		
// 		//pushing the elements (except middle element) back 
// 		//into stack after recursion calls.
// 		s.push(x);
// 	}
// 	void deleteMid(stack<char>&s, int sizeOfStack)
// 	{
// 		deleteMid_util(s,sizeOfStack,0);
// 	}

// //Driver function to test above functions
// int main()
// {
// 	stack<char> st;

// 	//push elements into the stack
// 	st.push('1');
// 	st.push('2');
// 	st.push('3');
// 	st.push('4');
// 	st.push('5');
// 	st.push('6');
// 	st.push('7');

// 	deleteMid(st, st.size());

// 	// Printing stack after deletion
// 	// of middle.
// 	while (!st.empty())
// 	{
// 		char p=st.top();
// 		st.pop();
// 		cout << p << " ";
// 	}
// 	return 0;
// }


// Delete using Another Stack

// Steps:

/*
Initialize an empty stack temp and a variable count with 0.
Run a while loop till count becomes equal to half the initial size of the given stack 
Pop the element of the given stack and push them in temp.
Pop the top element from the given stack.
Run a while loop till temp becomes empty. 
Push the element of temp and push them in the given stack .
*/

// C++ code to delete middle of a stack with iterative method
#include <bits/stdc++.h>
using namespace std;

// Deletes middle of stack of size n. Curr is current item number
void deleteMid(stack<char>& st)
{
	int n = st.size();
	stack<char> tempSt;
	int count = 0;
	
	// Put first n/2 element of st in tempSt
	while (count < n / 2) {
		char c = st.top();
		st.pop();
		tempSt.push(c);
		count++;
	}
	
	// Delete middle element
	st.pop();
	
	// Put all (n/2) element of tempSt in st
	while (!tempSt.empty()) {
		st.push(tempSt.top());
		tempSt.pop();
	}
}

// Driver Code
int main()
{
	stack<char> st;

	// Push elements into the stack
	st.push('1');
	st.push('2');
	st.push('3');
	st.push('4');
	st.push('5');
	st.push('6');
	st.push('7');

	deleteMid(st);

	// Printing stack after deletion of middle.
	while (!st.empty()) {
		char p = st.top();
		st.pop();
		cout << p << " ";
	}
	return 0;
}
