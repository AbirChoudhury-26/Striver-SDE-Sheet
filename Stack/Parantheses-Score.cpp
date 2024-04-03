// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the score
// of the parentheses using stack
void scoreOfParentheses(string s)
{
	// To keep track of the score
	stack<int> stack;

	// Initially, push 0 to stack
	stack.push(0);

	// Traverse the string s
	for (char c : s) {

		// If '(' is encountered,
		// then push 0 to stack
		if (c == '(')
			stack.push(0);

		// Otherwise
		else {

			// Balance the last '(', and store
			// the score of inner parentheses
			int tmp = stack.top();
			stack.pop();

			int val = 0;

			// If tmp is not zero, it means
			// inner parentheses exists
			if (tmp > 0)
				val = tmp * 2;

			// Otherwise, it means no
			// inner parentheses exists
			else
				val = 1;

			// Pass the score of this level
			// to parent parentheses
			stack.top() += val;
		}
	}

	// Print the score
	cout << stack.top();
}

// Driver Code
int main()
{
	string S = "(()(()))";
	scoreOfParentheses(S);

	return 0;
}
